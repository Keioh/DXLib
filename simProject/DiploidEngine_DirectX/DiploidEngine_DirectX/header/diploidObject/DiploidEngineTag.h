#pragma once
#include "DxLib.h"

#define DIPLOID_ENGINE_UI 0//UI
#define DIPLOID_ENGINE_GAMEOBJECT 1//ゲームオブジェクト

#define PLAYER 100//プレーヤー
#define NEUTRAL 101//中立
#define ENEMY 102//敵
#define UNEXPLORED 103//未開(プレーヤーでも敵の土地でもない)


//地域
#define REGION_01 1000
#define REGION_02 1001
#define REGION_03 1002
#define REGION_04 1003
#define REGION_05 1004
#define REGION_06 1005
#define REGION_07 1006
#define REGION_08 1007
#define REGION_09 1008
#define REGION_10 1009
#define REGION_11 1010
#define REGION_12 1011


//法律関連
#define LAW_BUTTON 2000


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