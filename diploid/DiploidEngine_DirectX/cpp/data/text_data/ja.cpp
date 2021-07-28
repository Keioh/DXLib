#include "data/text_data/ja.h"

void ja_text::Load()
{
	//for (int count = 0; count != string_data_line; ++count)
	//{
	//	string[count].Clear();
	//}

	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//フォントを作成
		
	string[0].Create("なぜ自分はここにいるのか、どうやって来たのか、定かではない。ただ一つ、確かなことは目の前にいる少女の言葉に耳を傾ける事だけだった。");
	string[0].SetSceneName("abandoned_road");

	string[1].Create("「君は死後の世界を信じているかい？」");
	string[1].SetSceneName("abandoned_road");

	string[2].Create("「......。」");
	string[2].SetSceneName("abandoned_road");

}

void ja_text::Init(DiploidEngineSetting& setting)
{
	//if (!string.empty())
	{
		for (int count = 0; count != string_data_line; count++)
		{
			string[count].Init(setting.GetSystemData().window_x * x_scale, setting.GetSystemData().window_y - y_scale, font.GetHandle());
		}
	}
}

void ja_text::SetSpeed(int new_speed)
{
	//if (!string.empty())
	{
		for (int count = 0; count != string_data_line; count++)
		{
			string[count].SetSpeed(new_speed);
		}
	}
}

void ja_text::Reset()
{
	//if (!string.empty())
	{
		for (int count = 0; count != string_data_line; count++)
		{
			string[count].Reset();
		}
	}
}

int ja_text::size()
{
	return string_data_line;
}