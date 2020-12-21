#include "data/text_data/ja.h"

void ja_text::Load()
{
	font.CreateFontData(30, 5, DX_FONTTYPE_NORMAL);
	for (int count = 0; count != 256; count++)
	{
		data[count].ChangeFont(font.GetHandle());
	}

	data[0].Load("暗闇の中を走っている。\n人気のない道を\n永遠と走っていた。");
	string.push_back(data[0]);

	data[1].Load("私は誰から逃げているのだろうか。");
	string.push_back(data[1]);

	data[2].Load("夜の暗闇は先の見えない恐怖となって襲い掛かる。");
	string.push_back(data[2]);
}
