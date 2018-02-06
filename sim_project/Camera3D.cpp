#include "Camera3D.h"



void Camera3D::Set(VECTOR pos)
{
	//現在の位置を保存
	xF = pos.x;
	yF = pos.y;
	zF = pos.z;

	Camera3D::Move(10.0f);

	SetCameraPositionAndAngle(VAdd(pos, moved_pos), 0.0f, 0.0f, 0.0f);
}

void Camera3D::Move(float speed)
{
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		moved_pos.y -= speed;
	}
	else
	{
		moved_pos.y += 0.0f;
	}

	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		moved_pos.y += speed;
	}
	else
	{
		moved_pos.y += 0.0f;
	}

	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		moved_pos.x -= speed;
	}
	else
	{
		moved_pos.x += 0.0f;
	}

	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		moved_pos.x += speed;
	}
	else
	{
		moved_pos.x += 0.0f;
	}


	wheel = GetMouseWheelRotVol();//マウスホイールの回転量をwheelに代入

	if (wheel != 0)
	{
		moved_pos.z += wheel * speed;
	}
	else
	{
		moved_pos.z += 0.0f;
	}
}