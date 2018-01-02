#pragma once
#include "start.h"
#include "load.h"
#include "exit.h"
#include "option.h"

#include "fade_in.h"
#include "fade_out.h"

class StartScene
{
private:
	int flag;

	int back_wall_graphics;//�w�i�摜�n���h��

public:
	StartScene();

	FadeIn fade_in;
	FadeOut fade_out;

	Start start;
	Load load;
	Option option;
	Exit exit;

	int start_pos_x;//start_button�A�j���J�n�����ʒu
	int load_pos_x;//load_button�A�j���J�n�����ʒu
	int option_pos_x;//option_button�A�j���J�n�����ʒu
	int exit_pos_x;//exit_button�A�j���J�n�����ʒu

	float anime_x;//�A�j���̑��x

	int start_scene_flag;//-1�ŃQ�[���I���A0�ŃX�^�[�g��ʂ����[�v�A1��new game�A2�Ń��[�h��ʁA3�ŃI�v�V������ʁB

	void Load();
	void Init();

	void DrawStartScene(int window_x, int window_y, bool wire);

};