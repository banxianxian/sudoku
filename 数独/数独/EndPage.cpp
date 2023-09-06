#include "EndPage.h"
void endPage::drawPage() {
	//设置结束语
	settextcolor(RED);
	settextstyle(100, 0, "微软雅黑");
	const char* text1 = "回答正确";
	RECT rect1 = { succUI[0].x,succUI[0].y,succUI[1].x,succUI[1].y };
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
	RECT  rect2 = { bottomUI[QUIT][0].x,bottomUI[QUIT][0].y,
		bottomUI[QUIT][1].x,bottomUI[QUIT][1].y };

	roundrect(bottomUI[QUIT][0].x, bottomUI[QUIT][0].y, 
		bottomUI[QUIT][1].x, bottomUI[QUIT][1].y, 15, 15);

	drawtext(text2, &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//第二个按钮
	if (isContinue) {
		settextcolor(RED);
	}
	else {
		settextcolor(BLACK);
	}
	const char* text3 = "继续";
	RECT rect3 = { bottomUI[CONTINUE][0].x,bottomUI[CONTINUE][0].y,
		bottomUI[CONTINUE][1].x,bottomUI[CONTINUE][1].y };

	roundrect(bottomUI[CONTINUE][0].x, bottomUI[CONTINUE][0].y,
		bottomUI[CONTINUE][1].x, bottomUI[CONTINUE][1].y, 15, 15);

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
		
		if (mouseX > bottomUI[QUIT][0].x && mouseX < bottomUI[QUIT][1].x && 
			mouseY > bottomUI[QUIT][0].y && mouseY < bottomUI[QUIT][1].y) {
			isExit = true;
		}
		else if (mouseX > bottomUI[CONTINUE][0].x && mouseX < bottomUI[CONTINUE][1].x 
			&& mouseY > bottomUI[CONTINUE][0].y && mouseY < bottomUI[CONTINUE][1].y) {
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