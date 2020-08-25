#include "ver2.0/Objects/DiploidTouchUI.h"

void DiploidTouchUI::Load(int graphics_handl)
{
	image.SetHandl(graphics_handl);
}

void DiploidTouchUI::Init(VECTOR pos, VECTOR size, float scale, bool touch)
{
	object_scale = scale;
	object_size = size;
	box.Init(pos, object_size, GetColor(200, 200, 200), object_scale);

	image.Init(VGet(pos.x + (image.GetSize().x / 2), pos.y + (image.GetSize().y / 2), 0), false);
	image.SetScale(scale, scale);

	touch_flag = touch;
}

void DiploidTouchUI::Updata(DiploidEngineInput* input)
{
	//9999を超えるなら
	if (time > 9999)
	{
		time = 9999;//9999で止める。
	}

	if (touch_flag == false)
	{
		GetMousePoint(&mouse_x, &mouse_y);//マウス座標を取得
	}
	else
	{
		//タッチ座標を取得
		mouse_x = input->GetTouchPositionX();
		mouse_y = input->GetTouchPositionY();
	}

	//BOXに当たっていたら
	if (collision.BoxAndMouseCollisionUpdate(&box, mouse_x, mouse_y) == true)
	{
		box.SetColor(GetColor(255, 0, 0));

		hit = true;

		if (touch_flag == false)
		{
			if (input->GetMouse(MOUSE_INPUT_LEFT) == true)
			{
				time += 1;
			}
			else
			{
				time = 0;
			}

			//クリックしたら
			if (input->GetPressMouse(MOUSE_INPUT_LEFT) == true)
			{
				box.SetColor(GetColor(0, 255, 0));

				click = true;
				selected *= -1;

			}
			else
			{
				click = false;

			}
		}
		else
		{
			if (input->GetTouch() == true)
			{
				time += 1;
			}
			else
			{
				time = 0;
			}

			//タッチしたら
			if (input->GetReleaseTouch() == true)
			{
				box.SetColor(GetColor(0, 255, 0));

				click = true;
				selected *= -1;				
			}
			else
			{
				click = false;
			}
		}
	}
	else
	{
		box.SetColor(GetColor(0, 0, 255));

		hit = false;
		click = false;
		time = 0;
	}

	if (click == 1)
	{
		box.SetColor(GetColor(0, 255, 0));
	}
}

void DiploidTouchUI::Draw(bool draw, bool debug)
{
	if (draw == true)
	{
		if (selected == 1)
		{
			image.SetBright(bright_red, bright_green, bright_blue);
			image.Draw(draw);
		}
		else if (hit == false)
		{
			image.SetBright(bright_red * on_hit_color_scale, bright_green * on_hit_color_scale, bright_blue * on_hit_color_scale);
			image.Draw(draw);
		}
		else
		{
			image.SetBright(bright_red, bright_green, bright_blue);
			image.Draw(draw);
		}

		if (debug == true)
		{
			box.Draw(draw);
		}

		SetDrawBright(255, 255, 255);
	}
}


void DiploidTouchUI::SetPosition(int pos_x, int pos_y)
{
	position = VGet(pos_x, pos_y, 0);
}

void DiploidTouchUI::SetSize(int size_x, int size_y)
{
	object_size = VGet(size_x, size_y, 0);
}

void DiploidTouchUI::SetScale(float new_scale)
{
	object_scale = new_scale;
}

void DiploidTouchUI::SetSelectedUI(int new_flag)
{
	selected = new_flag;
}

void DiploidTouchUI::SetTouchFlag(bool new_flag)
{
	touch_flag = new_flag;
}


VECTOR DiploidTouchUI::GetPosition()
{
	return position;
}

VECTOR DiploidTouchUI::GetSize()
{
	return object_size;
}

float DiploidTouchUI::GetScale()
{
	return object_scale;
}

VECTOR DiploidTouchUI::GetGraphicsSize()
{
	return image.GetSize();
}

bool DiploidTouchUI::GetHit()
{
	return hit;
}

bool DiploidTouchUI::GetClick()
{
	return click;
}

int DiploidTouchUI::GetSelectedUI()
{
	return selected;
}

int DiploidTouchUI::GetTime()
{
	return time;
}