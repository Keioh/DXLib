#include "diploidGraphics\diploidLine.h"

void DiploidLine::Init(VECTOR position_one, VECTOR position_two)
{
	POSITION_ONE = position_one;
	POSITION_TWO = position_two;

}

void DiploidLine::Update()
{
	if (mouse_point_move_flag == true)//�}�E�X�Ǐ]�̏ꍇ�͉�ʍ���𒆐S�ɕ`�ʂ���̂ō���50�A�E��50�h�b�g�\���������ꍇ��Init(VGet(-50,0,0), VGet(50,0,0))�Ƃ��邱��
	{
		GetMousePoint(&mouse_position_x, &mouse_position_y);
		Position_one.x = mouse_position_x + POSITION_ONE.x;
		Position_two.x = mouse_position_x + POSITION_TWO.x;

		Position_one.y = mouse_position_y + POSITION_ONE.y;
		Position_two.y = mouse_position_y + POSITION_TWO.y;

	}
	else
	{
		anime_position_one = VAdd(anime_position_one, move_speed);//�A�j���[�V�����ňړ���������ۑ�
		Position_one = VAdd(POSITION_ONE, anime_position_one);//�I�u�W�F�N�g��`�ʂ����ʒu�ƈړ���������ۑ�

		anime_position_two = VAdd(anime_position_two, move_speed);//�A�j���[�V�����ňړ���������ۑ�
		Position_two = VAdd(POSITION_TWO, anime_position_two);//�I�u�W�F�N�g��`�ʂ����ʒu�ƈړ���������ۑ�
	}
}

void DiploidLine::Draw(bool wire)
{
	if (wire == true)
	{
		DrawLine(Position_one.x, Position_one.y, Position_two.x, Position_two.y, color, thickness);
	}
}

double DiploidLine::GetAngle()
{
	double angle;

	angle = atan2(Position_two.y - Position_one.y, Position_two.x - Position_one.x);

	return angle;
}