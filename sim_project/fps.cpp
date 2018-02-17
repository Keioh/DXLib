#include "fps.h"

FPS::FPS() {
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
}

bool FPS::Update() {
	if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	return true;
}

void FPS::Draw(int pos_x, int pos_y) {
	DrawFormatString(pos_x, pos_y, GetColor(255, 255, 255), "%.2f FPS", mFps);
}

void FPS::Wait() {
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / fps - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}