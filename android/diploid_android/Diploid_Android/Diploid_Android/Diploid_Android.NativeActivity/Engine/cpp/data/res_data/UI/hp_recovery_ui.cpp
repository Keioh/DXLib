#include "data/res_data/UI/hp_recovery_ui.h"

void HpRecoveryUI::LoadGraphics()
{
	image[0].Load("res/hp_recovery/back.png");
	number.Load();
}

void HpRecoveryUI::LoadGraphicsHandle()
{

}

void HpRecoveryUI::Init(VECTOR pos, float scale)
{
	image[0].Init(pos, false);
	image[0].SetScale(scale, scale);

	number.Init(VGet(pos.x + (40 * scale), pos.y + (25 * scale), pos.z), scale);
}

void HpRecoveryUI::Updata(Player player)
{
	//playerÇ©ÇÁhp_recoveryÇÃèÓïÒÇìæÇÈ
	hp_recovery = player.GetHpRecoveryProbability();
	number.Update(hp_recovery);
}

void HpRecoveryUI::Draw(bool draw)
{
	image[0].Draw(draw);
	number.Draw(draw);
}