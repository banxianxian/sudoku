#include "menuPage.h"
#include <cstdio>
//enum levelUI { hard, middle, easy };

int menuPage::getLevel() const {
	if (isHard) {
		return hard;
	}
	else if (isMid) {
		return middle;
	}
	else if (isEasy) {
		return easy;
	}
	else {
		return 999;						//表示错误
	}
}


void menuPage::drawPage() {
	//绘制半仙羡的数独游戏
	//设置字体样式
	setbkmode(TRANSPARENT);				//将字体背景设置为透明
	settextcolor(BLACK);				//设置字体颜色
	settextstyle(100, 0, "微软雅黑");	//设置字体样式

	LOGFONT fontStyle;
	gettextstyle(&fontStyle);
	fontStyle.lfQuality = ANTIALIASED_QUALITY;	//抗锯齿
	settextstyle(&fontStyle);

	//在指定区域内绘图
	RECT area1 = { coorUI1[0].x,coorUI1[0].y,coorUI1[1].x,coorUI1[1].y };
	const char* text1 = "半仙羡的数独游戏";
	drawtext(text1, &area1, DT_CENTER);



	//绘制三个关卡
	const char* text[3] = { "困难","中等","容易" };
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 4);
	settextstyle(50, 0, "微软雅黑");
	RECT area[3] = {
	{coorUI2[hard][0].x, coorUI2[hard][0].y,coorUI2[hard][1].x, coorUI2[hard][1].y },
	{coorUI2[middle][0].x, coorUI2[middle][0].y,coorUI2[middle][1].x, coorUI2[middle][1].y },
	{coorUI2[easy][0].x, coorUI2[easy][0].y,coorUI2[easy][1].x, coorUI2[easy][1].y }
	};
	//绘制困难
	if (isHard) {
		settextcolor(RED);
	}
	else {
		settextcolor(BLACK);
	}
	roundrect(coorUI2[hard][0].x, coorUI2[hard][0].y, coorUI2[hard][1].x, coorUI2[hard][1].y, 50, 50);
	drawtext(text[hard], &area[hard], DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	//绘制中等
	
	if (isMid) {
		settextcolor(RED);
	}
	else {
		settextcolor(BLACK);
	}
	roundrect(coorUI2[middle][0].x, coorUI2[middle][0].y, coorUI2[middle][1].x, coorUI2[middle][1].y, 50, 50);
	drawtext(text[middle], &area[middle], DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	
	//绘制简单
	if (isEasy) {
		settextcolor(RED);
	}
	else {
		settextcolor(BLACK);
	}
	roundrect(coorUI2[easy][0].x, coorUI2[easy][0].y, coorUI2[easy][1].x, coorUI2[easy][1].y, 50, 50);
	drawtext(text[easy], &area[easy], DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}
void menuPage::updatePage() {

}

void menuPage::controlPage(const ExMessage& msg) {
	switch(msg.message) {
	case WM_MOUSEMOVE:
	{
		int mouseX = msg.x;
		int mouseY = msg.y;
		
		isEasy = false;
		isMid = false;
		isHard = false;
		if (mouseX > coorUI2[hard][0].x && mouseX < coorUI2[hard][1].x
			&& mouseY > coorUI2[hard][0].y && mouseY < coorUI2[hard][1].y) {
			isHard = true;
		}
		else if (mouseX > coorUI2[middle][0].x && mouseX < coorUI2[middle][1].x
			&& mouseY > coorUI2[middle][0].y && mouseY < coorUI2[middle][1].y) {
			isMid = true;
		}
		else if (mouseX > coorUI2[easy][0].x && mouseX < coorUI2[easy][1].x
			&& mouseY > coorUI2[easy][0].y && mouseY < coorUI2[easy][1].y) {
			isEasy = true;
		}
	}
		break;

	case WM_LBUTTONDOWN:
	{

		if (isHard || isMid || isEasy) {
			isQuit = true;
		}
	}
	break;

	}
}
bool menuPage::isQuitPage() {
	return isQuit;
}
