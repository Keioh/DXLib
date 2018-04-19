#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"

class DiploidCircle : public DiploidEngineObject
{
private:
	VECTOR center_position;//�I�u�W�F�N�g�̒��S�̒l
	float origin_size;//���X�̑傫��

public:		
	VECTOR anime_position;//�A�j���[�V����������Ƃ��̈ړ��ʂ�ۑ�����ϐ��B
	float anime_size;//�A�j���[�V����������Ƃ��̃T�C�Y��ۑ�����ϐ��B

	void Init(VECTOR position, float size);
	void Update(VECTOR move_speed, float move_size);
	void Draw(bool wire = true);
};