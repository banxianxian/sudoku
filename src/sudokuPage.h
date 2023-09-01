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
	bool isNumber;			//�Ƿ����޸�����
	bool isDelete;			//�Ƿ�ɾ��
	bool isCheck;			//����Ƿ����
	bool isTip;				//����һ���𰸽�
	bool isAnswer;			//����ȫ����
	bool isBack;			//���ص���һ��ҳ��
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