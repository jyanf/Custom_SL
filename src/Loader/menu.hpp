#pragma once

#include <SokuLib.hpp>

class ModList : public SokuLib::CFileList {
public:
    SokuLib::CDesign::Gauge* scrollBar;
    int scrollLen;

    ModList();
    void renderScroll(float x, float y, int offset, int size, int view);

    virtual void updateList() override;
    virtual int appendLine(SokuLib::String& out, void* unknown, SokuLib::Deque<SokuLib::String>& list, int index) override;
};

class ModMenu : public SokuLib::IMenu {
private:
    bool viewDirty = true;
    bool listDirty = true;
    bool settingsDirty = false;
    bool hasAction = false;
    SokuLib::CDesign design;
    ModList modList;
    SokuLib::MenuCursor modCursor;
    SokuLib::Sprite viewTitle;
    SokuLib::Sprite viewContent;
    SokuLib::Sprite viewOption;
    SokuLib::Sprite viewPreview;
    SokuLib::MenuCursor viewCursor;
    SokuLib::Guide guide;
    int orderCursor = -1;
    int scrollPos = 0;//save modCursor.unknown10 in case of list update causing moving
    int state = 0;
    int optionCount = 0;
    int options[3];
    const int rowsInList = 17;

public:
    ModMenu();
    ~ModMenu() override;
	void _() override;
	int onProcess() override;
	int onRender() override;
    void updateView(int index);
    void swap(int i, int j);
};
