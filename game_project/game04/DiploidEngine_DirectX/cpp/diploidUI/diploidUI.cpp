#include "diploidUI/diploidUI.h"

DiploidUI::DiploidUI()
{

}

DiploidUI::~DiploidUI()
{

}

//ワンクリックボタン
void DiploidUI::OneClickButtonBOX_Load(const char* path, int size_x, int size_y)
{
	image.Load(path);
	image_size = VGet(size_x, size_y, 0.0f);
}

void DiploidUI::OneClickButtonBOX_Load(const char* path_1, const char* path_2, const char* path_3, int size_x, int size_y)//ワンクリックボタンの読み込み処理(3つ)
{
	image.Load(path_1);
	image_size = VGet(size_x, size_y, 0.0f);

	image_1.Load(path_2);
	image_size_1 = VGet(size_x, size_y, 0.0f);

	image_2.Load(path_3);
	image_size_2 = VGet(size_x, size_y, 0.0f);

}

void DiploidUI::OneClickButtonBOX_Init(VECTOR position, VECTOR size, std::string name_tag, int layer_number)
{
	box.Init(position, size);
	box.name_tag = name_tag;
	box.layer_number = layer_number;

	image.Init(VGet(position.x + (image_size.x / 2), position.y + (image_size.y / 2), 0.0f));
	image_1.Init(VGet(position.x + (image_size.x / 2), position.y + (image_size.y / 2), 0.0f));
	image_2.Init(VGet(position.x + (image_size.x / 2), position.y + (image_size.y / 2), 0.0f));
	image_3.Init(VGet(position.x + (image_size.x / 2), position.y + (image_size.y / 2), 0.0f));
}

void DiploidUI::OneClickButtonBOX_Push(DiploidEngineImpact& impact)
{
	impact.PushBox(box);
}

bool DiploidUI::OneClickButtonBOX_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	input.Update();
	box.color = GetColor(150, 150, 150);

	bright_one = true;
	bright_two = false;
	bright_three = false;

	if (impact.GetBoxImpactFlag_Sreach_Name_Tag(box.name_tag) == true)
	{
		box.color = GetColor(180, 180, 180);

		bright_one = false;
		bright_two = true;
		bright_three = false;

		button_hit_flag = true;

		if (input.GetPressMouse(mouse_input_button_type) == true)
		{
			box.color = GetColor(200, 200, 200);

			bright_one = false;
			bright_two = false;
			bright_three = true;

			return true;
		}
	}
	else
	{
		button_hit_flag = false;
	}

	return false;
}

