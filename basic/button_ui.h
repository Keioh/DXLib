#pragma once
#include <iostream>

#include "Object_Base.h"
#include "Collision.h"
#include "Input.h"

class ButtonUI : public ObjectBase
{
private:
	Input mouse_input;

	float wheel_volume;

	int mouse_x, mouse_y;

	int graphics;
	int click_flag;//�N���b�N�������ǂ����̃t���O

public:
	ButtonUI();

	Collision box_collision;
	Collision circle_collision;

	int switch_flag;//�X�C�b�`�t���O

	float wheel_volume_buffer;

	void Load(char* path);
	void Init();

	int BoxUI_Button(int pos_x, int pos_y, float scale_x, float scale_y, int input = MOUSE_INPUT_LEFT, bool wire = false);//�o�O�ɂ��X�P�[���̒l��1.0f�Ŏg�����ƁB�i�߂�l�̓N���b�N�t���O���Ԃ�B1�ŃN���b�N�A0�ŃN���b�N���Ă��Ȃ��B�j
	int BoxUI_Button_Continuation(int pos_x, int pos_y, float scale_x, float scale_y, int input = MOUSE_INPUT_LEFT, bool wire = false);//�o�O�ɂ��X�P�[���̒l��1.0f�Ŏg�����ƁB�i�߂�l�̓N���b�N�t���O���Ԃ�B1�ŃN���b�N�A0�ŃN���b�N���Ă��Ȃ��B�j
	int BoxUI_Button_Switch(int pos_x, int pos_y, float scale_x, float scale_y, int input = MOUSE_INPUT_LEFT, bool wire = false);//�o�O�ɂ��X�P�[���̒l��1.0f�Ŏg�����ƁB�i�߂�l�̓N���b�N�t���O���Ԃ�B1�ŃN���b�N�A0�ŃN���b�N���Ă��Ȃ��B�j

	int BoxUI_WheelVertical(int pos_x, int pos_y, unsigned int color, bool wire = false);//�c�����ւ̃X���C�_�[
	int BoxUI_WheelHorizontal(int pos_x, int pos_y, unsigned int color, bool wire = false);//�������ւ̃X���C�_�[(�o�O����)

	int CircleUI_Button(int pos_x, int pos_y, int size_r, int input = MOUSE_INPUT_LEFT, bool wire = false);//�߂�l�̓N���b�N�t���O���Ԃ�B1�ŃN���b�N�A0�ŃN���b�N���Ă��Ȃ��B�j

};