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
	void OneClickButtonBOX_Init(VECTOR position = { 0.0f,0.0f,0.0f }, VECTOR size = { 0.0f,0.0f,0.0f }, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//�����N���b�N�{�^���̏���������
	void OneClickButtonBOX_Push(DiploidEngineImpact& impact);//�����N���b�N�{�^����impact�f�[�^�̃v�b�V��
	void OneClickButtonBOX_Load();//�����N���b�N�{�^���̓ǂݍ��ݏ���
	bool OneClickButtonBOX_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);//�����N���b�N�{�^���̃A�v�f����
	void OneClickButtonBOX_Draw();//�����N���b�N�{�^���̕`�ʏ���

	//�����N���b�N�{�^��(�����Ă����Ɍ��ɖ߂�{�^��)
	void OneClickButtonCIRCLE_Init(VECTOR position = { 0.0f,0.0f,0.0f }, float radius = 0.0f, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//�����N���b�N�{�^���̏���������
	void OneClickButtonCIRCLE_Push(DiploidEngineImpact& impact);//�����N���b�N�{�^����impact�f�[�^�̃v�b�V��
	void OneClickButtonCIRCLE_Load();//�����N���b�N�{�^���̓ǂݍ��ݏ���
	bool OneClickButtonCIRCLE_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);//�����N���b�N�{�^���̃A�v�f����
	void OneClickButtonCIRCLE_Draw();//�����N���b�N�{�^���̕`�ʏ���

	void Draw() {};//���Ԃ�g��Ȃ��B
};