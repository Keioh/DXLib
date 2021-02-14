#include "data/text_data/ja.h"

void ja_text::Load()
{
	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//�t�H���g���쐬
	
	data[0].Load("�̂̐l�͒n�k�◒�Ƃ��������R���ۂɈؕ|�����߂āA\n�����̎��ۂɁu�_(Kami)�v���h��Ƃ����M�������Ă����B");
	data[0].SetSceneName("clock");
	//data[0].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[0]);

	data[1].Load("�₪�Đl�X�͂�����u���S���̐_�v�ƌĂԂ悤�ɂȂ�A\n���݂Ɏ���܂ł��̐M�͑����Ă���B");
	data[1].SetSceneName("clock");
	//data[1].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[1]);

	data[2].Load("");
	data[2].SetSceneName("clock");
	//data[2].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[2]);

	data[3].Load("");
	data[3].SetSceneName("clock");
	//data[3].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[3]);

	data[4].Load("");
	data[4].SetSceneName("clock");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);



	//��L�̃f�[�^��z���push
	for (int count = 0; count != 256; count++)
	{
		//data[count].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
		string.push_back(data[count]);
	}

	if (string.size() > 256)
	{
		string.erase(string.begin(), string.begin() + 256);
	}
/*
	//�t�@�C���ǂݍ���	
	file.Load("text/jp.txt");

	SetUseASyncLoadFlag(FALSE);
	//file_handle = FileRead_open("text/jp.txt");

	for (int count = 0; count != file.data.size(); count++)
	{
		//FileRead_gets(string_data, 512, file_handle);

		data[count].Load(&file.data[count]);
		data[count].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
		string.push_back(data[count]);
	}

	//FileRead_close(file_handle);
	SetUseASyncLoadFlag(TRUE);
*/

}

void ja_text::Init(DiploidEngineSetting& setting)
{
	for (int count = 0; count != 256; count++)
	{
		string[count].Init(setting.window_x * x_scale, setting.window_y - y_scale, font.GetHandle());
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
