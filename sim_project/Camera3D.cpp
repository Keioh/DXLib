#include "Camera3D.h"

void Camera3D::Init()
{
	SetCameraNearFar(0.1f, 10000.0f);//奥行設定
	//SetLightDirection(VGet(0.0f, 0.5f, 0.5f));//ディレクションライトの方向を設定
	MV1SetLoadModelUsePhysicsMode(DX_LOADMODEL_PHYSICS_REALTIME);//物理演算の仕方を指定
}

void Camera3D::Set(int window_x, int window_y, VECTOR pos, bool wire)
{
	Camera3D::Move(window_x, window_y, 0.1f, wire);

	SetCameraPositionAndAngle(VAdd(pos, moved_pos), 45 * (DX_PI_F / 180), 0.0f, 0.0f);
}

void Camera3D::Move(int window_x, int window_y, float speed, bool wire)
{
	SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)

	if (cursol_move_up.BoxColliderMouse(0, window_x, 0, 5, wire) == true)
	{
		moved_pos.z += speed;
	}
	if (cursol_move_down.BoxColliderMouse(0, window_x, window_y - 5, 5, wire) == true)
	{
		moved_pos.z -= speed;
	}
	if (cursol_move_left.BoxColliderMouse(0, 5, 0, window_y, wire) == true)
	{
		moved_pos.x -= speed;
	}
	if (cursol_move_right.BoxColliderMouse(window_x - 5, 5, 0, window_y, wire) == true)
	{
		moved_pos.x += speed;
	}

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