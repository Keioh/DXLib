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
	for (int count = 0; count != 512; count++)
	{
		load_string[count] = str[count];
	}
}

void DiploidStrings::Init(float x, float y, int new_font_handle)
{
	pos_x = x;
	pos_y = y;

	font_handle = new_font_handle;

	GetFontStateToHandle(&font_name, &size, &thick, font_handle);

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

void DiploidStrings::SetLineSpaceing(int space)
{
	line_spacing = space;
}


void DiploidStrings::Reset()
{
	string_all = 0;
	end_flag = 0;
	time = 0;
}

void DiploidStrings::AllIn()
{
	for (int count = 0; count != 512; count++)
	{
		string[count] = load_string[count];
	}

	end_flag = 1;
	string_all = 512;
}


int DiploidStrings::GetEnd()
{
	return end_flag;
}


void DiploidStrings::Draw()
{	
	if (load_string[string_all] != '\0')
	{
		if (string_all != 512)
		{
			time += next_speed;

			if (time > next_time)
			{
				string[string_all] = load_string[string_all];

				if (string[string_all] == '\0')
				{
					end_flag = 1;
				}

				string_all++;
				time = 0;
			}
		}
	}
	else
	{
		end_flag = 1;
	}

	DrawStringToHandle(pos_x, pos_y, string, GetColor(255, 255, 255), font_handle);


/*
	DrawStringToHandle(pos_x, pos_y, strings[0], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 0) + line_spacing, strings[1], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 1) + (line_spacing * 2), strings[2], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 2) + (line_spacing * 3), strings[3], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 3) + (line_spacing * 4), strings[4], GetColor(255, 255, 255), font_handle);
		
	DrawStringToHandle(pos_x, pos_y, load_strings[0], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 0) + line_spacing, load_strings[1], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 1) + (line_spacing * 2), load_strings[2], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 2) + (line_spacing * 3), load_strings[3], GetColor(255, 255, 255), font_handle);
	DrawStringToHandle(pos_x, pos_y + (size * 3) + (line_spacing * 4), load_strings[4], GetColor(255, 255, 255), font_handle);


	for (int count = 0; count <= line_count; count++)
	{
		DrawStringToHandle(pos_x, pos_y + (size * count), strings[count], GetColor(255, 255, 255), font_handle);
	}
*/

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "end %d", GetEnd());
	//DrawFormatString(0, 20, GetColor(255, 255, 255), "time %d", time);
	//DrawFormatString(0, 40, GetColor(255, 255, 255), "speed %d", next_speed);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "all %d", string_all);

}