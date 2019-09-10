#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"

//��������̏���
class Dice
{
private:
	int roll_time;//�U�葱���鎞��

	DiploidObject dice_1;
	DiploidObject dice_2;
	DiploidObject dice_3;
	DiploidObject dice_4;
	DiploidObject dice_5;
	DiploidObject dice_6;

	DiploidBox box;

	DiploidEngineInput input;

	bool dice_roll;//���������U�邩�~��Ȃ���

public:
	Dice();
	~Dice() {};

	int dice_number;//��������̖ڂ�Ԃ��B

	bool dice_roll_active;//���������U���Ă���Œ����A��������Ȃ����B

	void Load();//�摜�̓ǂݍ��݁B
	void Init(VECTOR pos = { 0.0f,0.0f,0.0f }, float scale = 1.0f);//������
	void Push(DiploidEngineImpact& impact, VECTOR pos, float scale);//�����蔻��ǉ�
	void Update();//�X�V����
	void Draw(bool draw = true);//�`�ʏ���

	void Roll();//�_�C�X��U��

};