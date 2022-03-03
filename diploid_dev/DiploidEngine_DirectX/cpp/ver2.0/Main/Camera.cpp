#include "ver2.0/Main/Camera.h"

void DiploidCamera::SetMainCameraPosition(VECTOR* target)
{
	//カメラの中央座標とターゲットの現在の位置の差を計算
	origin_pos_sub_new_pos.x = target->x - camera_center_position.x;
	origin_pos_sub_new_pos.y = target->y - camera_center_position.y;
	origin_pos_sub_new_pos.z = target->z - camera_center_position.z;

	*target = camera_center_position;
}


void DiploidCamera::SetMainCameraPosition_DiploidCircleV2(DiploidCircleV2* target)
{
	//メインカメラのフラグを立てる
	//target->SetMainCameraFlag(true);

	//カメラの中央座標とターゲットの現在の位置の差を計算
	if (target->GetMainCameraFlag() == true)//objectのメインカメラのフラグがtrueなら
	{
		origin_pos_sub_new_pos.x = target->GetPosition().x - camera_center_position.x;
		origin_pos_sub_new_pos.y = target->GetPosition().y - camera_center_position.y;
		origin_pos_sub_new_pos.z = target->GetPosition().z - camera_center_position.z;

		target->SetPosition(camera_center_position);
	}
}

void DiploidCamera::SetOtherLookObjectPosition_DiploidCircleV2(DiploidCircleV2* target)
{
	if (target->GetMainCameraFlag() == false)//メインカメラのフラグがfalseなら
	{
		//差をtargetの位置から引く。
		other_position.x = target->GetPosition().x - origin_pos_sub_new_pos.x;
		other_position.y = target->GetPosition().y - origin_pos_sub_new_pos.y;
		other_position.z = target->GetPosition().z - origin_pos_sub_new_pos.z;

		target->SetPosition(other_position);//位置を設定。
	}
}


void DiploidCamera::SetMainCameraPosition_DiploidBoxV2(DiploidBoxV2* target)
{
	//メインカメラのフラグを立てる
	//target->SetMainCameraFlag(true);

	//カメラの中央座標とターゲットの現在の位置の差を計算
	if (target->GetMainCameraFlag() == true)//メインカメラのフラグがtrueなら
	{
		origin_pos_sub_new_pos.x = target->GetPosition().x - camera_center_position.x;
		origin_pos_sub_new_pos.y = target->GetPosition().y - camera_center_position.y;
		origin_pos_sub_new_pos.z = target->GetPosition().z - camera_center_position.z;

		target->SetPosition(camera_center_position);
	}
}

void DiploidCamera::SetOtherLookObjectPosition_DiploidBoxV2(DiploidBoxV2* target)
{
	if (target->GetMainCameraFlag() == false)//メインカメラのフラグがfalseなら
	{
		//差をtargetの位置から引く。
		other_position.x = target->GetPosition().x - origin_pos_sub_new_pos.x;
		other_position.y = target->GetPosition().y - origin_pos_sub_new_pos.y;
		other_position.z = target->GetPosition().z - origin_pos_sub_new_pos.z;

		target->SetPosition(other_position);//位置を設定。
	}
}


void DiploidCamera::SetMainCameraCenterPosition(VECTOR new_position)
{
	camera_center_position = new_position;
}


VECTOR DiploidCamera::GetMainCameraCenterPosition()
{
	return this->camera_center_position;
}