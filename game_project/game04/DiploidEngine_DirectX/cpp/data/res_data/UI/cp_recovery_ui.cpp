#include "data/res_data/UI/cp_recovery_ui.h"

void CpRecoveryUI::LoadGraphics()
{
	image[0].Load("texter/res/cp_recovery/back.png");
	number.Load();
}

void CpRecoveryUI::LoadGraphicsHandle()
{

}

void CpRecoveryUI::Init(VECTOR pos, float scale)
{
	image[0].Init(pos, false);
	image[0].SetScale(scale, scale);

	number.Init(VGet(pos.x + (40 * scale), pos.y + (25 * scale), pos.z), scale);
}

void CpRecoveryUI::Updata(Player player)
{
	//playerÇ©ÇÁhp_recoveryÇÃèÓïÒÇìæÇÈ
	cp_recovery = player.GetCpRecoveryProbability();
	number.Update(cp_recovery);
}

void CpRecoveryUI::Draw(bool draw)
{
	image[0].Draw(draw);
	number.Draw(draw);
}