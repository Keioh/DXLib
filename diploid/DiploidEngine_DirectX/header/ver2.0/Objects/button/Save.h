#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "system\DiploidEngineSetting.h"

class Save
{
private:
	DiploidAnimation button_animation;//�߂�{�^���̃A�j���[�V�����摜
	DiploidSelectedUIV2 button;//�߂�{�^��

public:
	void Load();
	void Init(VECTOR pos);
	void Update(DiploidEngineInput& input);
	void Draw(float frame_time = 1.0f, bool draw = true, bool debug = false);

	bool GetHit();//�J�[�\�����������Ă��邩
	bool GetClick();//�N���b�N���ꂽ��
	int GetSelected();//�I����Ԃ�

	void SetPosition(VECTOR new_pos);

	void SetSelectedFlag(int new_flag);
};