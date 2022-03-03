#include "data/text_data/ja.h"


void ja_text::OnceLoad()
{
	//��b�f�[�^�̓ǂݍ���
	file_string_data.ReadOpen("text/jp/jp.txt");//�t�@�C���ǂݍ���

	while ((ProcessMessage() == 0) && (file_string_data.GetFileInAdr()))
	{
		string_data.push_back(file_string_data.GetLine());//�t�@�C�������s�ǂݍ��݂�ňꎞ�ۑ�
	}

	file_string_data.Close();//�t�@�C�������


	//��b�f�[�^�Ɖ摜�f�[�^�̕R�Â��f�[�^�̓ǂݍ���
	file_scene_data.ReadOpen("texter/novel/scene_connect.txt");//�t�@�C���ǂݍ���

	while ((ProcessMessage() == 0) && (file_scene_data.GetFileInAdr()))
	{
		scene_name_data.push_back(file_scene_data.GetLine());//�t�@�C�������s�ǂݍ��݂�ňꎞ�ۑ�
	}

	file_scene_data.Close();//�t�@�C�������

}

void ja_text::Create()
{
	//�R�Â��f�[�^�̏�����
	//scene_number.clear();
	//scene_name.clear();

	//��b�f�[�^�̏�����
	//string.clear();
	//name.clear();

	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4, "���C���I");//�t�H���g���쐬

	if ((scene_number.empty() && scene_name.empty() && string.empty() && name.empty()) == true)
	{
		//�R�Â��f�[�^�̕����񕪊�����
		if (!scene_name_data.empty())
		{
			for (int count = 0; count != scene_name_data.size() - 1; count++)
			{
				std::string scene_name_buffer;
				int scene_number_buffer;

				trans.SplitString(scene_name_data[count], scene_number_buffer, scene_name_buffer);//������f�[�^�𕪊�

				scene_number.push_back(scene_number_buffer - 2);//-2�͉�b�f�[�^�Ɣz��̐���������邽�߂�TXT�t�@�C���̋�̍s�̕�

				scene_name.push_back(scene_name_buffer);
			}
		}

		//��b�f�[�^�̕����񕪊������ƕR�Â��f�[�^�̃V�[���ւ̕R�Â�
		if (!string_data.empty())
		{
			int scene_count = 0;

			for (int count = 0; count != string_data.size() - 1; count++)
			{
				std::string name_buffer, string_buffer;

				trans.SplitString(string_data[count], name_buffer, string_buffer);//������f�[�^�𕪊�


				string.push_back(DiploidStringV2::DiploidStringV2());//��̃f�[�^��ǉ�

				name.push_back(DiploidStringV2::DiploidStringV2());//��̃f�[�^��ǉ�


				name[count].CreateDXLIB(name_buffer, DX_CHARCODEFORMAT_SHIFTJIS);//���O�f�[�^�̕ۑ�

				string[count].CreateDXLIB(string_buffer, DX_CHARCODEFORMAT_SHIFTJIS);//���O�ɑ΂��镶����f�[�^�̕ۑ�


				//�V�[���̎w��
				string[count].SetSceneName(scene_name.at(scene_count));

				//�V�[����ς���
				if (scene_count != scene_number.size() - 1)
				{
					if (count == scene_number.at(scene_count + 1))
					{
						scene_count++;
					}
				}
			}
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