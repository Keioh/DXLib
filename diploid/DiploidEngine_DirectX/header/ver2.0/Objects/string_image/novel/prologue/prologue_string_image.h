#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "system\DiploidEngineSetting.h"
#include "diploidScreen\DiploidEngineScreen.h"

class PrologueStringImage
{
private:
	//Optionの画像
	VECTOR position = VGet(0, 0, 0);
	DiploidImageV2 prologue_images;
	DiploidImageV2 zyo_images;
	DiploidImageV2 black_back_images;


	DiploidImageV2 string_images[13];

	bool fead_flag = false;//trueになるとフェードアウト開始
	float fead_count;
	int next_fead_time = 100;//フェードアウトを開始するまでの時間

	float string_alpha[13];//各画像のアルファ値

	int anime_pos_init = -25;

	int alpha_speed = 150;//透過速度

	bool finish = false;

public:
	void Load();
	void Init(DiploidEngineSetting& setting, VECTOR pos);
	void Updata(DiploidEngineScreen& screen);
	void Draw(bool draw = true, bool debug = false);

	void NextAnimation();//次のアニメーションを再生します。

	void Reset();//アニメーションをリセットします。

	bool GetFinish();//再生完了フラグを得ます(treuで完了)
};