#include "data/text_data/ja.h"

void ja_text::Load()
{
	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//フォントを作成

	data[0].Load("???\n「......。」");	
	//data[0].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[0]);

	data[1].Load("???\n「......あっ。」");
	//data[1].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[1]);

	data[2].Load("???\n「」");
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
