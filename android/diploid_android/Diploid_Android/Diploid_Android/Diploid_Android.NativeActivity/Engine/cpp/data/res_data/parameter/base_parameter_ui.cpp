#include "data/res_data/parameter/base_parameter_ui.h"


void BaseParameterUI::Load()
{
	//�摜�̓ǂݍ���
	image_down.Load("res/button/down.png");
	image_up.Load("res/button/up.png");

	//�O���t�B�b�N�n���h����ǂݍ���
	touch_ui_down.Load(image_down.GetGraphicsHandl());	
	touch_ui_up.Load(image_up.GetGraphicsHandl());
}

void BaseParameterUI::Init(VECTOR pos, VECTOR size, const char* name)
{
	//���O��ς���
	string = name;

	//�{�^���̏����ʒu�Ƒ傫��������
	touch_ui_down.Init(pos, size);
	touch_ui_up.Init(VGet(pos.x + 256, pos.y, pos.z), size);	
	
	//�^�b�`����p�Ƀ{�^���d�l��ύX
	touch_ui_down.SetTouchFlag(true);	
	touch_ui_up.SetTouchFlag(true);
}

void BaseParameterUI::Update(DiploidEngineInput* input)
{
	//���ꂼ��̃{�^���̍��W��ۑ�
	down_position = touch_ui_down.GetPosition();
	up_position = touch_ui_up.GetPosition();


	//�ő�l�𒴂��Ȃ��悤��
	if (max_value < parameter)
	{
		parameter = max_value;//�������ꍇ�͐ݒ肵��max_value�̒l������B
	}

	//�ŏ��l�𒴂��Ȃ��悤��
	if (mini_value > parameter)
	{
		parameter = mini_value;//�������ꍇ�͐ݒ肵��mini_value�̒l������B
	}


	touch_ui_down.Updata(input);
	touch_ui_up.Updata(input);

	//������{�^�����������Ƃ��̏���
	if (touch_ui_down.GetClick() == true)
	{
		//�ݒ肵���ŏ��l��菬�����Ȃ����
		if (mini_value < parameter)
		{
			SubValue(1);//���l��������
		}
	}

	//�グ��{�^�����������Ƃ��̏���
	if (touch_ui_up.GetClick() == true)
	{
		//�ݒ肵���ő�l���傫���Ȃ����
		if (max_value > parameter)
		{
			AddValue(1);//���l���グ��
		}
	}
}

void BaseParameterUI::Draw(bool draw, bool debug)
{
	touch_ui_down.Draw(draw, debug);//������{�^���̕`��
	touch_ui_up.Draw(draw, debug);//�グ��{�^���̕`��

	DrawString(down_position.x + 24, down_position.y + 24, string, GetColor(255, 255, 255));//�p�����[�^�̖��O(��)
	DrawFormatString(up_position.x + 24, up_position.y + 24, GetColor(255, 255, 255), "%d", BaseParameterUI::GetParameterValue());//�p�����[�^�l(��)

	/*
	DrawFormatString(0, 240, GetColor(255, 255, 255), "DownButtonTouchTime:%d", touch_ui_down.GetTime());
	DrawFormatString(0, 300, GetColor(255, 255, 255), "UpButtonTouchTime:%d", touch_ui_up.GetTime());
	DrawFormatString(0, 360, GetColor(255, 255, 255), "Value:%d", BaseParameterUI::GetParameterValue());
	*/
}


void BaseParameterUI::SetMaxValue(int new_max_value)
{
	max_value = new_max_value;
}

void BaseParameterUI::SetMiniValue(int new_mini_value)
{
	mini_value = new_mini_value;
}


void BaseParameterUI::SetParameterValue(int new_value)
{
	parameter = new_value;
}

void BaseParameterUI::SetParameterName(const char* new_stirng)
{
	string = new_stirng;
}


void BaseParameterUI::AddValue(int add_value)
{
	parameter += add_value;
}

void BaseParameterUI::SubValue(int sub_value)
{
	parameter -= sub_value;
}

int BaseParameterUI::GetParameterValue()
{
	return parameter;
}