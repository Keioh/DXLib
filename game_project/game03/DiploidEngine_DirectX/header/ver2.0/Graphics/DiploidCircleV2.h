#pragma once
#include <string>
#include "DxLib.h"

using namespace std;

//2D�̉~�Ɋւ���N���X(�X�^���h�A���[���ȃN���X�Ƃ��Ď���)
class DiploidCircleV2
{
private:
	string name;//�I�u�W�F�N�g�̖��O(��Ɍ�������Ƃ��Ɏg�p)
	int layer_number;//���C���[�̔ԍ�(��ɓ����蔻�莞�ɂǂ̑w�ɋ���̂����ʂ���̂Ɏg�p)

	VECTOR position;//�I�u�W�F�N�g�̈ʒu
	float radius;//�~�̔��a(�����ASize)

	unsigned int object_color;//�F
	bool object_fill;//�h��Ԃ�
	float object_thickness;//����

protected:

public:

	void Init(VECTOR pos, float radi, unsigned int color, bool fill = TRUE, float thickness = 1.0f);
	void Updata();
	void Draw(bool draw = true);//�~��`�悵�܂��B(draw��false�����邱�Ƃŕ`�悵�Ȃ�)

	void SetColor(unsigned int color);//�V�����F��ݒ肵�܂��B
	void SetPosition(VECTOR new_pos);//�V�����ʒu��ݒ肵�܂��B
	void SetRadius(float new_radius);//�V�������a��ݒ肵�܂��B
	void SetFill(bool new_fill);//�V���ɓh��Ԃ���ݒ肵�܂��B
	void SetThickness(float new_thickness);//�V���ɐ��̑�����ݒ肵�܂��B

	VECTOR GetPosition();//���݂̈ʒu���擾���܂��B
	float GetRadius();//���݂̔��a���擾���܂��B
	float GetThickness();//���݂̐��̑������擾���܂��B
	unsigned int GetColor();//���݂̐F���擾���܂��B
	bool GetFill();//���݂̓h��Ԃ��̐ݒ���擾���܂��B
};
