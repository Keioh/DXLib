#include "game_window_cursor.h"

void GameWindowCursor::Init()
{
	int char_size = 8;//�����̑傫��
}

void GameWindowCursor::Load()
{

}

void GameWindowCursor::Draw(int pos_x, int pos_y, char* strings_hitbox, char* strings, bool wire)
{
	if (hit_box.BoxColliderMouse(pos_x, strlen(strings_hitbox) * char_size, pos_y, 30, wire) == true)
	{
		DrawBox(hit_box.x, hit_box.y, hit_box.x + strlen(strings_hitbox) * char_size, hit_box.y + 30, GetColor(0, 0, 0), TRUE);

		DrawFormatString(pos_x, pos_y, GetColor(0, 0, 0), "%s", strings);//�J�[�\���q�b�g���̕�����\��
	}

	DrawFormatString(pos_x, pos_y, GetColor(0, 0, 0), "%s", strings_hitbox);//�q�b�g�{�b�N�X���̕�����\��

}