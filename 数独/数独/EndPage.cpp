#include "EndPage.h"
void endPage::drawPage() {
	//设置结束语
	settextcolor(RED);
	settextstyle(100, 0, "微软雅黑");
	const char* text1 = "回答正确";
	RECT rect1 = { 300,100,700,250 };
	drawtext(text1, &rect1, DT_CENTER);
	//第一个按钮
	settextstyle(25, 0, "微软雅黑");

	if (isExit) {
		settextcolor(RED);
	}
	else {
		settextcolor(BLACK);
	}
	const char* text2 = "退出";
	RECT  rect2 = { 350,250,450,300 };
	roundrect(350, 250, 450, 300, 15, 15);
	drawtext(text2, &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//第二个按钮
	if (isContinue) {
		settextcolor(RED);
	}
	else {
		settextcolor(BLACK);
	}
	const char* text3 = "继续";
	RECT rect3 = { 550,250,650,300 };
	roundrect(550, 250, 650, 300, 15, 15);
	drawtext(text3, &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

}

void endPage::updatePage() {
	
		if (exitOk) {
			exit(0);
		}
	

}

void endPage::controlPage(const ExMessage& msg) {
	switch (msg.message) {
	case WM_MOUSEMOVE:
	{
		int mouseX = msg.x;
		int mouseY = msg.y;

		isExit = false;
		isContinue = false;
		
		if (mouseX > 350 && mouseX < 450 && mouseY > 250 && mouseY < 300) {
			isExit = true;
		}
		else if (mouseX > 550 && mouseX < 650  && mouseY > 250 && mouseY < 300) {
			isContinue = true;
		}
		
	}
	break;

	case WM_LBUTTONDOWN:
	{
		if (isExit) {
			exitOk = true;
		}
		if (isContinue) {
			isQuit = true;
		}
		
	}
	break;

	}
}

bool endPage::isQuitPage() {
	return isQuit;

}