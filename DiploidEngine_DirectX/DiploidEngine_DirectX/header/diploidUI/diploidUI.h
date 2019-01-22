#pragma once
#include "DxLib.h"
#include "diploidObject/DiploidEngineObjectInformation.h"
#include "diploidObject/DiploidEngineObject.h"


class DiploidUI : public DiploidEngineObjectInformation
{
private:


public:
	DiploidUI();//コンストラクタ
	~DiploidUI();//デストラクタ

	void Init();//初期化処理
	void Update();//アニメアプデ処理

	void Draw() {};//たぶん使わない。
};