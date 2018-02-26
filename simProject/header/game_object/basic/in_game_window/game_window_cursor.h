#pragma once
#include "DxLib.h"
#include "FileInput.h"
#include "Collision.h"

class GameWindowCursor
{
private:
	Collision hit_box;

public:

	int char_size = 8;//�����̑傫��

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, char* strings_hitbox, char* strings, bool wire = false);//(x�ʒu�y�ʒu��q�b�g�{�b�N�X���̕�����J�[�\���E�B���h�E���̕�������C���[�\��)
	void ColliderOff();
	void ColliderOn();
};