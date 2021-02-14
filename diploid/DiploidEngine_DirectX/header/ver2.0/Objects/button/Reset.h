#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

class Reset
{
private:
	DiploidAnimation return_button_animation;//�߂�{�^���̃A�j���[�V�����摜
	DiploidSelectedUIV2 return_button;//�߂�{�^��

public:
	void Load();
	void Init(VECTOR pos);
	void Update(DiploidEngineInput& input);
	void Draw(bool draw = true, bool debug = false);

	bool GetHit();//�J�[�\�����������Ă��邩
	bool GetClick();//�N���b�N���ꂽ��
	int GetSelected();//�I����Ԃ�

	void SetSelectedFlag(int new_flag);
};