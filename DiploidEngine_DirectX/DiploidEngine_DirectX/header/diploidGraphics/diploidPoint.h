#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidPoint : public DiploidEngineObjectInformation
{
private:
	VECTOR center_position;//�I�u�W�F�N�g�̒��S�̒l

public:
	VECTOR anime_position;//�A�j���[�V����������Ƃ��̈ړ��ʂ�ۑ�����ϐ��B

	void Init(VECTOR position);//�}�E�X�ɒǏ]������ꍇ��{0,0,0}����
	void Update();
	void Draw(bool wire = true);

	void Destory() { impacted = destory = true; };

	std::string GetNameTag();//name_tag�ɐݒ肳��Ă��閼�O��Ԃ��܂��B

};