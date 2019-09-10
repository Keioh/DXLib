#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidCircle : public DiploidEngineObjectInformation
{
private:
	VECTOR center_position;//�I�u�W�F�N�g�̒��S�̒l
	VECTOR anime_position;//�A�j���[�V����������Ƃ��̈ړ��ʂ�ۑ�����ϐ��B
	VECTOR anime_size;//�A�j���[�V����������Ƃ��̃T�C�Y��ۑ�����ϐ��B
	VECTOR origin_size;//���X�̑傫��

	void DrawNameTag();

public:	

	DiploidCircle();
	~DiploidCircle();

	void Init(VECTOR position, float size);
	void Update();
	void Draw(bool wire = true);

	//VECTOR MovePosition(VECTOR value = { 0.0f,0.0f,0.0f });//�ړ����������Ƃ��Ɏg�p�B(value�ɂ�1�t���[�����ɉ��h�b�g�ړ����邩���w��B)

	float GetSize();//�~�̑傫����Ԃ��܂��B
	VECTOR GetCenterPosition();//�����̈ʒu��Ԃ��܂��B

	void Destory() { impacted = destory = true; };

	int SetDrawNameTagFlag(int flag = TRUE);//TRUE��name_tag��\���B


	std::string GetNameTag();//name_tag�ɐݒ肳��Ă��閼�O��Ԃ��܂��B

};