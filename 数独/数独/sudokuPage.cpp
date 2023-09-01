#include "sudokuPage.h"
#include <easyx.h>
#include <cstdio>
sudokuPage::sudokuPage() {

}

sudokuPage::sudokuPage(int level): sudo(level) {
	
	for (int i = 1; i <= 9; i++) {
		vkTochar[48 + i] = '0' + i;
	}

}

void sudokuPage::drawPage() {
	//绘制数独
	//需要重新设置字体颜色，不然当开始简单模式会以红色出现
	settextcolor(BLACK);
	int leftStart = 100;
	int topStart = 100;
	int rightStart = 150;
	int bottomStart = 150;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int left = leftStart + i * 50;
			int top = topStart + j * 50;
			int right = rightStart + i * 50;
			int bottom = bottomStart + j * 50;
			rectangle(left, top, right, bottom);
			RECT rect = { left, top , right, bottom };
			char number;
			if (sudo.get_sudoku(i, j) == '.') {
				number = ' ';
			}
			else {
				number = sudo.get_sudoku(i, j);
			}
			drawtext(number, &rect, DT_CENTER);
		}
	}

	//五个按键UI
	settextstyle(35, 0, "微软雅黑");
	leftStart = 750;
	topStart = 100;
	rightStart = 850;
	bottomStart = 150;
	for (int i = 0; i < 5; i++) {
		int top = topStart + i * 100;
		int bottom = bottomStart + i * 100;
		roundrect(leftStart, top, rightStart, bottom, 15, 15);
		RECT rect = { leftStart, top, rightStart, bottom };
		if (i == 0 && isTip || i == 1 && isDelete || i == 2 
			&& isCheck || i == 3 && isAnswer || i == 4 && isBack) {
			settextcolor(RED);
		}
		
		drawtext(frame[i], &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		
		/*if (isCheck && isCheckFail) {
			BeginBatchDraw();
			cout << "yes" << endl;
			clearroundrect(750, 300, 850, 350, 15, 15);
			RECT rect = { 750,300,850,350 };
			drawtext("error", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}*/
		
		
		settextcolor(BLACK);
	}

}

void sudokuPage::updatePage() {
	if (status == CHANGE_NUMBER) {
		printf("x = %d  y = %d vk = %d\n", numberX, numberY, vk_char);
		if (sudo.isCanUse[numberX][numberY]) {
			//map vkTochar 映射 将按键的vk码转为字符
			sudo.change_sudoku(numberX, numberY, vkTochar[vk_char]);		
		}
	}
	else if (status == TIP) {

	}
	else if (status == DELETE_NUMBER) {
		sudo.delete_sudoku(numberX, numberY);
	}
	else if (status == CHECK_NUMBER) {
		if (sudo.check_sudoku()) {
			nextPage = 1;
			isQuit = true;
		}
		else {
			isCheckFail = true;
		}
	}

	else if (status == ANSWER_NUMBER) {
		sudo.answer_sudoku();
	}
	else if (status == BACK) {
		nextPage = 0;
		isQuit = true;
	}


	status = 0;
}

void sudokuPage::controlPage(const ExMessage& msg) {
	switch (msg.message)
	{
	case WM_MOUSEMOVE:
		{
			int mouseX = msg.x;
			int mouseY = msg.y;
			isNumber = false;
			isDelete = false;
			isCheck = false;
			isTip = false;
			isAnswer = false;
			isBack = false;
			//判断是否想要修改数字
			if (mouseX > 100 && mouseX < 550 && mouseY > 100 && mouseY < 550) {
				//numberX = (mouseX - 100) / 50;
				//numberY = (mouseY - 100) / 50;
				isNumber = true;
			}
			else if (mouseX > 750 && mouseX < 850 && mouseY > 100 && mouseY < 150) {
				isTip = true;
			}
			else if (mouseX > 750 && mouseX < 850 && mouseY > 200 && mouseY < 250) {
				isDelete = true;
			}
			else if (mouseX > 750 && mouseX < 850 && mouseY > 300 && mouseY < 350) {
				isCheck = true;
			}
			else if (mouseX > 750 && mouseX < 850 && mouseY > 400 && mouseY < 450) {
				isAnswer = true;
			}
			else if (mouseX > 750 && mouseX < 850 && mouseY > 500 && mouseY < 550) {
				isBack = true;
			}
		
		}
		break;

	case WM_LBUTTONDOWN:
		if (isNumber) {
			//status = CHANGE_NUMBER;
			int mouseX = msg.x;
			int mouseY = msg.y;
			numberX = (mouseX - 100) / 50;
			numberY = (mouseY - 100) / 50;
		} 
		else if (isTip) {
			status = TIP;
		}
		else if (isDelete) {
			status = DELETE_NUMBER;
		}
		else if (isCheck) {
			status = CHECK_NUMBER;
		}
		else if (isAnswer) {
			status = ANSWER_NUMBER;
		}
		else if (isBack) {
			status = BACK;
		}

		break;

	case WM_KEYDOWN:
		vk_char = msg.vkcode;
		if (isNumber) {
			status = CHANGE_NUMBER;
		}
		break;
	}

}

bool sudokuPage::isQuitPage() {

	return isQuit;
}

int sudokuPage::getLevel()const {
	return 0;
}

bool sudokuPage::isWait() {
	if (isCheckFail) {
		isCheckFail = false;
		return true;
	}
	else {
		return false;
	}
}

int sudokuPage::getNext()const {
	return nextPage;
}