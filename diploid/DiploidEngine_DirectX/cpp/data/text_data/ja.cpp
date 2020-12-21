#include "data/text_data/ja.h"

void ja_text::Load()
{
	font.CreateFontData(30, 5, DX_FONTTYPE_NORMAL);//フォントを作成


	data[0].Load("暗闇の中を垣分けて、人気のない道を必死に走っている。");
	data[0].Init(setting.window_x * 0.2f, setting.window_y * 0.7f, font.GetHandle());
	string.push_back(data[0]);

	data[1].Load("私は誰から逃げているのだろうか。");
	data[1].Init(setting.window_x * 0.2f, setting.window_y * 0.7f, font.GetHandle());
	string.push_back(data[1]);

	data[2].Load("夜の暗闇は先の見えない恐怖となって襲い掛かってくる。");
	data[2].Init(setting.window_x * 0.2f, setting.window_y * 0.7f, font.GetHandle());
	string.push_back(data[2]);
}
