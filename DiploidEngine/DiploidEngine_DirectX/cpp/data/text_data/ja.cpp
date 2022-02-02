#include "data/text_data/ja.h"


void ja_text::OnceLoad()
{
	//会話データの読み込み
	file_string_data.ReadOpen("text/jp/jp.txt");//ファイル読み込み

	while ((ProcessMessage() == 0) && (file_string_data.GetFileInAdr()))
	{
		string_data.push_back(file_string_data.GetLine());//ファイルから一行読み込みんで一時保存
	}

	file_string_data.Close();//ファイルを閉じる


	//会話データと画像データの紐づけデータの読み込み
	file_scene_data.ReadOpen("texter/novel/scene_connect.txt");//ファイル読み込み

	while ((ProcessMessage() == 0) && (file_scene_data.GetFileInAdr()))
	{
		scene_name_data.push_back(file_scene_data.GetLine());//ファイルから一行読み込みんで一時保存
	}

	file_scene_data.Close();//ファイルを閉じる

}

void ja_text::Create()
{
	//紐づけデータの初期化
	//scene_number.clear();
	//scene_name.clear();

	//会話データの初期化
	//string.clear();
	//name.clear();

	font.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4, "メイリオ");//フォントを作成

	if ((scene_number.empty() && scene_name.empty() && string.empty() && name.empty()) == true)
	{
		//紐づけデータの文字列分割処理
		if (!scene_name_data.empty())
		{
			for (int count = 0; count != scene_name_data.size() - 1; count++)
			{
				std::string scene_name_buffer;
				int scene_number_buffer;

				trans.SplitString(scene_name_data[count], scene_number_buffer, scene_name_buffer);//文字列データを分割

				scene_number.push_back(scene_number_buffer - 2);//-2は会話データと配列の整合性を取るためとTXTファイルの空の行の分

				scene_name.push_back(scene_name_buffer);
			}
		}

		//会話データの文字列分割処理と紐づけデータのシーンへの紐づけ
		if (!string_data.empty())
		{
			int scene_count = 0;

			for (int count = 0; count != string_data.size() - 1; count++)
			{
				std::string name_buffer, string_buffer;

				trans.SplitString(string_data[count], name_buffer, string_buffer);//文字列データを分割


				string.push_back(DiploidStringV2::DiploidStringV2());//空のデータを追加

				name.push_back(DiploidStringV2::DiploidStringV2());//空のデータを追加


				name[count].CreateDXLIB(name_buffer, DX_CHARCODEFORMAT_SHIFTJIS);//名前データの保存

				string[count].CreateDXLIB(string_buffer, DX_CHARCODEFORMAT_SHIFTJIS);//名前に対する文字列データの保存


				//シーンの指定
				string[count].SetSceneName(scene_name.at(scene_count));

				//シーンを変える
				if (scene_count != scene_number.size() - 1)
				{
					if (count == scene_number.at(scene_count + 1))
					{
						scene_count++;
					}
				}
			}
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
			string[count].Reset();
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