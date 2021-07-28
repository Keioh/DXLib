#include "ver2.0/Graphics/DiploidStringV2.h"

int DiploidStringV2::CreateFontData(int Size, int Thick, int FontType, char* FontName)
{
	font_handle = CreateFontToHandle(FontName, Size, Thick, FontType);

	return font_handle;
}

int DiploidStringV2::GetHandle()
{
	return font_handle;
}


void DiploidStringV2::LoadFile(const char* str)
{
	Clear();

	int line_count = 0;

	file.ReadOpen(str);//ファイル読み込み。

	while ((ProcessMessage() == 0) && (file.GetFileInAdr()))
	{
		string_data = file.GetLine();//データを読み込む。
		//wide_character.push_back(std::vector<wstring>());//空のcharを追加
		character.push_back(std::vector<string>());//空のcharを追加

		//stringをwstringに変換
		int BufferSize = MultiByteToWideChar(CP_ACP, 0, string_data.c_str(), -1, (wchar_t*)NULL, 0);

		wchar_t* cpUCS2 = new wchar_t[BufferSize];

		MultiByteToWideChar(CP_ACP, 0, string_data.c_str(), -1, cpUCS2, BufferSize);

		std::wstring wide_string_data(cpUCS2, cpUCS2 + BufferSize - 1);

		delete[] cpUCS2;// バッファの破棄


		for (int count = 0; count != wide_string_data.size(); ++count)
		{
			wide_character.push_back(wide_string_data.substr(count, 1));

			//wstringからstringへの変換
			int wBufferSize = WideCharToMultiByte(CP_OEMCP, 0, wide_character.at(count).c_str(), -1, (char*)NULL, 0, NULL, NULL);

			// バッファの取得
			CHAR* cpMultiByte = new CHAR[wBufferSize];

			// wstring → SJIS
			WideCharToMultiByte(CP_OEMCP, 0, wide_character.at(count).c_str(), -1, cpMultiByte, wBufferSize, NULL, NULL);

			// stringの生成
			std::string non_wide_string_data(cpMultiByte, cpMultiByte + wBufferSize - 1);

			// バッファの破棄
			delete[] cpMultiByte;

			//string変換後の一文字データをプッシュ
			character.at(line_count).push_back(non_wide_string_data);
		}

		wide_character.clear();

		//character.push_back(std::vector<string>());//空のcharを追加

		line_count++;
	}

	file.Close();//ファイルを閉じる。
}

void DiploidStringV2::Create(std::string str)
{
	Clear();

	int line_count = 0;

	string_data = str;//データを読み込む。
	character.push_back(std::vector<string>());//空のcharを追加

	//stringをwstringに変換
	int BufferSize = MultiByteToWideChar(CP_ACP, 0, string_data.c_str(), -1, (wchar_t*)NULL, 0);

	wchar_t* cpUCS2 = new wchar_t[BufferSize];

	MultiByteToWideChar(CP_ACP, 0, string_data.c_str(), -1, cpUCS2, BufferSize);

	std::wstring wide_string_data(cpUCS2, cpUCS2 + BufferSize - 1);

	delete[] cpUCS2;// バッファの破棄


	for (int count = 0; count != wide_string_data.size(); ++count)
	{
		wide_character.push_back(wide_string_data.substr(count, 1));

		//wstringからstringへの変換
		int wBufferSize = WideCharToMultiByte(CP_OEMCP, 0, wide_character.at(count).c_str(), -1, (char*)NULL, 0, NULL, NULL);

		// バッファの取得
		CHAR* cpMultiByte = new CHAR[wBufferSize];

		// wstring → SJIS
		WideCharToMultiByte(CP_OEMCP, 0, wide_character.at(count).c_str(), -1, cpMultiByte, wBufferSize, NULL, NULL);

		// stringの生成
		std::string non_wide_string_data(cpMultiByte, cpMultiByte + wBufferSize - 1);

		// バッファの破棄
		delete[] cpMultiByte;

		//string変換後の一文字データをプッシュ
		character.at(0).push_back(non_wide_string_data);

		//アルファ値のプッシュ
		alpha.push_back(0);
	}

	wide_character.clear();
}

