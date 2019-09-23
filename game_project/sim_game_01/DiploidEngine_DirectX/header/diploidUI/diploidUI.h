#pragma once
#include <string>
#include "DxLib.h"
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"

class DiploidUI : public DiploidObject
{
private:

	bool button_flag = false;//�{�^����������Ă����true�i�X�C�b�`�{�^���Ŏg�p�j
	VECTOR image_size = { 0.0f,0.0f,0.0f };//�摜�̑傫����ۑ�

	bool bright_one = false, bright_two = false, bright_three = false;//�摜�̖��邳�t���E


public:
	DiploidUI();//�R���X�g���N�^
	~DiploidUI();//�f�X�g���N�^

	bool* button_flag_ptr = &button_flag;//�{�^���̃t���O�ϐ��ւ̃|�C���^�[

	//�����N���b�N�{�^����(�����Ă����Ɍ��ɖ߂�{�^��)
	void OneClickButtonBOX_Init(VECTOR position = { 0.0f,0.0f,0.0f }, VECTOR size = { 0.0f,0.0f,0.0f }, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//�����N���b�N�{�^���̏���������
	void OneClickButtonBOX_Push(DiploidEngineImpact& impact);//�����N���b�N�{�^����impact�f�[�^�̃v�b�V��
	void OneClickButtonBOX_Load(const char* path, int size_x, int size_y);//�����N���b�N�{�^���̓ǂݍ��ݏ���
	bool OneClickButtonBOX_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);//�����N���b�N�{�^���̃A�v�f����
	void OneClickButtonBOX_Draw(bool image_draw = true, bool draw = false);//�����N���b�N�{�^���̕`�ʏ���

	//�����N���b�N�{�^���~(�����Ă����Ɍ��ɖ߂�{�^��)
	void OneClickButtonCIRCLE_Init(VECTOR position = { 0.0f,0.0f,0.0f }, float radius = 0.0f, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//�����N���b�N�{�^���̏���������
	void OneClickButtonCIRCLE_Push(DiploidEngineImpact& impact);//�����N���b�N�{�^����impact�f�[�^�̃v�b�V��
	void OneClickButtonCIRCLE_Load(const char* path, int size_x, int size_y);//�����N���b�N�{�^���̓ǂݍ��ݏ���
	bool OneClickButtonCIRCLE_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);//�����N���b�N�{�^���̃A�v�f����
	void OneClickButtonCIRCLE_Draw();//�����N���b�N�{�^���̕`�ʏ���

	//�X�C�b�`�{�^����(�����ƃI���I�t�؂�ւ��{�^��)
	void SwitchButtonBOX_Init(VECTOR position = { 0.0f,0.0f,0.0f }, VECTOR size = { 0.0f,0.0f,0.0f }, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//�X�C�b�`�{�^���̏���������
	void SwitchButtonBOX_Push(DiploidEngineImpact& impact);//�X�C�b�`�{�^����impact�f�[�^�̃v�b�V��
	void SwitchButtonBOX_Load(const char* path, int size_x, int size_y);//�X�C�b�`�{�^���̓ǂݍ��ݏ���
	bool SwitchButtonBOX_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);//�X�C�b�`�{�^���̃A�v�f����
	void SwitchButtonBOX_Draw(bool image_draw = true, bool draw = false);//�X�C�b�`�{�^���̕`�ʏ���
	bool SwitchButton_Flag_Change(bool flag);//�X�C�b�`�̃t���O�������I�ɕύX����


	void Draw() {};//���Ԃ�g��Ȃ��B
};