void DiploidUI::OneClickButtonBOX_Draw(int image_number, bool image_draw, bool draw)
{
	//抽象画の表示
	if (draw == true)
	{
		box.fill = TRUE;
		box.Draw();
	}

	//画像の表示
	if (image_draw == true)
	{
		//触れていないときの明るさ(一番暗い)
		if (bright_one == true)
		{
			image.blue_bright = 255 * 0.6f;
			image.red_bright = 255 * 0.6f;
			image.green_bright = 255 * 0.6f;

			image_1.blue_bright = 255 * 0.6f;
			image_1.red_bright = 255 * 0.6f;
			image_1.green_bright = 255 * 0.6f;

			image_2.blue_bright = 255 * 0.6f;
			image_2.red_bright = 255 * 0.6f;
			image_2.green_bright = 255 * 0.6f;

			image_3.blue_bright = 255 * 0.6f;
			image_3.red_bright = 255 * 0.6f;
			image_3.green_bright = 255 * 0.6f;

			if (image_number == 0)
			{
				image.Draw(image_draw);
			}

			if (image_number == 1)
			{
				image_1.Draw(image_draw);
			}

			if (image_number == 2)
			{
				image_2.Draw(image_draw);
			}

			if (image_number == 3)
			{
				image_3.Draw(image_draw);
			}

			image.blue_bright = 255;
			image.red_bright = 255;
			image.green_bright = 255;

			image_1.blue_bright = 255;
			image_1.red_bright = 255;
			image_1.green_bright = 255;

			image_2.blue_bright = 255;
			image_2.red_bright = 255;
			image_2.green_bright = 255;

			image_3.blue_bright = 255;
			image_3.red_bright = 255;
			image_3.green_bright = 255;

		}

		//触れているときの明るさ(暗い)
		if (bright_two == true)
		{
			image.blue_bright = 255 * 0.8f;
			image.red_bright = 255 * 0.8f;
			image.green_bright = 255 * 0.8f;

			image_1.blue_bright = 255 * 0.8f;
			image_1.red_bright = 255 * 0.8f;
			image_1.green_bright = 255 * 0.8f;

			image_2.blue_bright = 255 * 0.8f;
			image_2.red_bright = 255 * 0.8f;
			image_2.green_bright = 255 * 0.8f;

			image_3.blue_bright = 255 * 0.8f;
			image_3.red_bright = 255 * 0.8f;
			image_3.green_bright = 255 * 0.8f;

			if (image_number == 0)
			{
				image.Draw(image_draw);
			}

			if (image_number == 1)
			{
				image_1.Draw(image_draw);
			}

			if (image_number == 2)
			{
				image_2.Draw(image_draw);
			}

			if (image_number == 3)
			{
				image_3.Draw(image_draw);
			}

			image.blue_bright = 255;
			image.red_bright = 255;
			image.green_bright = 255;

			image_1.blue_bright = 255;
			image_1.red_bright = 255;
			image_1.green_bright = 255;

			image_2.blue_bright = 255;
			image_2.red_bright = 255;
			image_2.green_bright = 255;

			image_3.blue_bright = 255;
			image_3.red_bright = 255;
			image_3.green_bright = 255;

		}

		//クリックとフラグがオンのときの明るさ(明度マックス)
		if (bright_three == true || button_flag == true)
		{
			image.blue_bright = 255;
			image.red_bright = 255;
			image.green_bright = 255;

			image_1.blue_bright = 255;
			image_1.red_bright = 255;
			image_1.green_bright = 255;

			image_2.blue_bright = 255;
			image_2.red_bright = 255;
			image_2.green_bright = 255;

			image_3.blue_bright = 255;
			image_3.red_bright = 255;
			image_3.green_bright = 255;

			if (image_number == 0)
			{
				image.Draw(image_draw);
			}

			if (image_number == 1)
			{
				image_1.Draw(image_draw);
			}

			if (image_number == 2)
			{
				image_2.Draw(image_draw);
			}

			if (image_number == 3)
			{
				image_3.Draw(image_draw);
			}

			image.blue_bright = 255;
			image.red_bright = 255;
			image.green_bright = 255;

			image_1.blue_bright = 255;
			image_1.red_bright = 255;
			image_1.green_bright = 255;

			image_2.blue_bright = 255;
			image_2.red_bright = 255;
			image_2.green_bright = 255;

			image_3.blue_bright = 255;
			image_3.red_bright = 255;
			image_3.green_bright = 255;
		}
	}
}

bool DiploidUI:: GetOneClickButton_HitFlag()
{
	return button_hit_flag;
}


//ワンクリックボタン(押してすぐに元に戻るボタン)
void DiploidUI::OneClickButtonCIRCLE_Init(VECTOR position, float radius, std::string name_tag, int layer_number)
{
	circle.Init(position, radius);
	circle.name_tag = name_tag;
	circle.layer_number = layer_number;
}

void DiploidUI::OneClickButtonCIRCLE_Push(DiploidEngineImpact& impact)
{
	impact.PushCircle(circle);
}

void DiploidUI::OneClickButtonCIRCLE_Load(const char* path, int size_x, int size_y)
{
}

bool DiploidUI::OneClickButtonCIRCLE_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	input.Update();
	circle.color = GetColor(150, 150, 150);

	if (impact.GetCircleImpactFlag_Sreach_Name_Tag(circle.name_tag) == true)
	{
		circle.color = GetColor(180, 180, 180);

		if (input.GetPressMouse(mouse_input_button_type) == true)
		{
			circle.color = GetColor(200, 200, 200);

			return true;
		}
	}

	return false;
}

