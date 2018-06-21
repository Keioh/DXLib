#include "diploidGraphics\diploidImage.h"

void DiploidImage::Load(const char* path)
{
	handl = LoadGraph(path);
}

void DiploidImage::Init(VECTOR pos, double size_scale, double angle_scale)
{
	position = origin_position = pos;//�|�W�V������pos�ŏ�����
	scale = origin_size = size_scale;//�傫�����w��B
	angle = origin_angle = angle_scale;//�p�x���w��B
}

void DiploidImage::Updata()
{	
	GetGraphSize(handl, &GRAPHICS_SIZE_X, &GRAPHICS_SIZE_Y);//�摜�̑傫�����擾

	if (mouse_point_move_flag == false)
	{
		anime_position = VAdd(anime_position, move_speed);
		position = VAdd(anime_position, origin_position);
		center_position = VAdd(center_position, move_speed);

		anime_angle = anime_angle + move_angle;
		angle = anime_angle + origin_angle;

		anime_size = anime_size + move_size;
		scale = anime_size + origin_size;

		blend_volume += blend_speed;
	}
	else
	{
		GetMousePoint(&mouse_x, &mouse_y);

		position.x = mouse_x;
		position.y = mouse_y;

		anime_angle = anime_angle + move_angle;
		angle = anime_angle + origin_angle;

		anime_size = anime_size + move_size;
		scale = anime_size + origin_size;

		blend_volume += blend_speed;
	}

	//�p�x��360�x�𒴂�����0�x�ŏ�����
	if (angle >= (2 * DX_PI))
	{
		angle = anime_angle = 0;
	}

	//�ő�l�𒴂�����255�ŏ�����
	if (blend_volume > 255)
	{
		blend_volume = 255;
	}
	else if (blend_volume < 0)
	{
		blend_volume = 0;
	}
}

void DiploidImage::Draw(bool draw)
{
	if (draw == true)
	{
		SetDrawBlendMode(blend_mode, blend_volume);
		DrawRotaGraph(position.x, position.y, scale, angle, handl, TRUE, revers_x, revers_y);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
}