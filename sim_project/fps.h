#pragma once
#include "DxLib.h"


class FPS
{
private:

	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps

public:	
	int N = 60;//平均を取るサンプル数
	int fps = 120;	//設定したFPS

	FPS();

	bool Update();

	void Draw(int pos_x, int pos_y);
	void Wait();
};