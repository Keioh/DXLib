#pragma once
#include <math.h>
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

//����T�C�Y�ύX�֐��͖�����
class DiploidLine : public DiploidEngineObjectInformation
{
private:
	VECTOR POSITION_ONE, POSITION_TWO;

	VECTOR anime_position_one, anime_position_two;//�A�j���[�V����������Ƃ��̈ړ��ʂ�ۑ�����ϐ��B
	VECTOR anime_size;//�A�j���[�V����������Ƃ��̃T�C�Y��ۑ�����ϐ��B
	VECTOR origin_size;//���X�̑傫��

public:

	VECTOR Position_one, Position_two;

	void Init(VECTOR position_one, VECTOR position_two);
	void Update();
	void Draw(bool wire = false);

	void Destory() { impacted = destory = true; };

	double GetAngle();//�����̌X�����擾

};