#include "data/text_data/ja.h"

void ja_text::Load()
{
	line_count = 0;
	string.clear();
	name.clear();

	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//�t�H���g���쐬


	file.ReadOpen("text/jp/jp.txt");//�t�@�C���ǂݍ���

	while ((ProcessMessage() == 0) && (file.GetFileInAdr()))
	{
		string_data.push_back(file.GetLine());//�t�@�C�������s�ǂݍ��݂�ňꎞ�ۑ�
	}

	file.Close();//�t�@�C�������


	for(int count = 0; count != string_data.size()-1; count++)
	{	
		std::string one, two;

		trans.SplitString(string_data[count], one, two);//������f�[�^�𕪊�


		string.push_back(DiploidStringV2::DiploidStringV2());//��̃f�[�^��ǉ�

		name.push_back(DiploidStringV2::DiploidStringV2());//��̃f�[�^��ǉ�


		name[count].Create(one);//���O�f�[�^�̕ۑ�

		string[count].Create(two);//���O�ɑ΂��镶����f�[�^�̕ۑ�

		//string[line_count].SetSceneName("abandoned_road");	
	}

	line_count = string_data.size() - 1;//���s��-1(-1���Ȃ��ƃG���[���o��)

	string_data.clear();//�f�[�^���폜
}

void ja_text::Init(DiploidEngineSetting& setting)
{
	if (!string.empty())
	{
		for (int count = 0; count != string.size(); count++)
		{
			string[count].Init(setting.GetSystemData().window_x * x_scale, setting.GetSystemData().window_y - y_scale, font.GetFontInfo());
			string[count].SetWidth(setting.GetSystemData().window_x * 0.65f);//�\������ݒ�B
		}
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

int ja_text::size()
{
	return line_count;
}