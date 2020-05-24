#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "diploidInput/DiploidEngineInput.h"
#include "ver2.0/Main/Collision.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"

//軍事コマンド関連の処理
class MilitaryUI
{
private:
	//メインUI関連
	DiploidImageV2 image;
	DiploidBoxV2 box;
	DiploidCollision collision;

	bool hit = false;
	

	//爵位選択関連
	DiploidImageV2 king_image;
	DiploidSelectedUIV2 king;//王

	DiploidImageV2 duke_image;
	DiploidSelectedUIV2 duke[2];//公爵

	DiploidImageV2 marquess_one_image;
	DiploidSelectedUIV2 marquess_one;//侯爵その１
	DiploidSelectedUIV2 marquess_two;//侯爵その2

	DiploidImageV2 viscount_one_image;
	DiploidSelectedUIV2 viscount_one;//子爵その１
	DiploidSelectedUIV2 viscount_two;//子爵その2

	DiploidImageV2 baron_one_image;
	DiploidSelectedUIV2 baron_one;//男爵その１
	DiploidSelectedUIV2 baron_two;//男爵その2

public:
	void Load();
	void Init(VECTOR pos, float scale = 1.0f);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	bool GetHit();
};