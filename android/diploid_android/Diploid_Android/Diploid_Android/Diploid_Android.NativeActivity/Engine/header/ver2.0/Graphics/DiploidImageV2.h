#pragma once
#include "DxLib.h"
#include  <string>
#include <cmath>

using namespace std;

class DiploidImageV2
{
private:
	string name = "no_name";//�I�u�W�F�N�g�̖��O(��Ɍ�������Ƃ��Ɏg�p)
	int layer_number;//���C���[�̔ԍ�(��ɓ����蔻�莞�ɂǂ̑w�ɋ���̂����ʂ���̂Ɏg�p)
	int object_number;//�I�u�W�F�N�g�̔ԍ�

	int graphics_handl;//�O���t�B�b�N�n���h��
	int graphics_x, graphics_y;//�I���W�i���̑傫��

	VECTOR graphics_size;//���낢��ύX���������傫��
	VECTOR move_speed;//�I�u�W�F�N�g�̈ړ��X�s�[�h
	float move_angle;//�I�u�W�F�N�g�̈ړ�����
	VECTOR center_position;//�摜�̒��S�ʒu
	VECTOR down_center_position;//�摜�̉��̒��S�ʒu

	VECTOR position;//�`��ʒu
	VECTOR rotate_position;//��]����ۂ̒��S�_
	VECTOR graphics_scale = { 1.0f,1.0f,1.0f };//�摜�̔{��
	float angle;//��]�p�x
	bool turn = FALSE;//���E���]�̃t���O

	float object_life;//����

	bool destory_flag = false;//�폜�t���O(true�̏ꍇ�A�폜�Ώۂ�)
	bool hit_flag = false;//�������Ă��邩�̃t���O
	bool main_camera = false;//���C���J�����̒ǂ��I�u�W�F�N�g���̃t���O
	bool active = false;

protected:

public:
	void Load(const char* path);//�摜��ǂݍ��݂܂��B
	void Init(VECTOR pos, bool shift_flag = true);//�ǂݍ��񂾉摜�����������܂��B(shift_flag��true�ŉ摜�𒆐S�ɂ��ĕ`�悵�܂��B)
	void MoveUpdate();//�ݒ肵���ړ����x�𔽉f���܂��B
	void Draw(bool draw = true);//�摜��`�悵�܂��B

	void SetHandl(int new_handl);//�摜�n���h����ݒ肵�܂��B
	void SetScale(float scale_x, float scale_y);//�摜�̕\���{����ύX���܂��B
	void SetAngle(float new_angle);//�V������]�p��ݒ肵�܂��B
	void SetPosition(VECTOR new_position);//�V�����\���ʒu��ݒ肵�܂��B
	void SetTurnFlag(bool new_flag);//�V�����摜���]�t���O��ݒ肵�܂��B
	void SetRotatePosition(VECTOR new_position);//�V������]����ݒ肵�܂��B
	void SetBright(float scale = 1.0f);//���邳��ݒ肵�܂��B(1.0f��100%)
	void SetBright(int red, int green, int blue);//���邳���w�肵�܂��B

	void SetMoveSpeed(VECTOR new_move_speed);//�V�����ړ����鑬�x��ݒ肵�܂��B(3���w���)
	void SetMoveSpeed(float angle, float new_move_speed);//�V�����ړ����鑬�x��ݒ肵�܂��B(���W�A���p�w���)
	void SetName(string new_name);//�V���ɃI�u�W�F�N�g�̖��O��ݒ肵�܂��B
	void SetLife(float new_life);//�V����������ݒ肵�܂��B
	void SetDestoryFlag(bool new_flag);//�V�����폜�t���O��ݒ肵�܂��B
	void SetMainCameraFlag(bool new_flag);//�V�������C���J�����t���O��ݒ肵�܂��B(Camera�֐��ȊO����̎g�p�͍T����)
	void SetObjectNumber(int new_number);//�V�����I�u�W�F�N�g�ԍ���ݒ肵�܂��B
	void SetHitFlag(bool new_hit_flag);//�V�����q�b�g�t���O��ݒ肵�܂��B
	void SetActiveFlag(bool new_active_flag);

	void AddLife(float add_val);//�����J�E���g�𑫂��܂��B
	void SubLife(float sub_val);//�����J�E���g�������܂��B

	int GetGraphicsHandl();//�ǂݍ��܂ꂽ���݂̃O���t�B�b�N�n���h�����擾���܂��B
	VECTOR GetScale();//���݂̉摜�̕\���{�����擾���܂��B
	VECTOR GetSize();//���݂̉摜�̑傫�����擾���܂��B
	VECTOR GetPosition();//���݂̉摜�̍���̈ʒu���擾���܂��B
	VECTOR GetCenterPosition();//���݂̉摜�̒��S�ʒu���擾���܂��B
	VECTOR GetRotatePosition();//���݂̉摜�̉�]�����W���擾���܂��B
	VECTOR GetDownCenterPosition();//���݂̉摜�̍����̍��W���擾���܂��B
	float GetAngle();//���݂̉摜�̉�]�p���擾���܂��B(���W�A��)
	bool GetTurnFlag();//���݂̉摜���]�t���O���擾���܂��B(TRUE�Ŕ��])
	bool GetActiveFlag();

	VECTOR GetMoveSpeed();//���݂̃I�u�W�F�N�g�̈ړ����x���擾���܂��B
	float GetMoveAngle();//���݂̃I�u�W�F�N�g�̈ړ����Ă�����p���擾���܂��B(���W�A��)
	string GetName();//���݂̃I�u�W�F�N�g�̖��O���擾���܂��B
	float GetLife();//���݂̃I�u�W�F�N�g�̎������擾���܂��B
	bool GetDestoryFlag();//���݂̍폜�t���O���擾���܂��B(true�ō폜�ΏۃI��)	
	bool GetMainCameraFlag();//���݂̃I�u�W�F�N�g�����C���J�����̑ΏۂɂȂ��Ă��邩�̃t���O���擾���܂��B
	int GetObjectNumber();//���݂̃I�u�W�F�N�g�̔ԍ����擾���܂��B
	bool GetHitFlag();//���݂̃I�u�W�F�N�g�̃q�b�g�t���O���擾���܂��B

};