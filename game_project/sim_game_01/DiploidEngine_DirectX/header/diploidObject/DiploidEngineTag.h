#pragma once
#include "DxLib.h"
#include <vector>
#include <string>

//変更非推奨マクロ
//レイヤー番号(0～4)
#define DIPLOID_LAYER_00 0
#define DIPLOID_LAYER_01 1
#define DIPLOID_LAYER_02 2
#define DIPLOID_LAYER_03 3
#define DIPLOID_LAYER_04 4


//仮マクロ(ダイスプログラムで使用)
#define OBJECT_NUMBER_POINT 0//ポイント
#define OBJECT_NUMBER_PLUS_BUTTON 1//プラスボタン
#define OBJECT_NUMBER_MINUS_BUTTON 2//マイナスボタン
#define OBJECT_NUMBER_CUSTOM_NUMBER_BUTTON 3//カスタムナンバーボタン
#define OBJECT_NUMBER_CLEAR_BUTTON 4//クリアボタン

//日付関連
//季節
const int NEXT_DAY = 1;
const int NEXT_SEASON = 1;
const int SPRING_SEASON = 1;
const int RAINY_SEASON = 2;
const int SUMMER_SEASON = 3;
const int WINTER_SEASON = 4;

//月(桃)
const int NEXT_MONTH = 1;
const int TANTOU_NO_TUKI = 1;
const int KOUTOU_NO_TUKI = 2;
const int NOUTOU_NO_TUKI = 3;

//月(青)
const int TANSEI_NO_TUKI = 4;
const int KOUSEI_NO_TUKI = 5;
const int NOUSEI_NO_TUKI = 6;

//月(赤)
const int TANSEKI_NO_TUKI = 7;
const int KOUSEKI_NO_TUKI = 8;
const int NOUSEKI_NO_TUKI = 9;

//月(白)
const int TANHAKU_NO_TUKI = 10;
const int KOUPAKU_NO_TUKI = 11;
const int NOUHAKU_NO_TUKI = 12;


//主要コマンド関連
const int NO_COMMAND		  = 0;//コマンド選択なし
const int CAMP_COMMAND		  = 1;//野営コマンド
const int INFORMATION_COMMAND = 2;//情報コマンド
const int MOVE_COMMAND		  = 3;//移動コマンド
const int PRODUCTION_COMMAND  = 4;//製作コマンド
const int RESEARCH_COMMAND	  = 5;//研究コマンド
const int EXPLORE_COMMAND	  = 6;//探索コマンド


//プレーヤーの向いている方向
const int PLAYER_DIRECTION_UP = 0;//上
const int PLAYER_DIRECTION_DOWN = 1;//下
const int PLAYER_DIRECTION_LEFT = 2;//左
const int PLAYER_DIRECTION_RIGHT = 3;//右
const int PLAYER_DIRECTION_LEFT_UP = 4;//左上
const int PLAYER_DIRECTION_RIGHT_UP = 5;//右上
const int PLAYER_DIRECTION_RIGHT_DOWN = 6;//右下
const int PLAYER_DIRECTION_LEFT_DOWN = 7;//左下

//プレーヤーの移動状態
const int PLAYER_WAIT = 0;//待機
const int PLAYER_WALK = 1;//歩き
const int PLAYER_RUN = 2;//走り

//ステータス異常関連
const int STATUS_INJURY_LV1 = 0;//負傷LV1
const int STATUS_INJURY_LV2 = 1;//負傷LV2
const int STATUS_INJURY_LV3 = 2;//負傷LV3
const int STATUS_INJURY_LV4 = 3;//負傷LV4
const int STATUS_INJURY_LV5 = 4;//負傷LV5


//タグ情報構造体
struct Tag
{
	int object_number;//オブジェクト番号
	int layer_number;//レイヤー番号
	std::string name_tag;//オブジェクト名
};

//Push関数以外未実装
class DiploidEngineTag
{
private:
	std::vector<Tag> tag_vector;

public:
	DiploidEngineTag();
	~DiploidEngineTag() {};


	int GetNumber(int target);//tag_vectorの前からtarget番目のobject_numberを返します。
	std::string GetObjectName(int target);//tag_vectorの前からtarget番目のobject_nameを返します。

	int GetNumber_tag_vector(int object_number);//object_numberで指定した配列が前から何番目なのかを返します。
	int GetNameTag_tag_vector(std::string object_name);//object_nameで指定した配列が前から何番目なのかを返します。

	void SortOnObjectNumber();//object_numberを基準に昇順に並べ替えます。

	//以下使用頻度が高くなるであろう関数
	Tag GetTag_target(int target);//tag_vectorの前からtarget番目のtagを返します。
	Tag GetTag_object_number(int object_number);//object_numberで指定した配列を見つけ出しそのtagを返します。
	Tag GetTag_name_tag(std::string object_name);//object_nameで指定した配列を見つけ出しそのtagを返します。

	int FindOnTagVector(Tag tag);//tag_vectorからtagを見つけ出し前から何番目なのかを返します。

	void Push(Tag tag);//タグを登録します。

	void Destory_target(int target);//tag_vectorの前からtarget番目のTagを削除します。
	void Destory_object_number(int object_number);//tag_vectorの中からobject_numberを見つけ出し削除します。
	void Destory_name_tag(std::string object_name);//tag_vectorの中からobject_nameを見つけ出し削除します。

};