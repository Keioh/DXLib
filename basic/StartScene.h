#pragma once
#include "start.h"
#include "load.h"
#include "exit.h"
#include "option.h"

class StartScene
{
private:

public:
	Start start;
	Load load;
	Option option;
	Exit exit;

	int start_scene_flag;//-1�ŃQ�[���I���A0�ŃX�^�[�g��ʂ����[�v�A1��new game�A2�Ń��[�h��ʁA3�ŃI�v�V������ʁB

	void LoadGraphics();
	void Init();

	void DrawStartScene(int window_x, int window_y, bool wire);

};