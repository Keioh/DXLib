#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"


class DiploidEngineScreen : public DiploidEngineObjectInformation
{

private:
	int StartTime;         //����J�n����
	int Count;             //�J�E���^
	float Fps;             //fps
	int AvrSample = 60;//���ς����T���v����
	int SettingFPS = 60;	//�ݒ肵��FPS

	float deltatime = 0.0f;
	float deltatime_start, deltatime_end, deltatime_complate;
	float flip_count;

	float test = 0;


public:
	void FrameCount();

	void Init(int setting_fps = 60);
	void Update();
	void Draw(int x = 0, int y = 0, bool debug = false);
	void Wait();

	float GetDeltaTime();//���̃t���[���ɍs���܂łɊ|���������Ԃ��擾���܂��B(������)
	float GetFrameTime();
};