void DiploidStringV2::ChangeFont(int handle)
{
	font_handle = handle;

	GetFontStateToHandle(&font_name, &size, &thick, font_handle);
}

void DiploidStringV2::Init(float x, float y, int new_font_handle)
{
	master_position = VGet(x, y, 0);

	font_handle = new_font_handle;

	GetFontStateToHandle(&font_name, &size, &thick, font_handle);
}

void DiploidStringV2::Init(float x, float y)
{
	master_position = VGet(x, y, 0);
}

void DiploidStringV2::DrawFile(int line, float frame_time)
{
	if (!character.empty())
	{
		for (int count = 0; count != character.at(line).size(); count++)
		{
			DrawString(0 + (20 * count), 0 + (20 * 0), character.at(line).at(count).c_str(), GetColor(200, 200, 200));
		}
	}
}

void DiploidStringV2::Draw(float frame_time)
{
	int width = 0;

	if (!character.empty())
	{
		//文字のアルファ処理
		for (int count = 0; count != alpha.size(); count++)
		{
			alpha.at(0) += next_speed * frame_time;

			if (alpha.at(count) > (255 / 2))
			{
				if ((count + 1) >= alpha.size())
				{
					alpha.at(count) += next_speed * frame_time;
				}
				else
				{
					alpha.at(count + 1) += next_speed * frame_time;
				}
			}

			//数値の上下限設定
			if (alpha.at(count) > 255)
			{
				alpha.at(count) = 255;
			}

			if (alpha.at(count) < 0)
			{
				alpha.at(count) = 0;
			}
		}

		//文字の表示
		for (int count = 0; count != character.at(0).size(); count++)
		{
			width = GetDrawStringWidthToHandle(character.at(0).at(0).c_str(), strlen(character.at(0).at(count).c_str()), font_handle) + width;

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha.at(count));
			DrawStringToHandle(master_position.x + width, master_position.y, character.at(0).at(count).c_str(), GetColor(200, 200, 200), font_handle);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		}

		//描画終わりのフラグ処理
		if (alpha.at(alpha.size() - 1) >= 255)
		{
			end_flag = 1;
			complete = true;
		}
	}

	//DrawFormatString(0, 60, GetColor(0, 0, 0), "%d", GetDrawStringWidthToHandle(character.at(0).at(0).c_str(), strlen(character.at(0).at(0).c_str()), font_handle));
}

void DiploidStringV2::Clear()
{
	if (!character.empty())
	{
		character.clear();
	}

	if (!wide_character.empty())
	{
		wide_character.clear();
	}

	if (!string_data.empty())
	{
		string_data.clear();
	}

	if (!alpha.empty())
	{
		alpha.clear();
	}
}


std::string DiploidStringV2::GetSceneName()
{
	return scene_number;
}

void DiploidStringV2::SetSceneName(std::string name)
{
	scene_number = name;
}

void DiploidStringV2::SetColor(unsigned int new_color)
{
	color = new_color;
}

float DiploidStringV2::GetDrawSpeed()
{
	return next_speed;
}

void DiploidStringV2::SetSpeed(float speed)
{
	next_speed = speed;
}

void DiploidStringV2::AllIn()
{
	for (int count = 0; count != alpha.size(); count++)
	{
		alpha.at(count) = 255;
	}

	end_flag = 1;
}

bool DiploidStringV2::GetCompleteFlag()
{
	return complete;
}

void DiploidStringV2::SetCompleteFlag(bool new_flag)
{
	complete = new_flag;
}

void DiploidStringV2::Reset()
{
	for (int count = 0; count != alpha.size(); count++)
	{
		alpha.at(count) = 0;
	}

	end_flag = 0;
}

int DiploidStringV2::GetEnd()
{
	return end_flag;
}