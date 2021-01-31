#include "ver2.0/Objects/OptionScene.h"

void OptionScene::Load()
{
	back_button.Load();
}

void OptionScene::Init(DiploidEngineSetting& setting)
{
	back_button.Init(VGet(setting.window_x - (128 + 4), setting.window_y - (32 + 4), 0));
}

void OptionScene::Updata(DiploidEngineInput& input)
{
	SetBackgroundColor(255, 255, 255);

	back_button.Update(input);
}

void OptionScene::Draw(bool draw, bool debug)
{
	back_button.Draw(draw, debug);
}


bool OptionScene::GetReturnFlag()
{
	if ((back_button.GetHit() == true) && (back_button.GetClick() == true))
	{
		return true;
	}

	return false;
}