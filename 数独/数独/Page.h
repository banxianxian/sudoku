#pragma once
#include <easyx.h>
class Page {
public:
	virtual void drawPage() = 0;
	virtual void updatePage() = 0;
	virtual void controlPage(const ExMessage& msg) = 0;
	virtual bool isQuitPage() = 0;

	virtual int getLevel() const = 0;
	virtual bool isWait() = 0;
	virtual int getNext()const = 0;
};