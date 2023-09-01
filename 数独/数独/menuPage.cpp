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
		return 999;						//��ʾ����
	}
}


void menuPage::drawPage() {
	//���ư����۵�������Ϸ
	//����������ʽ
	setbkmode(TRANSPARENT);				//�����屳������Ϊ͸��
	settextcolor(BLACK);				//����������ɫ
	settextstyle(100, 0, "΢���ź�");	//����������ʽ

	LOGFONT fontStyle;
	gettextstyle(&fontStyle);
	fontStyle.lfQuality = ANTIALIASED_QUALITY;	//�����
	settextstyle(&fontStyle);

	//��ָ�������ڻ�ͼ
	RECT area1 = { coorUI1[0].x,coorUI1[0].y,coorUI1[1].x,coorUI1[1].y };
	const char* text1 = "�����۵�������Ϸ";
	drawtext(text1, &area1, DT_CENTER);



	//���������ؿ�
	const char* text[3] = { "����","�е�","����" };
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 4);
	settextstyle(50, 0, "΢���ź�");
	RECT area[3] = {
	{coorUI2[hard][0].x, coorUI2[hard][0].y,coorUI2[hard][1].x, coorUI2[hard][1].y },
	{coorUI2[middle][0].x, coorUI2[middle][0].y,coorUI2[middle][1].x, coorUI2[middle][1].y },
	{coorUI2[easy][0].x, coorUI2[easy][0].y,coorUI2[easy][1].x, coorUI2[easy][1].y }
	};
	//��������
	if (isHard) {
		settextcolor(RED);
	}
	else {
		settextcolor(BLACK);
	}
	roundrect(coorUI2[hard][0].x, coorUI2[hard][0].y, coorUI2[hard][1].x, coorUI2[hard][1].y, 50, 50);
	drawtext(text[hard], &area[hard], DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	//�����е�
	
	if (isMid) {
		settextcolor(RED);
	}
	else {
		settextcolor(BLACK);
	}
	roundrect(coorUI2[middle][0].x, coorUI2[middle][0].y, coorUI2[middle][1].x, coorUI2[middle][1].y, 50, 50);
	drawtext(text[middle], &area[middle], DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	
	//���Ƽ�
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
