//オブジェクトまとめ

#pragma once
#include "DxLib.h"
#include "diploidGraphics\diploidBox.h"
#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"
#include "diploidGraphics\diploidLine.h"
#include "diploidGraphics\diploidImage.h"
#include "diploidSound\diploidEnigneSound.h"
#include "diploidInput\DiploidEngineInput.h"
#include "diploidInput\DiploidEnigneFile.h"
#include "diploidObject\DiploidMap.h"
#include "diploidPhysics/diploidPhysics.h"//重力などの物理計算

class DiploidObject
{
private:

public:
	DiploidBox box;//四角
	DiploidCircle circle;//円
	DiploidPoint point;//点
	DiploidLine line;//線分

	DiploidImage image;//画像

	DiploidEngineSound sound;//音
	
	DiploidEngineFile file;//ファイル入出力
	DiploidMap map;//マップ作製

	DiploidEngineInput input;//入力機器キーボードやマウス、パッドなど(Appのほうで使ったほうが無駄なメモリを消費しないですむ。シングルトン実装しなければ)

	DiploidPhysics physics;//物理計算

	void Init();
	void Updata();
	void Draw(bool debug = true);

};