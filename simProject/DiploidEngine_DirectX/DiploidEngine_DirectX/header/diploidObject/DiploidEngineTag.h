#pragma once
#include "DxLib.h"


#define PLAYER 0//プレーヤー
#define NEUTRAL 1//中立
#define ENEMY 2//敵
#define UNEXPLORED 3//未開(プレーヤーでも敵の土地でもない)

#define DIPLOID_ENGINE_UI 0//UI
#define DIPLOID_ENGINE_GAMEOBJECT 1//ゲームオブジェクト

//地域
#define REGION_01 10
#define REGION_02 11
#define REGION_03 12
#define REGION_04 13
#define REGION_05 14
#define REGION_06 15
#define REGION_07 16
#define REGION_08 17
#define REGION_09 18
#define REGION_10 19
#define REGION_11 20
#define REGION_12 21


//今のところ使わない
class DiploidEngineTag
{
private:

public:

	//タグ登録
	enum NAME
	{
		test
	};
};