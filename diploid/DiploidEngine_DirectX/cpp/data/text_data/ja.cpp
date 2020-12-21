#include "data/text_data/ja.h"

void ja_text::Load()
{
	font.CreateFontData(30, 5, DX_FONTTYPE_NORMAL);
	for (int count = 0; count != 256; count++)
	{
		data[count].ChangeFont(font.GetHandle());
	}

	data[0].Load("�Èł̒��𑖂��Ă���B\n�l�C�̂Ȃ�����\n�i���Ƒ����Ă����B");
	string.push_back(data[0]);

	data[1].Load("���͒N���瓦���Ă���̂��낤���B");
	string.push_back(data[1]);

	data[2].Load("��̈Èł͐�̌����Ȃ����|�ƂȂ��ďP���|����B");
	string.push_back(data[2]);
}
