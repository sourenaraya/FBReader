/*
 * FBReader -- electronic book reader
 * Copyright (C) 2005 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __QFBREADER_H__
#define __QFBREADER_H__

#include <map>

#include <qmainwindow.h>

#include "../common/fbreader/FBReader.h"

class QFBReader : public QMainWindow, public FBReader { 
	Q_OBJECT

public:
	static const std::string ImageDirectory;
	
public:
	QFBReader();
	~QFBReader();

private:
	void closeEvent(QCloseEvent *event);
	void keyPressEvent(QKeyEvent *event);

protected:
	void setWindowCaption(const std::string &caption) { setCaption(QString::fromUtf8(caption.c_str())); }
	void addButton(ActionCode id, const std::string &name);
	void addButtonSeparator() {} // TODO: implement
	void setButtonVisible(ActionCode id, bool visible);
	void setButtonEnabled(ActionCode id, bool enable);
	void cancelSlot();
	void searchSlot();
	void fullscreenSlot() {}
	void quitSlot();
	bool isRotationSupported() const { return true; }
	
private slots:
	void doActionSlot(int buttonNumber);
	void emptySlot() {}

private:
	std::map<int,ActionCode> myKeyBindings;
};

#endif /* __QFBREADER_H__ */
