#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

class AutoNovel
{
private:
	DiploidAnimation anime;
	DiploidSelectedUIV2 button;
	DiploidBoxV2 box;

	float auto_speed = 0.5f;//���Ԃɉ��Z�����
	float time;//���݂̉��Z���ꂽ���Ԃ̕ۑ��p
	float target_time = 64;//���̎��ԂɂȂ�����next_flag�𗧂Ă�

	bool next_flag = false;//���ɍs���Ă������flag

public:
	void Load();
	void Init(VECTOR pos);
	void Update(DiploidEngineInput& input,int string_get_end_flag, float frame_time = 1.0f);
	void Draw(float frame_time = 1.0f, bool draw = true,  bool debug = false);

	void Reset();

	void SetSpeed(float new_speed);
	void SetSelected(int new_flag);

	bool GetHit();//�J�[�\�����������Ă��邩
	bool GetClick();//�N���b�N���ꂽ��
	int GetSelected();//�I����Ԃ�

	bool GetNextFlag();
	float GetAutoSpeed();
};