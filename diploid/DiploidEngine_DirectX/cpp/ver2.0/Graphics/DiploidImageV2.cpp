#include "ver2.0/Graphics/DiploidImageV2.h"


void DiploidImageV2::Load(const char* path)
{
	SetUseASyncLoadFlag(FALSE);
	graphics_handl = LoadGraph(path);

	GetGraphSize(graphics_handl, &graphics_x, &graphics_y);

	//‰æ‘œ‚Ì‘å‚«‚³‚ð•Û‘¶
	graphics_size.x = graphics_x;
	graphics_size.y = graphics_y;


	//‰ñ“]‚Ì’†S“_‚ðÝ’è
	//rotate_position.x = graphics_x / 2;
	//rotate_position.y = graphics_y / 2;	
	
	SetUseASyncLoadFlag(TRUE);
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

void DiploidImageV2::MoveUpdate()
{
	this->position.x += this->move_speed.x;
	this->position.y += this->move_speed.y;
	this->position.z += this->move_speed.z;

	move_speed = VGet(0, 0, 0);
}

void DiploidImageV2::Draw(bool draw)
{
	if (draw == true)
	{
		DrawRotaGraph3(position.x, position.y, rotate_position.x, rotate_position.y, graphics_scale.x, graphics_scale.y, angle, graphics_handl, TRUE, turn);
	}
}


void DiploidImageV2::SetHandl(int new_handl)
{
	graphics_handl = new_handl;

	GetGraphSize(graphics_handl, &graphics_x, &graphics_y);

	//‰æ‘œ‚Ì‘å‚«‚³‚ð•Û‘¶
	graphics_size.x = graphics_x;
	graphics_size.y = graphics_y;

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

void DiploidImageV2::SetBright(float scale)
{
	SetDrawBright(255 * scale, 255 * scale, 255 * scale);
}

void DiploidImageV2::SetBright(int red, int green, int blue)
{
	SetDrawBright(red, green, blue);
}


void DiploidImageV2::SetMoveSpeed(VECTOR new_move_speed)
{
	move_speed = new_move_speed;
}

void DiploidImageV2::SetMoveSpeed(float angle, float new_move_speed)
{
	move_speed.x = cosf(angle) * new_move_speed;
	move_speed.y = sinf(angle) * new_move_speed;

	move_angle = angle;
}

void DiploidImageV2::SetName(string new_name)
{
	name = new_name;
}

void DiploidImageV2::SetLife(float new_life)
{
	object_life = new_life;
}

void DiploidImageV2::SetDestoryFlag(bool new_flag)
{
	destory_flag = new_flag;
}

void DiploidImageV2::SetMainCameraFlag(bool new_flag)
{
	main_camera = new_flag;
}

void DiploidImageV2::SetObjectNumber(int new_number)
{
	object_number = new_number;
}

void DiploidImageV2::SetHitFlag(bool new_hit_flag)
{
	hit_flag = new_hit_flag;
}


void DiploidImageV2::AddLife(float add_val)
{
	this->object_life += add_val;
}

void DiploidImageV2::SubLife(float sub_val)
{
	this->object_life -= sub_val;
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

VECTOR DiploidImageV2::GetCenterPosition()
{
	center_position.x = position.x + (graphics_x / 2);
	center_position.y = position.y + (graphics_y / 2);

	return center_position;
}

VECTOR DiploidImageV2::GetRotatePosition()
{
	return rotate_position;
}

VECTOR DiploidImageV2::GetDownCenterPosition()
{
	down_center_position.x = position.x + graphics_x;
	down_center_position.y = position.y + graphics_y;

	return down_center_position;
}

float DiploidImageV2::GetAngle()
{
	return angle;
}

bool DiploidImageV2::GetTurnFlag()
{
	return turn;
}


VECTOR DiploidImageV2::GetMoveSpeed()
{
	return this->move_speed;
}

float DiploidImageV2::GetMoveAngle()
{
	return this->move_angle;
}

string DiploidImageV2::GetName()
{
	return name;
}

float DiploidImageV2::GetLife()
{
	return this->object_life;
}

bool DiploidImageV2::GetDestoryFlag()
{
	return this->destory_flag;
}

bool DiploidImageV2::GetMainCameraFlag()
{
	return this->main_camera;
}

int DiploidImageV2::GetObjectNumber()
{
	return this->object_number;
}

bool DiploidImageV2::GetHitFlag()
{
	return this->hit_flag;
}