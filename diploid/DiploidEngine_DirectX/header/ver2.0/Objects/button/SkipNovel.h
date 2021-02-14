#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

class SkipNovel
{
private:
	DiploidAnimation anime;
	DiploidSelectedUIV2 button;
	DiploidBoxV2 box;
	
	float skip_speed = 5;
	float next_time = 60;
	float time;

	int next_flag = 1;//���ɍs���Ă������flag

public:
	void Load();
	void Init(VECTOR pos);
	void Update(DiploidEngineInput& input);
	void Draw(bool draw = true,  bool debug = false);


	void Reset();


	void SetSelected(int new_flag);


	bool GetHit();//�J�[�\�����������Ă��邩
	bool GetClick();//�N���b�N���ꂽ��
	int GetSelected();//�I����Ԃ�

	int GetNextFlag();//1�Ŏ��ւ���flag�������Ă���A-1�őI����ԂłȂ��A0�őI����Ԃ����X�L�b�v�����𖞂����ĂȂ��B
};