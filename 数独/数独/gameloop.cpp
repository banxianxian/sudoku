#include <easyx.h>
#include "gameloop.h"
#include <cstdio>
void gameloop(Page* scene,int fps) {
	//计时工具
	LARGE_INTEGER startCount, endCount, F;
	long long elapse = 0;

	timeBeginPeriod(1);
	QueryPerformanceFrequency(&F);			//获取计时器的频率
	BeginBatchDraw();
	while (1) {
		QueryPerformanceCounter(&startCount);

		cleardevice();
		//绘图
		//scene->updatePage();
		scene->drawPage();

		//更新数独数组
		scene->updatePage();
		FlushBatchDraw();
		//if (scene->isWait()) {
		//	Sleep(1000);
		//}
		QueryPerformanceCounter(&endCount);
		//elapse 单位为微秒
		elapse = (endCount.QuadPart - startCount.QuadPart) * 1000000 / F.QuadPart;
		while (elapse < 1000000 / fps) {
			Sleep(1);
			ExMessage msg;
			bool isOK = peekmessage(&msg, EX_MOUSE | EX_KEY);
			if (isOK) {
				scene -> controlPage(msg);
			}
			QueryPerformanceCounter(&endCount);
			elapse = (endCount.QuadPart - startCount.QuadPart) * 1000000 / F.QuadPart;
		}

		if (scene->isQuitPage()) {
			break;
		}
	}
	
	EndBatchDraw();
	timeEndPeriod(1);

}



//void gameloop(unique<Page>& target, int fps) {
// 
//}