#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "diploidScreen\DiploidEngineScreen.h"

class LogoScene
{
private:
	DiploidEngineSetting setting;

	DiploidScreenGraphics scr_gra;

	DiploidEngineInput input;

	DiploidImageV2 logo;
	DiploidImageV2 logo_lib;

	float mosaic = 0.0f;

	float alpha = 0;
	float alpha_speed = 50;//���߃X�s�[�h

	int scene_number = 0;

	int main_log_time;

	int main_logo_draw_time = 60;//���C�����S�̕\������

	int r = 255, g = 255, b = 255;
	int back_ground_speed = 15;//�w�i�F�̕ω����x


public:
	void Load();

	void Init();

	void Updata(DiploidEngineScreen& screen);

	void Draw();

	bool GetFinalScene();

};