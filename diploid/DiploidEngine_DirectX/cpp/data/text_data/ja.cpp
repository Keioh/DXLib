#include "data/text_data/ja.h"

void ja_text::Load()
{
	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//フォントを作成

	data[0].Load("青く光るPCのディスプレイが灯りの無い部屋を照らす。");	
	//data[0].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[0]);

	data[1].Load("ディスプレイの両端にはコンポに使われるスピーカーが置かれ、\nそこからはドビュッシーのピアノ曲が流れている。");
	//data[1].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[1]);

	data[2].Load("深緑色の少女\n「......ん。」");
	//data[2].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[2]);

	data[3].Load("???\n「」");
	//data[3].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[3]);

	data[4].Load("???\n「」");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);


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