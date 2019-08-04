#pragma once
#include <string>
#include "DxLib.h"
#include "diploidObject/DiploidEngineObjectInformation.h"
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"

class DiploidUI : public DiploidObject
{
private:

public:
	DiploidUI();//�R���X�g���N�^
	~DiploidUI();//�f�X�g���N�^

	//�����N���b�N�{�^��(�����Ă����Ɍ��ɖ߂�{�^��)
	void OneClickButton_Init(VECTOR position = { 0.0f,0.0f,0.0f }, VECTOR size = { 0.0f,0.0f,0.0f }, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//�����N���b�N�{�^���̏���������
	void OneClickButton_Push(DiploidEngineImpact& impact);//�����N���b�N�{�^����impact�f�[�^�̃v�b�V��
	void OneClickButton_Load();//�����N���b�N�{�^���̓ǂݍ��ݏ���
	bool OneClickButton_Update(DiploidEngineImpact& impact, DiploidEngineInput& input);//�����N���b�N�{�^���̃A�v�f����
	void OneClickButton_Draw();//�����N���b�N�{�^���̕`�ʏ���

	void Draw() {};//���Ԃ�g��Ȃ��B
};