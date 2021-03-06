#include "ver2.0/Graphics/DiploidImageV2.h"

void DiploidImageV2::Load(const char* path)
{
	SetUseASyncLoadFlag(FALSE);
	graphics_handl = LoadGraph(path);
	SetUseASyncLoadFlag(TRUE);

	GetGraphSize(graphics_handl, &graphics_x, &graphics_y);

	//画像の大きさを保存
	graphics_size.x = graphics_x;
	graphics_size.y = graphics_y;


	//回転の中心点を設定
	//rotate_position.x = graphics_x / 2;
	//rotate_position.y = graphics_y / 2;
}

void DiploidImageV2::Init(VECTOR pos, bool shift_flag)
{
	if (shift_flag == true)//画像の中心に合わせた描画の時
	{
		position.x = pos.x - (graphics_x / 2);
		position.y = pos.y - (graphics_y / 2);
	}
	else
	{
		position = pos;
	}
}

void DiploidImageV2::Draw(bool draw)
{
	DrawRotaGraph3(position.x, position.y, rotate_position.x, rotate_position.y, graphics_scale.x, graphics_scale.y, angle, graphics_handl, TRUE, turn);
}


void DiploidImageV2::SetScale(float scale_x, float scale_y)
{
	graphics_scale.x = scale_x;
	graphics_scale.y = scale_y;

	//いろいろ変更したあとの大きさを保存
	graphics_size.x = graphics_scale.x * graphics_x;
	graphics_size.y = graphics_scale.y * graphics_y;
}

void DiploidImageV2::SetAngle(float new_angle)
{
	angle = new_angle;
}

void DiploidImageV2::SetPosition(VECTOR new_position)
{
	position = new_position;
}

void DiploidImageV2::SetTurnFlag(bool new_flag)
{
	turn = new_flag;
}

void DiploidImageV2::SetRotatePosition(VECTOR new_position)
{
	rotate_position = new_position;
}


int DiploidImageV2::GetGraphicsHandl()
{
	return this->graphics_handl;
}

VECTOR DiploidImageV2::GetScale()
{
	return graphics_scale;
}

VECTOR DiploidImageV2::GetSize()
{
	return graphics_size;
}

VECTOR DiploidImageV2::GetPosition()
{
	return position;
}

VECTOR DiploidImageV2::GetRotatePosition()
{
	return rotate_position;
}

float DiploidImageV2::GetAngle()
{
	return angle;
}

bool DiploidImageV2::GetTurnFlag()
{
	return turn;
}