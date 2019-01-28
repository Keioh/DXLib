#pragma once
#include "DxLib.h"


#define DIPLOID_ENGINE_UI 0
#define DIPLOID_ENGINE_GAMEOBJECT 1
#define DIPLOID_ENGINE_MAP_HIT_OBJECT 2//マップとキャラクタのヒットレイヤー
#define DIPLOID_ENGINE_PLAYER_ENEMY_HIT_OBJECT 3//PLAYERとENEMYのヒットレイヤー(例：攻撃判定など)

#define OBJECT_NUMBER_PLAYER_BODY 0//本体(攻撃ヒット判定に使用)
#define OBJECT_NUMBER_PLAYER_UP 1//上
#define OBJECT_NUMBER_PLAYER_LEFT 2//左
#define OBJECT_NUMBER_PLAYER_RIGHT 3//右
#define OBJECT_NUMBER_PLAYER_DOWN 4//下
#define OBJECT_NUMBER_PLAYER_MAX OBJECT_NUMBER_PLAYER_DOWN + 1//PLAYER_DOWNの数値(マクロ追加で４以上になる場合はこの数値も同じく増やす。)


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