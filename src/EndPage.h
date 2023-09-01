#pragma once
#include "Page.h"
class endPage: public Page {
public:

	void drawPage();
	void updatePage();
	void controlPage(const ExMessage& msg);
	bool isQuitPage();

private:
	int getLevel() const { return 0; };
	bool isWait() { return false; };
	int getNext()const { return 0; };
	bool exitOk;
	bool isQuit;
	bool isExit;
	bool isContinue;
};

