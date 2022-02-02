#include "ver2.0/Main/Camera.h"

void DiploidCamera::SetMainCameraPosition(VECTOR* target)
{
	//�J�����̒������W�ƃ^�[�Q�b�g�̌��݂̈ʒu�̍����v�Z
	origin_pos_sub_new_pos.x = target->x - camera_center_position.x;
	origin_pos_sub_new_pos.y = target->y - camera_center_position.y;
	origin_pos_sub_new_pos.z = target->z - camera_center_position.z;

	*target = camera_center_position;
}


void DiploidCamera::SetMainCameraPosition_DiploidCircleV2(DiploidCircleV2* target)
{
	//���C���J�����̃t���O�𗧂Ă�
	//target->SetMainCameraFlag(true);

	//�J�����̒������W�ƃ^�[�Q�b�g�̌��݂̈ʒu�̍����v�Z
	if (target->GetMainCameraFlag() == true)//object�̃��C���J�����̃t���O��true�Ȃ�
	{
		origin_pos_sub_new_pos.x = target->GetPosition().x - camera_center_position.x;
		origin_pos_sub_new_pos.y = target->GetPosition().y - camera_center_position.y;
		origin_pos_sub_new_pos.z = target->GetPosition().z - camera_center_position.z;

		target->SetPosition(camera_center_position);
	}
}

void DiploidCamera::SetOtherLookObjectPosition_DiploidCircleV2(DiploidCircleV2* target)
{
	if (target->GetMainCameraFlag() == false)//���C���J�����̃t���O��false�Ȃ�
	{
		//����target�̈ʒu��������B
		other_position.x = target->GetPosition().x - origin_pos_sub_new_pos.x;
		other_position.y = target->GetPosition().y - origin_pos_sub_new_pos.y;
		other_position.z = target->GetPosition().z - origin_pos_sub_new_pos.z;

		target->SetPosition(other_position);//�ʒu��ݒ�B
	}
}


void DiploidCamera::SetMainCameraPosition_DiploidBoxV2(DiploidBoxV2* target)
{
	//���C���J�����̃t���O�𗧂Ă�
	//target->SetMainCameraFlag(true);

	//�J�����̒������W�ƃ^�[�Q�b�g�̌��݂̈ʒu�̍����v�Z
	if (target->GetMainCameraFlag() == true)//���C���J�����̃t���O��true�Ȃ�
	{
		origin_pos_sub_new_pos.x = target->GetPosition().x - camera_center_position.x;
		origin_pos_sub_new_pos.y = target->GetPosition().y - camera_center_position.y;
		origin_pos_sub_new_pos.z = target->GetPosition().z - camera_center_position.z;

		target->SetPosition(camera_center_position);
	}
}

void DiploidCamera::SetOtherLookObjectPosition_DiploidBoxV2(DiploidBoxV2* target)
{
	if (target->GetMainCameraFlag() == false)//���C���J�����̃t���O��false�Ȃ�
	{
		//����target�̈ʒu��������B
		other_position.x = target->GetPosition().x - origin_pos_sub_new_pos.x;
		other_position.y = target->GetPosition().y - origin_pos_sub_new_pos.y;
		other_position.z = target->GetPosition().z - origin_pos_sub_new_pos.z;

		target->SetPosition(other_position);//�ʒu��ݒ�B
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