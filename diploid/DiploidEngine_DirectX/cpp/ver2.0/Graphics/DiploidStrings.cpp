#include "ver2.0/Graphics/DiploidStrings.h"


int DiploidStrings::CreateFontData(int Size, int Thick, int FontType, char *FontName)
{
	font_handle = CreateFontToHandle(FontName, Size, Thick, FontType);

	return font_handle;
}

int DiploidStrings::GetHandle()
{
	return font_handle;
}

void DiploidStrings::Load(const char* str)
{	
	for (int count = 0; count != 256; count++)
	{
		if (str[word_count] == '\n')
		{	
			//count++;
			count = 0;
			line++;
		}

		load_strings[line][count] = str[word_count];

		word_count++;
	}

	word_count = 0;
	line = 0;
}

void DiploidStrings::Init(float x, float y, int new_font_handle)
{
	pos_x = x;
	pos_y = y;

	font_handle = new_font_handle;
}

void DiploidStrings::Init(float x, float y)
{
	pos_x = x;
	pos_y = y;
}


void DiploidStrings::ChangeFont(int handle)
{
	font_handle = handle;

	GetFontStateToHandle(&font_name, &size, &thick, font_handle);
}


void DiploidStrings::SetSpeed(int speed)
{
	next_speed = speed;
}

void DiploidStrings::Reset()
{
	count = 0;
	next_time = 0;

	//for (int count_str = 0; count_str != 256; count_str++)
	{
		//strings[count] = 0;
	}
}

int DiploidStrings::GetEnd()
{
	if (line == 6)
	{
		end_flag = 1;
	}
	else
	{
		end_flag = 0;
	}

	return end_flag;
}


void DiploidStrings::Draw(float x, float y)
{
	pos_x = x;
	pos_y = y;
	
	if (count != 256)
	{
		strings[line][count] = load_strings[line][count];//文字列の移し替え。

		next_time++;//アニメーションを進める。

		if (next_time > next_speed)
		{
			count++;//文字を進める。

			next_time = 0;//アニメーションの時間をリセット
		}

		if (load_strings[line][count] == '\0')//読み込んだ現在位置の文字列が\0なら
		{
			if (line != 6)
			{
				line++;//行を進める
			}

			count = 0;//最前列に移動
		}
	}
	

	GetFontStateToHandle(NULL, &size, NULL, font_handle);

	DrawStringToHandle(pos_x, pos_y, strings[0], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 0), strings[1], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 1), strings[2], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 2), strings[3], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 3), strings[4], GetColor(255, 255, 255), font_handle);


	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", GetEnd());
	//DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", count);
	//DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", line);

}