#include "game_window_cursor.h"

void GameWindowCursor::Init()
{
	int char_size = 8;//文字の大きさ
}

void GameWindowCursor::Load()
{

}

void GameWindowCursor::Draw(int pos_x, int pos_y, char* strings_hitbox, char* strings, bool wire)
{
	DrawFormatString(pos_x, pos_y, GetColor(0, 0, 0), "%s", strings_hitbox);//ヒットボックス内の文字を表示

	if (hit_box.BoxColliderMouse(pos_x, strlen(strings_hitbox) * char_size, pos_y, 20, wire) == true)
	{
		DrawBox(hit_box.x + 10, hit_box.y, hit_box.x + strlen(strings) * char_size + 10, hit_box.y + 30, GetColor(150, 150, 150), TRUE);

		DrawFormatString(hit_box.x + 18, hit_box.y + 8, GetColor(0, 0, 0), "%s", strings);//カーソルヒット時の文字を表示
	}
}

void GameWindowCursor::ColliderOff()
{
	hit_box.active = false;
}

void GameWindowCursor::ColliderOn()
{
	hit_box.active = true;
}