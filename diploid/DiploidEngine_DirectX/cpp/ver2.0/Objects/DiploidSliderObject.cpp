#include "ver2.0/Objects/DiploidSliderObject.h"

void DiploidSliderObject::Load(int graphics_handl)
{
	image.SetHandl(graphics_handl);
}

void DiploidSliderObject::Init(VECTOR pos,VECTOR size, int slider_type, float scale)
{
	object_scale = scale;
	object_size = size;
	this->slider_type = slider_type;


	box.Init(pos, object_size, GetColor(200, 200, 200), object_scale);

	//image.Init(VGet(pos.x + (image.GetSize().x / 2), pos.y + (image.GetSize().y / 2), 0), false);
	image.Init(VGet(pos.x, pos.y, 0), false);
	image.SetScale(scale, scale);
}

void DiploidSliderObject::Updata(DiploidEngineInput& input)
{
	GetMousePoint(&mouse_x, &mouse_y);//マウス座標を取得

	//BOXに当たっていたら
	if (collision.BoxAndMouseCollisionUpdate(&box, mouse_x, mouse_y) == true)
	{
		box.SetColor(GetColor(255, 0, 0));

		hit = true;


		//クリックしたら
		if (input.GetMouse(MOUSE_INPUT_LEFT) == false)
		{
			no_hit_flag = false;
		}

		if (no_hit_flag == false)
		{
			//クリックしたら
			if (input.GetMouse(MOUSE_INPUT_LEFT) == true)
			{
				click = true;
				selected = 1;
			}
			else
			{
				click = false;
				selected = -1;
			}

			if (selected == 1)
			{
				box.SetColor(GetColor(0, 255, 0));
			}
		}
		else
		{
			box.SetColor(GetColor(0, 0, 255));
		}
	}
	else
	{
		//クリックしたら
		if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
		{
			no_hit_flag = true;
		}


		if (no_hit_flag == false)
		{
			if (selected == 1)
			{
				box.SetColor(GetColor(0, 255, 0));

				if (input.GetMouse(MOUSE_INPUT_LEFT) == false)
				{
					selected = -1;
				}
			}
			else
			{
				box.SetColor(GetColor(0, 0, 255));
			}

			hit = false;
		}
		else
		{
			if (selected == 1)
			{
				box.SetColor(GetColor(0, 255, 0));

			}
			else
			{
				box.SetColor(GetColor(0, 0, 255));
			}
		}
	}


	if (selected == 1)
	{
		if (slider_type == 0)
		{
			box.SetPosition(VGet(mouse_x - ((object_size.x / 2) * object_scale), mouse_y - ((object_size.y / 2) * object_scale), 0));
		}

		if (slider_type == 1)
		{
			box.SetPosition(VGet(mouse_x - ((object_size.x / 2) * object_scale), box.GetPosition().y, 0));
		}

		if (slider_type == 2)
		{
			box.SetPosition(VGet(box.GetPosition().x, mouse_y - ((object_size.y / 2) * object_scale), 0));
		}
	}
}

void DiploidSliderObject::Updata()
{
	GetMousePoint(&mouse_x, &mouse_y);//マウス座標を取得

	input.Update();

		//BOXに当たっていたら
	if (collision.BoxAndMouseCollisionUpdate(&box, mouse_x, mouse_y) == true)
	{
		box.SetColor(GetColor(255, 0, 0));

		hit = true;

		//クリックしたら
		if (input.GetMouse(MOUSE_INPUT_LEFT) == false)
		{
			no_hit_flag = false;
		}

		if (no_hit_flag == false)
		{
			//クリックしたら
			if (input.GetMouse(MOUSE_INPUT_LEFT) == true)
			{
				click = true;
				selected = 1;
			}
			else
			{
				click = false;
				selected = -1;
			}

			if (selected == 1)
			{
				box.SetColor(GetColor(0, 255, 0));
			}
		}
		else
		{
			box.SetColor(GetColor(0, 0, 255));
		}
	}
	else
	{
		//クリックしたら
		if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
		{
			no_hit_flag = true;
		}

		if (input.GetMouse(MOUSE_INPUT_LEFT) == false)
		{
			no_hit_flag = false;
		}


		if (no_hit_flag == false)
		{
			if (selected == 1)
			{
				box.SetColor(GetColor(0, 255, 0));

				if (input.GetMouse(MOUSE_INPUT_LEFT) == false)
				{
					selected = -1;
				}
			}
			else
			{
				box.SetColor(GetColor(0, 0, 255));
			}

			hit = false;
		}
		else
		{
			if (selected == 1)
			{
				box.SetColor(GetColor(0, 255, 0));

			}
			else
			{
				box.SetColor(GetColor(0, 0, 255));
			}
		}
	}


	if (selected == 1)
	{
		if (slider_type == 0)
		{
			box.SetPosition(VGet(mouse_x - ((object_size.x / 2) * object_scale), mouse_y - ((object_size.y / 2) * object_scale), 0));
		}

		if (slider_type == 1)
		{
			box.SetPosition(VGet(mouse_x - ((object_size.x / 2) * object_scale), box.GetPosition().y, 0));
		}

		if (slider_type == 2)
		{
			box.SetPosition(VGet(box.GetPosition().x, mouse_y - ((object_size.y / 2) * object_scale), 0));
		}
	}

	position = box.GetPosition();
	image.SetPosition(position);
}

void DiploidSliderObject::Draw(bool draw, bool debug)
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

	//DrawFormatString(0, 300, GetColor(0, 0, 0), "%d", selected);
}


void DiploidSliderObject::SetPosition(int pos_x, int pos_y)
{
	image.SetPosition(VGet(pos_x, pos_y, 0));
	box.SetPosition(VGet(pos_x, pos_y, 0));

	position = VGet(pos_x, pos_y, 0);
}

void DiploidSliderObject::SetSize(int size_x, int size_y)
{
	//box.SetSize(VGet(size_x, size_y, 0));

	object_size = VGet(size_x, size_y, 0);
}

void DiploidSliderObject::SetScale(float new_scale)
{
	//image.SetScale(new_scale, new_scale);
	//box.SetScale(new_scale, new_scale);

	object_scale = new_scale;
}

void DiploidSliderObject::SetSelectedUI(int new_flag)
{
	selected = new_flag;
}

void DiploidSliderObject::SetSliderType(int new_type)
{
	slider_type = new_type;
}


VECTOR DiploidSliderObject::GetPosition()
{
	return position;
}

VECTOR DiploidSliderObject::GetSize()
{
	return object_size;
}

float DiploidSliderObject::GetScale()
{
	return object_scale;
}

VECTOR DiploidSliderObject::GetGraphicsSize()
{
	return image.GetSize();
}

bool DiploidSliderObject::GetHit()
{
	return hit;
}

bool DiploidSliderObject::GetClick()
{
	return click;
}

int DiploidSliderObject::GetSelectedUI()
{
	return selected;
}

int DiploidSliderObject::GetSliderType()
{
	return slider_type;
}