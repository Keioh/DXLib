#include "diploidGraphics\diploidImage.h"

void DiploidImage::Load(const char* path)
{
	handl = LoadGraph(path);
}

void DiploidImage::Init(VECTOR pos, double size_scale, double angle_scale)
{
	position = origin_position = pos;//ポジションをposで初期化
	scale = origin_size = size_scale;//大きさを指定。
	angle = origin_angle = angle_scale;//角度を指定。

	GetGraphSize(handl, &GRAPHICS_SIZE_X, &GRAPHICS_SIZE_Y);//画像の大きさを取得
}

void DiploidImage::Updata()
{	
	GetGraphSize(handl, &GRAPHICS_SIZE_X, &GRAPHICS_SIZE_Y);//画像の大きさを取得

	if (mouse_point_move_flag == false)
	{
		anime_position = VAdd(anime_position, move_speed);
		position = VAdd(anime_position, origin_position);
		center_position = VAdd(center_position, move_speed);

		anime_angle = anime_angle + move_angle;
		angle = anime_angle + origin_angle;

		anime_size = anime_size + move_size_private;
		scale = anime_size + origin_size;

		blend_volume += blend_speed;

		red_bright += red_bright_speed;
		green_bright += green_bright_speed;
		blue_bright += blue_bright_speed;
	}
	else
	{
		GetMousePoint(&mouse_x, &mouse_y);

		position.x = mouse_x;
		position.y = mouse_y;

		anime_angle = anime_angle + move_angle;
		angle = anime_angle + origin_angle;

		anime_size = anime_size + move_size_private;
		scale = anime_size + origin_size;

		blend_volume += blend_speed;

		red_bright += red_bright_speed;
		green_bright += green_bright_speed;
		blue_bright += blue_bright_speed;
	}

	//画像の明るさの値が一定値を超えた場合、超過しないように処理。
	if (red_bright > 255)
	{
		red_bright = 255;
	}
	if (red_bright < 0)
	{
		red_bright = 0;
	}

	if (green_bright > 255)
	{
		green_bright = 255;
	}
	if (green_bright < 0)
	{
		green_bright = 0;
	}

	if (blue_bright > 255)
	{
		blue_bright = 255;
	}
	if (blue_bright < 0)
	{
		blue_bright = 0;
	}

	//角度が360度を超えたら0度で初期化
	if (angle > (2 * DX_PI))
	{
		angle = anime_angle = 0;
	}

	if (angle < -(2 * DX_PI))
	{
		angle = anime_angle = 0;
	}

	//最大値を超えたら255で初期化
	if (blend_volume > 255)
	{
		blend_volume = 255;
	}

	if (blend_volume < 0)
	{
		blend_volume = 0;
	}
}

void DiploidImage::Draw(bool draw)
{
	if (draw == true)
	{
		SetDrawBright(red_bright, green_bright, blue_bright);
		SetDrawBlendMode(blend_mode, blend_volume);
		DrawRotaGraph(position.x, position.y, scale, angle, handl, TRUE, revers_x, revers_y);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBright(255, 255, 255);
	}
}


int DiploidImage::GetGraphicsSizeX()
{
	return GRAPHICS_SIZE_X;
}

int DiploidImage::GetGraphicsSizeY()
{
	return GRAPHICS_SIZE_Y;
}