#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Main/Collision.h"
#include "diploidInput/DiploidEngineInput.h"

class SwitchButtonBoxV2
{
private:
	DiploidBoxV2 box;//�����蔻��pBOX
	DiploidCollision collision;//�����蔻��

	DiploidEngineInput input;//�C���v�b�g

	bool button_hit_flag = false;//�{�^���ɐG��Ă����true
	bool button_click_flag = false;//�{�^�����N���b�N�����u�Ԃ�true
	int button_selected_flag = -1;//�{�^����������Ă����1�i�X�C�b�`�{�^���Ŏg�p�j

	int mouse_button_type = MOUSE_INPUT_LEFT;//�}�E�X�̂ǂ̃{�^���������΃N���b�N���肪�L���Ȃ̂��B

public:
	void Init(VECTOR pos, VECTOR size, int mouse_button);
	void Update();
	void Draw(bool draw = true);

	bool GetHit();
	bool GetClick();
	int GetSelected();

	DiploidBoxV2& GetBoxPtr();//�����蔻��ŗp���Ă���BOX�������邽�߂̎Q��
};