void DiploidUI::OneClickButtonCIRCLE_Draw()
{
	circle.fill = TRUE;
	circle.Draw();
}


//ワンクリックボタン箱(押すとオンオフ切り替わるボタン)
void DiploidUI::SwitchButtonBOX_Init(VECTOR position, VECTOR size, std::string name_tag, int layer_number)
{
	box.Init(position, size);
	box.name_tag = name_tag;
	box.layer_number = layer_number;

	image.Init(VGet(position.x + (image_size.x / 2), position.y + (image_size.y / 2), 0.0f));
	image_1.Init(VGet(position.x + (image_size.x / 2), position.y + (image_size.y / 2), 0.0f));
	image_2.Init(VGet(position.x + (image_size.x / 2), position.y + (image_size.y / 2), 0.0f));
	image_3.Init(VGet(position.x + (image_size.x / 2), position.y + (image_size.y / 2), 0.0f));
}

void DiploidUI::SwitchButtonBOX_Push(DiploidEngineImpact& impact)
{
	impact.PushBox(box);
}

void DiploidUI::SwitchButtonBOX_Load(const char* path, int size_x, int size_y)
{
	image.Load(path);
	image_size = VGet(size_x, size_y, 0.0f);
}

void DiploidUI::SwitchButtonBOX_Load(const char* path_1, const char* path_2, const char* path_3, int size_x, int size_y)//スイッチボタンの読み込み処理(3つ)
{
	image.Load(path_1);
	image_size = VGet(size_x, size_y, 0.0f);

	image_1.Load(path_2);
	image_size_1 = VGet(size_x, size_y, 0.0f);

	image_2.Load(path_3);
	image_size_2 = VGet(size_x, size_y, 0.0f);
}

void DiploidUI::SwitchButtonBOX_Load(const char* path_1, const char* path_2, const char* path_3, const char* path_4, int size_x, int size_y)//スイッチボタンの読み込み処理(複数)
{
	image.Load(path_1);
	image_size = VGet(size_x, size_y, 0.0f);

	image_1.Load(path_2);
	image_size_1 = VGet(size_x, size_y, 0.0f);

	image_2.Load(path_3);
	image_size_2 = VGet(size_x, size_y, 0.0f);

	image_3.Load(path_4);
	image_size_3 = VGet(size_x, size_y, 0.0f);
}

bool DiploidUI::SwitchButtonBOX_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	input.Update();
	box.color = GetColor(150, 150, 150);

	bright_one = true;
	bright_two = false;
	bright_three = false;

	if (impact.GetBoxImpactFlag_Sreach_Name_Tag(box.name_tag) == true)
	{
		box.color = GetColor(180, 180, 180);

		bright_one = false;
		bright_two = true;
		bright_three = false;

		button_hit_flag = true;

		if (input.GetPressMouse(mouse_input_button_type) == true)
		{
			box.color = GetColor(200, 200, 200);

			bright_one = false;
			bright_two = false;
			bright_three = true;

			//button_flagがfalseなら
			if (button_flag == false)
			{
				button_flag = true;	

				return button_flag;
			}
			else
			{
				button_flag = false;
				return button_flag;
			}
		}
	}
	else
	{
		button_hit_flag = false;
	}

	return button_flag;
}

