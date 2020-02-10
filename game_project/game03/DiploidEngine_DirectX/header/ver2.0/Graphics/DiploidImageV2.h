#pragma once
#include "DxLib.h"

class DiploidImageV2
{
private:
	int graphics_handl;//�O���t�B�b�N�n���h��
	int graphics_x, graphics_y;//�I���W�i���̑傫��

	VECTOR graphics_size;//���낢��ύX���������傫��

	VECTOR position;//�`��ʒu
	VECTOR rotate_position;//��]����ۂ̒��S�_
	VECTOR graphics_scale = { 1.0f,1.0f,1.0f };//�摜�̔{��
	float angle;//��]�p�x
	bool turn = FALSE;//���E���]�̃t���O

protected:

public:
	void Load(const char* path);//�摜��ǂݍ��݂܂��B
	void Init(VECTOR pos, bool shift_flag = true);//�ǂݍ��񂾉摜�����������܂��B(shift_flag��true�ŉ摜�𒆐S�ɂ��ĕ`�悵�܂��B)
	void MoveUpdata();//�ݒ肵���ړ����x�𔽉f���܂��B
	void Draw(bool draw = true);//�摜��`�悵�܂��B

	void SetScale(float scale_x, float scale_y);//�摜�̕\���{����ύX���܂��B
	void SetAngle(float new_angle);//�V������]�p��ݒ肵�܂��B
	void SetPosition(VECTOR new_position);//�V�����\���ʒu��ݒ肵�܂��B
	void SetTurnFlag(bool new_flag);//�V�����摜���]�t���O��ݒ肵�܂��B
	void SetRotatePosition(VECTOR new_position);//�V������]����ݒ肵�܂��B
	void SetMoveSpeed(VECTOR new_move_speed);//�V�����ړ����鑬�x��ݒ肵�܂��B(3���w���)
	void SetMoveSpeed(float angle, float new_move_speed);//�V�����ړ����鑬�x��ݒ肵�܂��B(���W�A���p�w���)

	int GetGraphicsHandl();//�ǂݍ��܂ꂽ���݂̃O���t�B�b�N�n���h�����擾���܂��B
	VECTOR GetScale();//���݂̉摜�̕\���{�����擾���܂��B
	VECTOR GetSize();//���݂̉摜�̑傫�����擾���܂��B
	VECTOR GetPosition();//���݂̉摜�̈ʒu���擾���܂��B
	VECTOR GetRotatePosition();//���݂̉摜�̉�]�����W���擾���܂��B
	float GetAngle();//���݂̉摜�̉�]�p���擾���܂��B(���W�A��)
	bool GetTurnFlag();//���݂̉摜���]�t���O���擾���܂��B(TRUE�Ŕ��])
	VECTOR GetMoveSpeed();//���݂̃I�u�W�F�N�g�̈ړ����x���擾���܂��B
	float GetMoveAngle();//���݂̃I�u�W�F�N�g�̈ړ����Ă�����p���擾���܂��B(���W�A��)

};