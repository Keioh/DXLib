#include "data/text_data/ja.h"

void ja_text::Load()
{
	font.CreateFontData(30, 5, DX_FONTTYPE_NORMAL);//�t�H���g���쐬


	data[0].Load("�Èł̒����_�����āA�l�C�̂Ȃ�����K���ɑ����Ă���B");
	data[0].Init(setting.window_x * 0.2f, setting.window_y * 0.7f, font.GetHandle());
	string.push_back(data[0]);

	data[1].Load("���͒N���瓦���Ă���̂��낤���B");
	data[1].Init(setting.window_x * 0.2f, setting.window_y * 0.7f, font.GetHandle());
	string.push_back(data[1]);

	data[2].Load("��̈Èł͐�̌����Ȃ����|�ƂȂ��ďP���|�����Ă���B");
	data[2].Init(setting.window_x * 0.2f, setting.window_y * 0.7f, font.GetHandle());
	string.push_back(data[2]);
}
