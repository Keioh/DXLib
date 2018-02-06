#include "Camera3D.h"

void Camera3D::Init()
{
	SetCameraNearFar(0.1f, 10000.0f);//奥行設定
	//SetLightDirection(VGet(0.0f, 0.5f, 0.5f));//ディレクションライトの方向を設定
	MV1SetLoadModelUsePhysicsMode(DX_LOADMODEL_PHYSICS_REALTIME);//物理演算の仕方を指定
}

void Camera3D::Set(VECTOR pos)
{
	//現在の位置を保存
	xF = pos.x;
	yF = pos.y;
	zF = pos.z;

	Camera3D::Move(0.1f);

	SetCameraPositionAndAngle(VAdd(pos, moved_pos), 45 * (DX_PI_F / 180), 0.0f, 0.0f);
}

void Camera3D::Move(float speed)
{
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		moved_pos.z += speed;
	}
	else
	{
		moved_pos.z += 0.0f;
	}

	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		moved_pos.z -= speed;
	}
	else
	{
		moved_pos.z += 0.0f;
	}

	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		moved_pos.x += speed;

	}
	else
	{
		moved_pos.x += 0.0f;
	}

	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		moved_pos.x -= speed;
	}
	else
	{
		moved_pos.x += 0.0f;
	}


	wheel = GetMouseWheelRotVol();//マウスホイールの回転量をwheelに代入

	if (wheel != 0)
	{
		moved_pos.y -= wheel * speed;
	}
	else
	{
		moved_pos.y += 0.0f;
	}
}