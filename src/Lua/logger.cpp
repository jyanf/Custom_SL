#include "logger.hpp"

#include <fstream>
//#include <ctime>
#include <list>
#include <mutex>
#include <SokuLib.hpp>

namespace {
    SokuLib::SWRFont* consoleFont = 0;
    SokuLib::Sprite consoleView;
    std::mutex consoleLock;
    std::time_t timerStart = 0;
    int logFlags = 0;
    bool isDirty = false;

    std::list<std::string> logContent;
    std::ofstream logFile;
}

static SokuLib::SWRFont* createFont() {
    SokuLib::SWRFont* font = new SokuLib::SWRFont;
    font->create();
    font->setIndirect(SokuLib::FontDescription {
        "Courier New",                      // faceName
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // color
        14, 500,                            // height, weight
        false, true, false,                 // italic, shadow, wrap
        0, 0, 0, 0, 0,                      // buffer?, padding, spacing
    });
    return font;
}

void Logger::Initialize(int flags, const std::string_view& filename) {
    logFlags = flags;
    if (!filename.empty()) logFile.open(filename.data());
}

void Logger::Finalize() {
    std::lock_guard guard(consoleLock);
    //if (consoleView.dxHandle) SokuLib::textureMgr.remove(consoleView.dxHandle);
    logContent.clear();

    if (consoleFont) {
        consoleFont->destruct();
        delete consoleFont;
        consoleFont = 0;
    }
}

void Logger::Clear() {
    std::lock_guard guard(consoleLock);
    logContent.clear();
    isDirty = true;
}

void Logger::Render() {
    if (logContent.empty()) return;

    if (consoleLock.try_lock()) {
    if (isDirty) {
        if (!consoleFont) consoleFont = createFont();
        isDirty = false;
        std::string content;
        for (auto& line : logContent) {
            content += line + "<br>";
        }

        if (consoleView.dxHandle) SokuLib::textureMgr.remove(consoleView.dxHandle);
        int texture, width, height;
        int* x = SokuLib::textureMgr.createTextTexture(&texture, content.c_str(), *consoleFont, 632, 472, &width, &height);
        consoleView.setTexture2(texture, 0, 0, width, height);
    } consoleLock.unlock(); }

    if (timerStart != 0) {
        std::time_t timerEnd; std::time(&timerEnd);
        if (std::difftime(timerEnd, timerStart) < 8.) {
            consoleView.render(4, 476 - consoleView.size.y);
        } else {
            Clear();
            timerStart = 0;
        }
    }
}

static std::string getTypeName(int type) {
    switch (type) {
        case Logger::LOG_DEBUG: return "D: ";
        case Logger::LOG_ERROR: return "E: ";
        case Logger::LOG_INFO: return ">>";
        case Logger::LOG_WARNING: return "W: ";
        default: return "<untyped> ";
    }
}

void Logger::Log(int type, const std::string& text) {
    if ((type & logFlags) == 0) return;

    std::lock_guard guard(consoleLock);
    logContent.push_back(getTypeName(type) + text);
    if (logFile.is_open()) logFile << getTypeName(type) + text << std::endl;
    isDirty = true; std::time(&timerStart);

    // size limiting
    while(logContent.size() > 10) logContent.pop_front();
}
