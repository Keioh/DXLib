#include "ver2.0/Objects/DiploidSlider.h"

void DiploidSlider::Load()
{
	slider_image.Load("texter/basic/button/slider/0.png");
	slider_button.Load(slider_image.GetGraphicsHandl());
}

void DiploidSlider::Init(VECTOR pos, VECTOR size, int slider_type, float scale)
{
	position = pos;
	object_size = size;
	object_scale = scale;
	slider_object_type = slider_type;

	slider_button.Init(position, VGet(16 * object_scale, 32 * object_scale, 0), slider_object_type, object_scale);

	box.Init(VGet(position.x, position.y + (16 * object_scale), position.z), VGet(object_size.x + (16 * object_scale), object_size.y + (4 * object_scale), object_size.z), GetColor(150, 150, 150));
	box.SetFill(true);

	t_data.point_one = VGet(position.x, position.y + (16 * object_scale), position.z);
	t_data.point_two = VGet(object_size.x + position.x + (16 * object_scale), position.y + object_size.y + (8 * object_scale), object_size.z);
	t_data.point_three = VGet(object_size.x + position.x + (16 * object_scale), position.y + object_size.y + (24 * object_scale), object_size.z);

	triangle.Init(t_data, GetColor(150, 150, 150));
	triangle.SetFill(true);
}

void DiploidSlider::Updata()
{
	slider_button.Updata();

	if ((position.x + object_size.x) < slider_button.GetPosition().x)
	{
		slider_button.SetPosition((position.x + object_size.x), position.y);
	}

	if (position.x > slider_button.GetPosition().x)
	{
		slider_button.SetPosition(position.x, position.y);
	}
}

void DiploidSlider::Draw(bool draw, bool debug)
{
	//box.Draw(draw);
	triangle.Draw(draw);

	slider_button.Draw(draw, debug);

	//DrawFormatString(300, 0, GetColor(0, 0, 0), "%f", slider_button.GetPosition().x);
}


void DiploidSlider::SetPosition(int pos_x, int pos_y)
{
	position = VGet(pos_x, pos_y, 0);
}

void DiploidSlider::SetSelectedUI(int new_flag)
{
	slider_button.SetSelectedUI(new_flag);
}

void DiploidSlider::SetSliderType(int new_type)
{
	slider_button.SetSliderType(new_type);
}

void DiploidSlider::SetParameter(VECTOR new_parameter)
{
	VECTOR pos = VGet(0, 0, 0);

	pos = VAdd(new_parameter, position);

	slider_button.SetPosition(pos.x, pos.y);
}


bool DiploidSlider::GetHit()
{
	return slider_button.GetHit();
}

bool DiploidSlider::GetClick()
{
	return slider_button.GetClick();
}

int DiploidSlider::GetSelectedUI()
{
	return slider_button.GetSelectedUI();
}

int DiploidSlider::GetSliderType()
{
	return slider_button.GetSliderType();
}

VECTOR DiploidSlider::GetParameter()
{
	VECTOR pos = VGet(0, 0, 0);

	pos = VSub(slider_button.GetPosition(), position);

	return pos;
}