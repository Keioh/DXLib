#pragma once
#include "DxLib.h"


#define DIPLOID_ENGINE_UI 0
#define DIPLOID_ENGINE_GAMEOBJECT 1
#define DIPLOID_ENGINE_MAP_HIT_OBJECT 2//マップとキャラクタのヒットレイヤー
#define DIPLOID_ENGINE_PLAYER_ENEMY_HIT_OBJECT 3//PLAYERとENEMYのヒットレイヤー(例：攻撃判定など)

#define OBJECT_NUMBER_POINT 0//ポイント
#define OBJECT_NUMBER_PLUS_BUTTON 1//プラスボタン
#define OBJECT_NUMBER_MINUS_BUTTON 2//マイナスボタン
#define OBJECT_NUMBER_CUSTOM_NUMBER_BUTTON 3//カスタムナンバーボタン
#define OBJECT_NUMBER_CLEAR_BUTTON 4//クリアボタン


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