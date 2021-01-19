#include "data/text_data/ja.h"

void ja_text::Load()
{
	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//�t�H���g���쐬

	data[0].Load("�����Ȃ��ǂɑ傫�ȐU��q���v���|�����Ă����B");
	data[0].SetSceneName("clock");
	//data[0].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[0]);

	data[1].Load("�[���}�C�΂˂��瑗��ꂽ�͂��G�X�P�[�v�����g�ɓ`���A\n�U��q��h�炵�ă`�N�^�N�Ɖ���炷�B");
	data[1].SetSceneName("clock");
	//data[1].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[1]);

	data[2].Load("���Ԋu�̉������񋿂�����A���j���i�ށB");
	data[2].SetSceneName("clock");
	//data[2].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[2]);

	data[3].Load("???\n�u�v");
	data[3].SetSceneName("clock");
	//data[3].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[3]);

	data[4].Load("???\n�u�v");
	data[4].SetSceneName("clock");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	//��L�̃f�[�^��z���push
	for (int count = 0; count != 256; count++)
	{
		data[count].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
		string.push_back(data[count]);
	}


	/*
	SetUseASyncLoadFlag(FALSE);
	file_handle = FileRead_open("text/jp.txt");

	for (int count = 0; count != 2; count++)
	{
		FileRead_gets(string_data, 512, file_handle);

		data[0].Load(string_data);
		data[0].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
		string.push_back(data[0]);
	}

	FileRead_close(file_handle);
	SetUseASyncLoadFlag(TRUE);	
	*/
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