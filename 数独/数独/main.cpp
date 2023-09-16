#include <iostream>
#include <memory>
#include <easyx.h>
#include "Page.h"
#include "menuPage.h"
#include "sudokuPage.h"
#include "Sudoku.h"
#include "EndPage.h"
#include "gameloop.h"
#pragma comment(lib, "winmm.lib")
using namespace std;
int main() {
	
	initgraph(1000, 800);	//,EX_SHOWCONSOLE
	mciSendString("open ./永远同在.mp3", nullptr, 0, nullptr);
	mciSendString("play 永远同在.mp3 repeat", nullptr, 0, nullptr);
	//修改逻辑坐标
	//setorigin(0, 800);
	//setaspectratio(1, -1);
	setbkcolor(RGB(255, 255, 255));			//设置背景色为白色
	//开始三个界面

	while (1) {
		//menuPage
		unique_ptr<Page> menu = make_unique<menuPage>();
		gameloop(menu.get(), 60);
		/*unique_ptr<Sudoku> sudo = make_unique<Sudoku>(menu->getLevel());
		sudo->print();
		sudo->print1();*/
		//数独页面
		unique_ptr<Page> sudoku = make_unique<sudokuPage>(menu->getLevel());
		gameloop(sudoku.get(), 5);
		//结束页面
		
		if (sudoku->getNext()) {
			unique_ptr<Page> EndPage = make_unique<endPage>();
			gameloop(EndPage.get(), 60);
		}

	}
	
	mciSendString("stop 永远同在.mp3", nullptr, 0, nullptr);
	//getchar();
	closegraph();

	return 0;
}