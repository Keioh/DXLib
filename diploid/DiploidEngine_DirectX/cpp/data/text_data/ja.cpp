#include "data/text_data/ja.h"

void ja_text::Load()
{
	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//�t�H���g���쐬
	
	data[0].Load("���邳�����̐�̐����苿���B");
	data[0].SetSceneName("abandoned_road");
	//data[1].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[1]);

	data[1].Load("�Ȃ������͂����ɂ���̂��A�ǂ�����ė����̂��A�肩�ł͂Ȃ��B\n������A�m���Ȃ��Ƃ͖ڂ̑O�ɂ��鏭���̌��t�Ɏ����X���鎖�����������B");
	data[1].SetSceneName("abandoned_road");
	//data[2].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[2]);

	data[2].Load("����1\n�u�N�͎���̐��E��M���Ă��邩���H�v");
	data[2].SetSceneName("abandoned_road");
	//data[3].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[3]);

	data[3].Load("��l��\n�u......�B�v");
	data[3].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[4].Load("����1\n�u��������̐��E���݂�Ƃ���΁A�����͂ǂ�Ȑ��E�Ȃ̂��낤�ȁB�v");
	data[4].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[5].Load("��l��\n�u......�B�v");
	data[5].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[6].Load("����1\n�u�ӂ��A���܂Ȃ��ȁB����Șb�����āB�v");
	data[6].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[7].Load("�����͌y���΂��A������̗l�q���f�����߂��U������B");
	data[7].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[8].Load("���̊�͐\����Ȃ������ȁA�����Ĉ��������ȕ\������Ă����B");
	data[8].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[9].Load("����1\n�u����Ȋ�����Ȃ��ł���B���܂ň������Ȃ邶��Ȃ����B�v");
	data[9].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);


	//��L�̃f�[�^��z���push
	for (int count = 0; count != 256; count++)
	{
		//data[count].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
		string.push_back(data[count]);
	}

	//�ēǂݍ��ݎ��̏d���f�[�^�̍폜
	if (string.size() > 256)
	{
		string.erase(string.begin(), string.begin() + 256);
	}
}

void ja_text::Init(DiploidEngineSetting& setting)
{
	for (int count = 0; count != 256; count++)
	{
		string[count].Init(setting.GetSystemData().window_x * x_scale, setting.GetSystemData().window_y - y_scale, font.GetHandle());
	}
}

void ja_text::SetSpeed(int new_speed)
{
	if (!string.empty())
	{
		for (int count = 0; count != string.size(); count++)
		{
			string[count].SetSpeed(new_speed);
		}
	}
}

void ja_text::Reset()
{
	if (!string.empty())
	{
		for (int count = 0; count != string.size(); count++)
		{
			string[count].Reset();
		}
	}
}
