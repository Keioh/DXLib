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
	for (int count_str = 0; count_str != 128; count_str++)
	{
		load_strings[count_str] = str[count_str];
	}
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
}


void DiploidStrings::SetSpeed(int speed)
{
	next_speed = speed;
}

void DiploidStrings::Reset()
{
	count = 0;
	next_time = 0;
}


void DiploidStrings::Draw(float x, float y)
{
	pos_x = x;
	pos_y = y;

	if (count != 128)
	{
		strings[count] = load_strings[count];

		DrawStringToHandle(pos_x, pos_y, strings, GetColor(255, 255, 255), font_handle);

		next_time++;

		if (next_time > next_speed)
		{
			count++;
			next_time = 0;
		}
	}
	else
	{
		DrawStringToHandle(pos_x, pos_y, strings, GetColor(255, 255, 255), font_handle);
	}
}

void DiploidStrings::DrawStrings(int x, int y, const char* str)
{
	if (count != 128)
	{
		strings[count] = str[count];

		DrawString(x, y, strings, GetColor(255, 255, 255));

		next_time++;

		if (next_time > next_speed)
		{
			count++;
			next_time = 0;
		}
	}
	else
	{
		DrawStringToHandle(pos_x, pos_y, strings, GetColor(255, 255, 255), font_handle);
	}
}