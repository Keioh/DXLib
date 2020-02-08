#pragma once
#include <list>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"

using namespace std;

class DiploidCollision
{
private:
	int upadata_count;//���X�V���邩�̃J�E���g(��ʊO�ȂǁA�p�ɂɔ�����������Ȃ��ꏊ�Ōv�Z�񐔂����炷���߂̕ϐ�)

protected:

public:
	bool CircleAndCircleCollisionUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two, int updata_rate = 0);//�~�Ɖ~�̓����蔻������s���܂��B(�߂�l�͓�̉~���q�b�g���Ă�����true��Ԃ��܂��B)
	VECTOR CircleAndCircleCollisionPointsUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two, int updata_rate = 0);//�~�Ɖ~�����������u�Ԃ̈ʒu�𓾂܂��B(�߂�l�͓��������ꏊ�̈ʒu��Ԃ��܂��Bz�ɂ͔��a�������Ă��܂��B)
	
	int GetUpdataCounter();//�X�V�p�x�𐔂���J�E���^�[���擾���܂��B
};