#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidTouchUI.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "diploidInput/DiploidEngineInput.h"

class BaseParameterUI
{
private:
	DiploidTouchUI touch_ui_up;//���l���グ��p
	DiploidTouchUI touch_ui_down;//���l��������p

	DiploidImageV2 image_up;//���l���グ��{�^���̉摜
	DiploidImageV2 image_down;//���l��������{�^���̉摜

	int parameter = 0;//�p�����[�^�l�ۑ��p

	int max_value = 9999;//�p�����[�^�̍ő�l
	int mini_value = 0;//�p�����[�^�̍ŏ��l

	const char* string = "no_name_parameter";

	VECTOR down_position;
	VECTOR up_position;


public:
	void Load();
	void Init(VECTOR pos, VECTOR size, const char* name = "no_name_parameter");
	void Update(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	void SetParameterValue(int new_value);//�p�����[�^�l��V�����ݒ肵�܂��B
	void SetMaxValue(int new_max_value);//�p�����[�^�l�̍ő�����ݒ肵�܂��B
	void SetMiniValue(int new_mini_value);//�p�����[�^�l�̍ŏ������l��ݒ肵�܂��B
	void SetParameterName(const char* new_stirng);

	void AddValue(int add_value);//�p�����[�^�l��add_value�������₵�܂��B
	void SubValue(int sub_value);//�p�����[�^�l��add_value�������炵�܂��B

	int GetParameterValue();//���݂̃p�����[�^�l�𓾂܂��B

};