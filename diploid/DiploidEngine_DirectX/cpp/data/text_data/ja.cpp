#include "data/text_data/ja.h"


void ja_text::OnceLoad()
{
	file.ReadOpen("text/jp/jp.txt");//�t�@�C���ǂݍ���

	while ((ProcessMessage() == 0) && (file.GetFileInAdr()))
	{
		string_data.push_back(file.GetLine());//�t�@�C�������s�ǂݍ��݂�ňꎞ�ۑ�
	}

	file.FileInClose();//�t�@�C�������
}

void ja_text::Create()
{
	string.clear();
	name.clear();

	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4, "���C���I");//�t�H���g���쐬


	if (!string_data.empty())
	{
		for (int count = 0; count != string_data.size() - 1; count++)
		{
			std::string one, two;

			trans.SplitString(string_data[count], one, two);//������f�[�^�𕪊�


			string.push_back(DiploidStringV2::DiploidStringV2());//��̃f�[�^��ǉ�

			name.push_back(DiploidStringV2::DiploidStringV2());//��̃f�[�^��ǉ�


			name[count].CreateDXLIB(one, DX_CHARCODEFORMAT_SHIFTJIS);//���O�f�[�^�̕ۑ�

			string[count].CreateDXLIB(two, DX_CHARCODEFORMAT_SHIFTJIS);//���O�ɑ΂��镶����f�[�^�̕ۑ�


			//�w�i�摜�̎w��(�����͂��̏����͎���������)
			string[count].SetSceneName("cafe");
		}
	}
}

void ja_text::StringInit(DiploidEngineSetting& setting)
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

void ja_text::NameInit(DiploidEngineSetting& setting)
{
	if (!name.empty())
	{
		for (int count = 0; count != name.size(); count++)
		{
			name[count].Init(setting.GetSystemData().window_x * (x_scale - 0.03f), setting.GetSystemData().window_y - (y_scale + (font.GetFontInfo().size * 1.25f)), font.GetFontInfo());
			name[count].SetWidth(setting.GetSystemData().window_x * 0.65f);//�\������ݒ�B
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

	if (!name.empty())
	{
		for (int count = 0; count != name.size(); count++)
		{		
			name[count].SetSpeed(new_speed);
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

	if (!name.empty())
	{
		for (int count = 0; count != name.size(); count++)
		{
			name[count].Reset();
		}
	}
}

int ja_text::size()
{
	return string.size();
}