#pragma once
#include "DxLib.h"
#include "FileInput.h"
#include "Collision.h"

class GameWindowCursor
{
private:
	Collision hit_box;

public:

	int char_size = 8;//文字の大きさ

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, char* strings_hitbox, char* strings, bool wire = false);//(x位置､y位置､ヒットボックス内の文字､カーソルウィンドウ内の文字､ワイヤー表示)
	void ColliderOff();
	void ColliderOn();
};