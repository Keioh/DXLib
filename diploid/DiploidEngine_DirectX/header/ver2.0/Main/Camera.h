#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"

class DiploidCamera
{
private:
	VECTOR camera_center_position = { 1280 / 2,720 / 2,0 };//�J�����̒����ʒu
	VECTOR origin_pos_sub_new_pos;//���ɂȂ����I�u�W�F�N�g�������ꏊ�ƃJ���������̋���

	VECTOR other_position;//���C���J�����ɐݒ肳�ꂽ�I�u�W�F�N�g�ȊO�̈ʒu
protected:

public:
	void SetMainCameraPosition_DiploidCircleV2(DiploidCircleV2* target);//target�̑��݂���ʒu�ɃJ�������ړ������܂��B
	void SetOtherLookObjectPosition_DiploidCircleV2(DiploidCircleV2* target);//���C���J�����̈ʒu�Ɉړ����Ă��Ȃ��I�u�W�F�N�g�𐳂����ړ������܂��B

	void SetMainCameraCenterPosition(VECTOR new_position);//�^�[�Q�b�g����ʂ̂ǂ��Ɉړ�������̂��ݒ肵�܂��B

	VECTOR GetMainCameraCenterPosition();//���C���J�����̈ʒu���擾���܂��B
};