#include "ver2.0/Objects/DiploidSelectedUIV2.h"

void DiploidSelectedUIV2::Load(int graphics_handl)
{
	image.SetHandl(graphics_handl);	
}

void DiploidSelectedUIV2::Init(VECTOR pos, VECTOR size, float scale)
{
	object_scale = scale;
	object_size = size;
	box.Init(pos, object_size, GetColor(200, 200, 200), object_scale);

	//image.Init(VGet(pos.x + (image.GetSize().x / 2), pos.y + (image.GetSize().y / 2), 0), false);
	image.Init(VGet(pos.x , pos.y, 0), false);
	image.SetScale(scale, scale);
}

void DiploidSelectedUIV2::Updata(DiploidEngineInput* input)
{
	GetMousePoint(&mouse_x, &mouse_y);//マウス座標を取得

	//BOXに当たっていたら
	if (collision.BoxAndMouseCollisionUpdate(&box, mouse_x, mouse_y) == true)
	{
		box.SetColor(GetColor(255, 0, 0));

		hit = true;

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
		box.SetColor(GetColor(0, 0, 255));

		hit = false;
	}
}

void DiploidSelectedUIV2::Draw(bool draw, bool debug)
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


void DiploidSelectedUIV2::SetPosition(int pos_x, int pos_y)
{	
	image.SetPosition(VGet(pos_x, pos_y, 0));
	box.SetPosition(VGet(pos_x, pos_y, 0));

	position = VGet(pos_x, pos_y, 0);
}

void DiploidSelectedUIV2::SetSize(int size_x, int size_y)
{
	//box.SetSize(VGet(size_x, size_y, 0));

	object_size = VGet(size_x, size_y, 0);
}

void DiploidSelectedUIV2::SetScale(float new_scale)
{
	//image.SetScale(new_scale, new_scale);
	//box.SetScale(new_scale, new_scale);

	object_scale = new_scale;
}

void DiploidSelectedUIV2::SetSelectedUI(int new_flag)
{
	selected = new_flag;
}


VECTOR DiploidSelectedUIV2::GetPosition()
{
	return position;
}

VECTOR DiploidSelectedUIV2::GetSize()
{
	return object_size;
}

float DiploidSelectedUIV2::GetScale()
{
	return object_scale;
}

VECTOR DiploidSelectedUIV2::GetGraphicsSize()
{
	return image.GetSize();
}

bool DiploidSelectedUIV2::GetHit()
{
	return hit;
}

bool DiploidSelectedUIV2::GetClick()
{
	return click;
}

int DiploidSelectedUIV2::GetSelectedUI()
{
	return selected;
}