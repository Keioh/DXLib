//このファイルですべての処理をまとめてDiploidEngineAppに渡す

#pragma once
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"

class DiploidEngineMain
{
private:

public:
	DiploidEngineSetting diploidEngineSetting;//エンジン初期化や設定などの処理。


	//以下、よく使う変数を関数として登録
	VECTOR WindowSize();//windowサイズを取得(z値はBIT)
};