void DiploidUI::SwitchButtonBOX_Draw(int image_number, bool image_draw, bool draw)
{
	//抽象画の表示
	if (draw == true)
	{
		box.fill = TRUE;
		box.Draw();
	}

	//画像の表示
	if (image_draw == true)
	{
		//触れていないときの明るさ(一番暗い)
		if (bright_one == true)
		{
			image.blue_bright = 255 * 0.6f;
			image.red_bright = 255 * 0.6f;
			image.green_bright = 255 * 0.6f;

			image_1.blue_bright = 255 * 0.6f;
			image_1.red_bright = 255 * 0.6f;
			image_1.green_bright = 255 * 0.6f;

			image_2.blue_bright = 255 * 0.6f;
			image_2.red_bright = 255 * 0.6f;
			image_2.green_bright = 255 * 0.6f;

			image_3.blue_bright = 255 * 0.6f;
			image_3.red_bright = 255 * 0.6f;
			image_3.green_bright = 255 * 0.6f;

			if (image_number == 0)
			{
				image.Draw(image_draw);
			}

			if (image_number == 1)
			{
				image_1.Draw(image_draw);
			}

			if (image_number == 2)
			{
				image_2.Draw(image_draw);
			}	
			
			if (image_number == 3)
			{
				image_3.Draw(image_draw);
			}

			image.blue_bright = 255;
			image.red_bright = 255;
			image.green_bright = 255;

			image_1.blue_bright = 255;
			image_1.red_bright = 255;
			image_1.green_bright = 255;

			image_2.blue_bright = 255;
			image_2.red_bright = 255;
			image_2.green_bright = 255;

			image_3.blue_bright = 255;
			image_3.red_bright = 255;
			image_3.green_bright = 255;

		}

		//触れているときの明るさ(暗い)
		if (bright_two == true)
		{
			image.blue_bright = 255 * 0.8f;
			image.red_bright = 255 * 0.8f;
			image.green_bright = 255 * 0.8f;

			image_1.blue_bright = 255 * 0.8f;
			image_1.red_bright = 255 * 0.8f;
			image_1.green_bright = 255 * 0.8f;

			image_2.blue_bright = 255 * 0.8f;
			image_2.red_bright = 255 * 0.8f;
			image_2.green_bright = 255 * 0.8f;

			image_3.blue_bright = 255 * 0.8f;
			image_3.red_bright = 255 * 0.8f;
			image_3.green_bright = 255 * 0.8f;

			if (image_number == 0)
			{
				image.Draw(image_draw);
			}

			if (image_number == 1)
			{
				image_1.Draw(image_draw);
			}

			if (image_number == 2)
			{
				image_2.Draw(image_draw);
			}

			if (image_number == 3)
			{
				image_3.Draw(image_draw);
			}

			image.blue_bright = 255;
			image.red_bright = 255;
			image.green_bright = 255;

			image_1.blue_bright = 255;
			image_1.red_bright = 255;
			image_1.green_bright = 255;

			image_2.blue_bright = 255;
			image_2.red_bright = 255;
			image_2.green_bright = 255;

			image_3.blue_bright = 255;
			image_3.red_bright = 255;
			image_3.green_bright = 255;

		}

		//クリックとフラグがオンのときの明るさ(明度マックス)
		if (bright_three == true || button_flag == true)
		{
			image.blue_bright = 255;
			image.red_bright = 255;
			image.green_bright = 255;

			image_1.blue_bright = 255;
			image_1.red_bright = 255;
			image_1.green_bright = 255;

			image_2.blue_bright = 255;
			image_2.red_bright = 255;
			image_2.green_bright = 255;

			image_3.blue_bright = 255;
			image_3.red_bright = 255;
			image_3.green_bright = 255;

			if (image_number == 0)
			{
				image.Draw(image_draw);
			}

			if (image_number == 1)
			{
				image_1.Draw(image_draw);
			}

			if (image_number == 2)
			{
				image_2.Draw(image_draw);
			}

			if (image_number == 3)
			{
				image_3.Draw(image_draw);
			}

			image.blue_bright = 255;
			image.red_bright = 255;
			image.green_bright = 255;

			image_1.blue_bright = 255;
			image_1.red_bright = 255;
			image_1.green_bright = 255;

			image_2.blue_bright = 255;
			image_2.red_bright = 255;
			image_2.green_bright = 255;

			image_3.blue_bright = 255;
			image_3.red_bright = 255;
			image_3.green_bright = 255;
		}
	}
}

bool DiploidUI::SwitchButton_Flag_Change(bool flag)
{
	return button_flag = flag;
}

bool DiploidUI::GetSwitchButton_Flag()
{
	return button_flag;
}

bool DiploidUI::GetSwitchButton_HitFlag()
{
	return button_hit_flag;
}