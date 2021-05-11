#include "data/text_data/ja.h"

void ja_text::Load()
{
	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//フォントを作成
	
	data[0].Load("うるさい程の蝉の声が鳴り響く。");
	data[0].SetSceneName("abandoned_road");
	//data[1].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[1]);

	data[1].Load("なぜ自分はここにいるのか、どうやって来たのか、定かではない。\nただ一つ、確かなことは目の前にいる少女の言葉に耳を傾ける事だけだった。");
	data[1].SetSceneName("abandoned_road");
	//data[2].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[2]);

	data[2].Load("少女1\n「君は死後の世界を信じているかい？」");
	data[2].SetSceneName("abandoned_road");
	//data[3].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[3]);

	data[3].Load("主人公\n「......。」");
	data[3].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[4].Load("少女1\n「もし死後の世界が在るとすれば、そこはどんな世界なのだろうな。」");
	data[4].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[5].Load("主人公\n「......。」");
	data[5].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[6].Load("少女1\n「ふっ、すまないな。こんな話をして。」");
	data[6].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[7].Load("少女は軽く笑い、こちらの様子を伺うためか振り向く。");
	data[7].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[8].Load("その顔は申し訳なさそうな、そして哀しそうな表情をしていた。");
	data[8].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);

	data[9].Load("少女1\n「そんな顔をしないでくれ。私まで哀しくなるじゃないか。」");
	data[9].SetSceneName("abandoned_road");
	//data[4].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
	//string.push_back(data[4]);


	//上記のデータを配列にpush
	for (int count = 0; count != 256; count++)
	{
		//data[count].Init(setting.window_x * x_scale, setting.window_y * y_scale, font.GetHandle());
		string.push_back(data[count]);
	}

	//再読み込み時の重複データの削除
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
