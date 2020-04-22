#pragma once
#include <memory>
#include <string>
#include "DxLib.h"

using namespace std;

class DiploidBoxV2
{
	string name;//�I�u�W�F�N�g�̖��O(��Ɍ�������Ƃ��Ɏg�p)
	int layer_number;//���C���[�̔ԍ�(��ɓ����蔻�莞�ɂǂ̑w�ɋ���̂����ʂ���̂Ɏg�p)
	int object_number;//�I�u�W�F�N�g�̔ԍ�

	VECTOR position;//�I�u�W�F�N�g�̈ʒu
	VECTOR move_speed;//�I�u�W�F�N�g�̈ړ��X�s�[�h
	float move_angle;//�I�u�W�F�N�g�̈ړ�����
	VECTOR box_size;//�l�p�̑傫��

	float object_scale_x = 1.0f;
	float object_scale_y = 1.0f;
	unsigned int object_color;//�F
	bool object_fill;//�h��Ԃ�
	float object_thickness;//����
	float object_life;//����

	bool destory_flag = false;//�폜�t���O(true�̏ꍇ�A�폜�Ώۂ�)
	bool hit_flag = false;//�������Ă��邩�̃t���O
	bool main_camera = false;//���C���J�����̒ǂ��I�u�W�F�N�g���̃t���O

protected:

public:

	void Init(VECTOR pos, VECTOR size, unsigned int color, float scale = 1.0f, bool fill = FALSE, float thickness = 1.0f);
	void MoveUpdate();//�ݒ肵���ړ����x�𔽉f���܂��B
	void Draw(bool draw = true);//�~��`�悵�܂��B(draw��false�����邱�Ƃŕ`�悵�Ȃ�)

	void SetColor(unsigned int new_color);//�V�����F��ݒ肵�܂��B
	void SetPosition(VECTOR new_pos);//�V�����ʒu��ݒ肵�܂��B
	void SetSize(VECTOR new_size);//�V�����傫����ݒ肵�܂��B
	void SetFill(bool new_fill);//�V���ɓh��Ԃ���ݒ肵�܂��B
	void SetThickness(float new_thickness);//�V���ɐ��̑�����ݒ肵�܂��B
	void SetScale(float new_scale_x, float new_scale_y);//�V���ɃX�P�[���l��ݒ肵�܂��B

	void SetName(string new_name);//�V���ɃI�u�W�F�N�g�̖��O��ݒ肵�܂��B
	void SetObjectNumber(int new_number);//�V�����I�u�W�F�N�g�ԍ���ݒ肵�܂��B
	void SetHitFlag(bool new_hit_flag);//�V�����q�b�g�t���O��ݒ肵�܂��B
	void SetMoveSpeed(VECTOR new_move_speed);//�V�����ړ����鑬�x��ݒ肵�܂��B(3���w���)
	void SetMoveSpeed(float angle, float new_move_speed);//�V�����ړ����鑬�x��ݒ肵�܂��B(���W�A���p�w���)
	void SetLife(float new_life);//�V����������ݒ肵�܂��B
	void SetDestoryFlag(bool new_flag);//�V�����폜�t���O��ݒ肵�܂��B
	void SetMainCameraFlag(bool new_flag);//�V�������C���J�����t���O��ݒ肵�܂��B(Camera�֐��ȊO����̎g�p�͍T����)

	void AddLife(float add_val);//�����J�E���g�𑫂��܂��B
	void SubLife(float sub_val);//�����J�E���g�������܂��B

	VECTOR GetPosition();//���݂̈ʒu���擾���܂��B
	VECTOR GetSize();//���݂̑傫�����擾���܂��B
	float GetScaleX();//���݂�X�����̃X�P�[���l���擾���܂��B
	float GetScaleY();//���݂�X�����̃X�P�[���l���擾���܂��B
	float GetThickness();//���݂̐��̑������擾���܂��B
	unsigned int GetColor();//���݂̐F���擾���܂��B
	bool GetFill();//���݂̓h��Ԃ��̐ݒ���擾���܂��B

	string GetName();//���݂̃I�u�W�F�N�g�̖��O���擾���܂��B
	int GetObjectNumber();//���݂̃I�u�W�F�N�g�̔ԍ����擾���܂��B
	bool GetHitFlag();//���݂̃I�u�W�F�N�g�̃q�b�g�t���O���擾���܂��B
	VECTOR GetMoveSpeed();//���݂̃I�u�W�F�N�g�̈ړ����x���擾���܂��B
	float GetMoveAngle();//���݂̃I�u�W�F�N�g�̈ړ����Ă�����p���擾���܂��B(���W�A��)
	float GetLife();//���݂̃I�u�W�F�N�g�̎������擾���܂��B
	bool GetDestoryFlag();//���݂̍폜�t���O���擾���܂��B(true�ō폜�ΏۃI��)	
	bool GetMainCameraFlag();//���݂̃I�u�W�F�N�g�����C���J�����̑ΏۂɂȂ��Ă��邩�̃t���O���擾���܂��B

};