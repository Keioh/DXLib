#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidCircle : public DiploidEngineObjectInformation
{
private:
	VECTOR center_position;//�I�u�W�F�N�g�̒��S�̒l

public:		
	VECTOR anime_position;//�A�j���[�V����������Ƃ��̈ړ��ʂ�ۑ�����ϐ��B
	VECTOR anime_size;//�A�j���[�V����������Ƃ��̃T�C�Y��ۑ�����ϐ��B
	VECTOR origin_size;//���X�̑傫��

	void Init(VECTOR position, float size);
	void Update();
	void Draw(bool wire = true);

	void Destory() { impacted = destory = true; };
};