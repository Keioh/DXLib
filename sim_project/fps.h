#pragma once
#include "DxLib.h"


class FPS
{
private:

	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps

public:	
	int N = 60;//���ς����T���v����
	int fps = 120;	//�ݒ肵��FPS

	FPS();

	bool Update();

	void Draw(int pos_x, int pos_y);
	void Wait();
};