#include "ver2.0/Graphics/DiploidImageV2.h"

void DiploidImageV2::Load(const char* path)
{
	SetUseASyncLoadFlag(FALSE);
	graphics_handl = LoadGraph(path);
	SetUseASyncLoadFlag(TRUE);

	GetGraphSize(graphics_handl, &graphics_x, &graphics_y);

	//‰æ‘œ‚Ì‘å‚«‚³‚ð•Û‘¶
	graphics_size.x = graphics_x;
	graphics_size.y = graphics_y;


	//‰ñ“]‚Ì’†S“_‚ðÝ’è
	//rotate_position.x = graphics_x / 2;
	//rotate_position.y = graphics_y / 2;
}

void DiploidImageV2::Init(VECTOR pos, bool shift_flag)
{
	if (shift_flag == true)//‰æ‘œ‚Ì’†S‚É‡‚í‚¹‚½•`‰æ‚ÌŽž
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

	//‚¢‚ë‚¢‚ë•ÏX‚µ‚½‚ ‚Æ‚Ì‘å‚«‚³‚ð•Û‘¶
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