#pragma once
#include <easyx.h>
#include "Page.h"
#include "simpleStruct.h"
class menuPage: public Page {
public:
	void drawPage();
	void updatePage();
	void controlPage(const ExMessage& msg);
	bool isQuitPage();
	int getLevel() const;
private:
	int getNext()const { return 0; };
	bool isWait() { return false; };
	bool isHard;
	bool isMid;
	bool isEasy;
	bool isQuit;

	Coordinate coorUI1[2] = { {200, 0},{800, 150} };		//"半仙羡的数独游戏 绘制的坐标"
	Coordinate coorUI2[3][2] = { {450,250,550,350},{450,450,550,550},{450,650,550,750} };
};