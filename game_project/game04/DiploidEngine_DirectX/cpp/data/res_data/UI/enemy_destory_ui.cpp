#include "data/res_data/UI/enemy_destory_ui.h"

void EnemyDestoryUI::LoadGraphics()
{
	image[0].Load("texter/res/NumberDestroyed/number_destroyed.png");
	number.Load();
}

void EnemyDestoryUI::LoadGraphicsHandle()
{

}

void EnemyDestoryUI::Init(VECTOR pos, float scale)
{
	image[0].Init(VGet(pos.x + (20 * scale), pos.y, pos.z), false);
	image[0].SetScale(scale, scale);

	number.Init(VGet(pos.x - (20 * scale), pos.y + (20.0f * scale), pos.z), scale);
}

void EnemyDestoryUI::Updata(Player player)
{
	//player‚©‚çEnemyDestoryVolume‚Ìî•ñ‚ğ“¾‚é
	enemy_destory_volume = player.GetEnemyDestoryVolume();

	number.Update(enemy_destory_volume);
}

void EnemyDestoryUI::Draw(bool draw)
{
	image[0].Draw(draw);
	number.Draw(draw);
}