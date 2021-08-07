#include "data/text_data/ja.h"

void ja_text::Load()
{
	string.clear();

	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//�t�H���g���쐬
		
	string.push_back(DiploidStringV2::DiploidStringV2());
	string[0].Create("�Ȃ������͂����ɂ���̂��A�ǂ�����ė����̂��A�肩�ł͂Ȃ��B������A�m���Ȃ��Ƃ͖ڂ̑O�ɂ��鏭���̌��t�Ɏ����X���鎖�����������B");
	string[0].SetSceneName("abandoned_road");

	string.push_back(DiploidStringV2::DiploidStringV2());
	string[1].Create("�u�N�͎���̐��E��M���Ă��邩���H�v");
	string[1].SetSceneName("abandoned_road");

	string.push_back(DiploidStringV2::DiploidStringV2());
	string[2].Create("�u�v");
	string[2].SetSceneName("abandoned_road");

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
	return string.size();
}