#pragma once
#include "Page.h"
#include "Sudoku.h"
#include <map>
enum whichStatus { CHANGE_NUMBER = 1, TIP, DELETE_NUMBER, CHECK_NUMBER, ANSWER_NUMBER, BACK };
class sudokuPage: public Page {
public:
	sudokuPage();
	sudokuPage(int level);
	void drawPage();
	void updatePage();
	void controlPage(const ExMessage& msg);
	bool isQuitPage();
	bool isWait();
	int getNext()const;
	//bool get_isCHeckFail() { return isCheckFail; };

private:
	int getLevel() const;
	bool isQuit;			
	bool isNumber;			//是否在修改数字
	bool isDelete;			//是否删除
	bool isCheck;			//检查是否过关
	bool isTip;				//给出一个答案解
	bool isAnswer;			//给出全部答案
	bool isBack;			//返回到上一个页面
	bool isCheckFail;
	int numberX;			
	int numberY;			
	int vk_char;
	int status;
	int nextPage;
	map<int, char> vkTochar;
	const char* frame[5] = { "Tip","Delete","Check","Answer","Back" };
	Sudoku sudo;

	
};