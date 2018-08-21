//オブジェクトまとめ

#pragma once
#include "DxLib.h"
#include "diploidGraphics\diploidBox.h"
#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"
#include "diploidGraphics\diploidImage.h"
#include "diploidSound\diploidEnigneSound.h"
#include "diploidInput\DiploidEngineInput.h"

class DiploidObject
{
private:

public:
	DiploidBox box;//四角
	DiploidCircle circle;//円
	DiploidPoint point;//点

	DiploidImage image;//画像

	DiploidEngineSound sound;//音

	DiploidEngineInput input;//入力(Appのほうで使ったほうが無駄なメモリを消費しないですむ。シングルトン実装しなければ)

	void Init();
	void Updata();
	void Draw(bool debug = true);

};