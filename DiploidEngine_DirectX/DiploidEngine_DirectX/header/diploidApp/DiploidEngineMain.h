//このファイルですべての処理をまとめてDiploidEngineAppに渡す

#pragma once
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidObject\DiploidEngineTag.h"
#include "diploidImpact\DiploidEngineImpact.h"
#include "diploidLayer\DiploidEngineLayer.h"
#include "diploidNetwork\DiploidEngineNetwork.h"

class DiploidEngineMain
{
private:

public:	

	DiploidEngineTag diploidEngineTag;//タグ名で使用

	DiploidEngineSetting diploidEngineSetting;//エンジン初期化や設定などの処理。
	DiploidEngineLayer diploidEngineLayer;//レイヤーシステム処理
	DiploidEngineImpact diploidEngineImpact;//衝突処理
	DiploidEngineNetwork diploidEngineNetwork;//ネットワーク機能処理

	//以下、よく使う変数を関数として登録
	VECTOR WindowSize();//windowサイズを取得(z値はBIT)
};