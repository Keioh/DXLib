#pragma once
#include "DxLib.h"
#include "diploidObject/DiploidEngineObjectInformation.h"
#include "diploidObject/DiploidEngineObject.h"


class DiploidUI : public DiploidEngineObjectInformation
{
private:


public:
	DiploidUI();//�R���X�g���N�^
	~DiploidUI();//�f�X�g���N�^

	void Init();//����������
	void Update();//�A�j���A�v�f����

	void Draw() {};//���Ԃ�g��Ȃ��B
};