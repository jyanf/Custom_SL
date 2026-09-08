#pragma once

#include <lua.hpp>
#include <unordered_map>
#include <mutex>
#include <filesystem>
#include "../Core/package.hpp"

namespace ShadyLua {
    class LuaScript {
    public:
        struct File { std::istream& input; inline File(std::istream& input) : input(input) {} };
        using fnOpen_t = File* (*)(void* userdata, const char* filename);
        using fnClose_t = void (*)(void* userdata, File* file);
        using fnDestroy_t = void (*)(void* userdata);

        lua_State* const L;
        class : public std::recursive_mutex {
            using Base = std::recursive_mutex;
            volatile unsigned int _depth{ 0 };
        public:
            void lock() {
                Base::lock();
                ++_depth;
            }
            void unlock() {
                Base::unlock();
                --_depth;
            }
            bool try_lock() {
                if (!Base::try_lock())
                    return false;
                ++_depth;
                return true;
            }
            bool try_outer_lock() {
                if (!try_lock()) return false;
                if (_depth == 1) {
                    return true;
                }
                unlock();
                return false;
            }
        } mutex;
        void* const userdata;
        std::unordered_map<const void*, void(*)(lua_State*, int, lua_State*)> IPCCopierBuffer;
    protected:
        fnOpen_t fnOpen;
        fnClose_t fnClose;
        fnDestroy_t fnDestroy;

    public:
        LuaScript(void* userdata, fnOpen_t open, fnClose_t close, fnDestroy_t destroy = nullptr);
        LuaScript(const LuaScript&) = delete;
        LuaScript(LuaScript&&) = delete;
        virtual ~LuaScript();

        int load(const char* filename, const char* mode = 0);
        int require(const char* filename, const char* modulename, const std::string& searchpath);
        inline File* openFile(const char* filename) { return fnOpen(userdata, filename); }
        inline void closeFile(File* file) { return fnClose(userdata, file); }
        int run();
    };

    class LuaScriptFS : public LuaScript {
    private:
        std::filesystem::path basePath;
        ShadyCore::PackageEx package;

        static File* fnOpen(void* userdata, const char* filename);
        static void fnClose(void* userdata, File* file);
    public:
        LuaScriptFS(const std::filesystem::path& basePath);
    };

    extern std::unordered_map<lua_State*, ShadyLua::LuaScript*> ScriptMap;
}
