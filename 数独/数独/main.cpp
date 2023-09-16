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
	mciSendString("open ./��Զͬ��.mp3", nullptr, 0, nullptr);
	mciSendString("play ��Զͬ��.mp3 repeat", nullptr, 0, nullptr);
	//�޸��߼�����
	//setorigin(0, 800);
	//setaspectratio(1, -1);
	setbkcolor(RGB(255, 255, 255));			//���ñ���ɫΪ��ɫ
	//��ʼ��������

	while (1) {
		//menuPage
		unique_ptr<Page> menu = make_unique<menuPage>();
		gameloop(menu.get(), 60);
		/*unique_ptr<Sudoku> sudo = make_unique<Sudoku>(menu->getLevel());
		sudo->print();
		sudo->print1();*/
		//����ҳ��
		unique_ptr<Page> sudoku = make_unique<sudokuPage>(menu->getLevel());
		gameloop(sudoku.get(), 5);
		//����ҳ��
		
		if (sudoku->getNext()) {
			unique_ptr<Page> EndPage = make_unique<endPage>();
			gameloop(EndPage.get(), 60);
		}

	}
	
	mciSendString("stop ��Զͬ��.mp3", nullptr, 0, nullptr);
	//getchar();
	closegraph();

	return 0;
}