#pragma once
#include "Page.h"
#include "simpleStruct.h"
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
	Coordinate bottomUI[2][2] = { {350,250,450,300} ,{550,250,650,300} };
	Coordinate succUI[2] = { 300,100,700,250 };
};

