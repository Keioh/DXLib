#pragma once
#include <list>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"

using namespace std;

class DiploidCollision
{
private:
	int upadata_count;//���X�V���邩�̃J�E���g(��ʊO�ȂǁA�p�ɂɔ����������Ȃ��ꏊ�Ōv�Z�񐔂���炷���߂̕ϐ�)
	int window_size_x = 1080, window_size_y = 1920;

protected:

public:
	bool CircleAndCircleCollisionUpdate(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two, int updata_rate = 0);//�~�Ɖ~�̓����蔻�����s���܂��B(�߂�l�͓�̉~���q�b�g���Ă�����true��Ԃ��܂��B)
	VECTOR CircleAndCircleCollisionPointsUpdate(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two, int updata_rate = 0);//�~�Ɖ~�����������u�Ԃ̈ʒu�𓾂܂��B(�߂�l�͓��������ꏊ�̈ʒu��Ԃ��܂��Bz�ɂ͔��a�������Ă��܂��B)
	
	bool BoxAndMouseCollisionUpdate(DiploidBoxV2* box, int mouse_x, int mouse_y, int updata_rate = 0);//�l�p�ƃ}�E�X�̓����蔻�����s���܂��B(�߂�l�̓}�E�X�Ǝl�p���q�b�g���Ă�����true��Ԃ��܂��B)
	bool BoxAndTouchCollisionUpdate(DiploidBoxV2* box, int touch_x, int touch_y, int updata_rate = 0);//�l�p�ƃ^�b�`�̓����蔻�����s���܂��B(�߂�l�̓^�b�`�Ǝl�p���q�b�g���Ă�����true��Ԃ��܂��B)


	int GetUpdateCounter();//�X�V�p�x�𐔂���J�E���^�[��擾���܂��B
};