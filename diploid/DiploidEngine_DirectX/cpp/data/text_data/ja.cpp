#include "data/text_data/ja.h"


void ja_text::OnceLoad()
{
	file.ReadOpen("text/jp/jp.txt");//ファイル読み込み

	while ((ProcessMessage() == 0) && (file.GetFileInAdr()))
	{
		string_data.push_back(file.GetLine());//ファイルから一行読み込みんで一時保存
	}

	file.FileInClose();//ファイルを閉じる
}

void ja_text::Create()
{
	string.clear();
	name.clear();

	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//フォントを作成


	if (!string_data.empty())
	{
		for (int count = 0; count != string_data.size() - 1; count++)
		{
			std::string one, two;

			trans.SplitString(string_data[count], one, two);//文字列データを分割


			string.push_back(DiploidStringV2::DiploidStringV2());//空のデータを追加

			name.push_back(DiploidStringV2::DiploidStringV2());//空のデータを追加


			name[count].Create(one);//名前データの保存

			string[count].Create(two);//名前に対する文字列データの保存


			//背景画像の指定(将来はこの処理はコメントアウト)
			string[count].SetSceneName("abandoned_road");
		}
	}
}

void ja_text::StringInit(DiploidEngineSetting& setting)
{
	if (!string.empty())
	{
		for (int count = 0; count != string.size(); count++)
		{
			string[count].Init(setting.GetSystemData().window_x * x_scale, setting.GetSystemData().window_y - y_scale, font.GetFontInfo());
			string[count].SetWidth(setting.GetSystemData().window_x * 0.65f);//表示幅を設定。
		}
	}
}

void ja_text::NameInit(DiploidEngineSetting& setting)
{
	if (!name.empty())
	{
		for (int count = 0; count != name.size(); count++)
		{
			name[count].Init(setting.GetSystemData().window_x * (x_scale - 0.03f), setting.GetSystemData().window_y - (y_scale + (font.GetFontInfo().size * 1.25f)), font.GetFontInfo());
			name[count].SetWidth(setting.GetSystemData().window_x * 0.65f);//表示幅を設定。
		}
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

	if (!name.empty())
	{
		for (int count = 0; count != name.size(); count++)
		{		
			name[count].SetSpeed(new_speed);
		}
	}
}

void ja_text::Reset()
{
	if (!string.empty())
	{
		for (int count = 0; count != string.size(); count++)
		{
			name[count].Reset();
		}
	}

	if (!name.empty())
	{
		for (int count = 0; count != name.size(); count++)
		{
			name[count].Reset();
		}
	}
}

int ja_text::size()
{
	return string.size();
}