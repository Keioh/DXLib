#pragma once
#include <list>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"

using namespace std;

class DiploidCollision
{
private:

protected:

public:
	bool CircleAndCircleCollisionUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two);//�~�Ɖ~�̓����蔻������s���܂��B(�߂�l�͓�̉~���q�b�g���Ă�����true��Ԃ��܂��B)
	VECTOR CircleAndCircleCollisionPointsUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two);//�~�Ɖ~�����������u�Ԃ̈ʒu�𓾂܂��B(�߂�l�͓��������ꏊ�̈ʒu��Ԃ��܂��Bz�ɂ͔��a�������Ă��܂��B)
};