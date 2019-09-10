#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidUI/diploidUI.h"

class MyCastle
{
private:
	DiploidObject json;//JSON�t�@�C���ǂݍ��ݗp
	DiploidObject back_color_circle_object;//���_�̔w�i�F
	DiploidObject defense_circle_object;//�h�ǃI�u�W�F�N�g

	DiploidUI ui;//���_�I��UI�I�u�W�F�N�g

	int population;
	int defense;
	int money;
	int size;

public:
	MyCastle();//�R���X�g���N�^
	
	void Load();//Json�t�@�C���Ɖ摜�≹�Ȃ�
	void Inti(VECTOR position = { 0.0f,0.0f,0.0f }, float radius = 10.0f);
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool wire = true, bool debug = false);

};