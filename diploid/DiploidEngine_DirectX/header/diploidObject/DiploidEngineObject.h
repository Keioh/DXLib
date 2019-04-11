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
#include "diploidPhysics/diploidPhysics.h"
#include "diploidObject/DiploidEngineTag.h"

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

	Tag tag;//タグ情報の作成(AppにあるdiploidEngineTagのPush関数に代入)
	DiploidEngineTag tag_system;//タグシステムの作成(AppにあるdiploidEngineTagとは別に新しくシステムを作成したい場合に使用)

	DiploidEngineInput input;//入力機器キーボードやマウス、パッドなど(Appのほうで使ったほうが無駄なメモリを消費しないですむ。シングルトン実装しなければ)

	DiploidPhysics physics;//物理計算

	void Init();
	void Updata();
	void Draw(bool debug = true);

};