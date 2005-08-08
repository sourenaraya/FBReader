#ifndef __PALMFBREADER_H__
#define __PALMFBREADER_H__

#include <PalmOS.h>				

#include "../common/fbreader/FBReader.h"

void EventLoop() FB_SECTION;

class PalmPaintContext;

class PalmFBReader : public FBReader {

public:
	PalmFBReader() FB_SECTION;
	~PalmFBReader() FB_SECTION;
	void setWindowCaption(const std::string &caption) FB_SECTION;
	void addButton(ActionCode id, const std::string &name) FB_SECTION;
	void addButtonSeparator() FB_SECTION;
	void setButtonVisible(ActionCode id, bool visible) FB_SECTION;
	void setButtonEnabled(ActionCode id, bool enable) FB_SECTION;
	void searchSlot() FB_SECTION;
	void cancelSlot() FB_SECTION;
	void fullscreenSlot() FB_SECTION;
	void quitSlot() FB_SECTION;
	bool isRotationSupported() const FB_SECTION;
	void stylusPressEvent(int x, int y) FB_SECTION;
	void paintEvent() FB_SECTION;
};

extern PalmFBReader *READER;

#endif /* __PALMFBREADER_H__ */
