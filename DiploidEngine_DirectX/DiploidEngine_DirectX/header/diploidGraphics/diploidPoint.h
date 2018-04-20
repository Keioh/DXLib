#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"

class DiploidPoint : public DiploidEngineObject
{
private:
	VECTOR center_position;//�I�u�W�F�N�g�̒��S�̒l

public:
	VECTOR anime_position;//�A�j���[�V����������Ƃ��̈ړ��ʂ�ۑ�����ϐ��B

	void Init(VECTOR position);//�}�E�X�ɒǏ]������ꍇ��{0,0,0}����
	void Update(VECTOR move_speed, bool mouse_point = false);
	void Draw(bool wire = true);
};