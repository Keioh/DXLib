//オブジェクトを描写する順番を決めるためのレイヤーシステム

#pragma once
#include <vector>
#include "DxLib.h"
#include "diploidGraphics\diploidImage.h"

class DiploidEngineLayer
{
private:
	float top_byte;
	float mid_byte;
	float bot_byte;
	int top_size;
	int mid_size;
	int bot_size;

public:
	std::vector<DiploidImage> image_top_vector;
	std::vector<DiploidImage> image_mid_vector;
	std::vector<DiploidImage> image_bot_vector;

	void GetSize();//各配列の大きさを取得

	void PushTopGraphics(DiploidImage image);
	void PushMidGraphics(DiploidImage image);
	void PushBotGraphics(DiploidImage image);

	void Updata();
	void Draw(bool debug = false, bool draw = true);
	void Destory();//destory変数がtureの場合、要素を削除

	void DestoryTop();//top配列から要素を削除
	void DestoryMid();//mid配列から要素を削除
	void DestoryBot();//bot配列から要素を削除


	//アニメーション値を変更する関数。
	//TOP(Position)
	void SetTOPAnimationPosition(int number, VECTOR move_speed = { 0.0f,0.0f,0.0f });//top配列の指定のオブジェクト番号の画像の座標アニメーション値を変更する。
	void SetTOPAnimationPositionX(int number, float move_speed = 0.0f);//top配列の指定のオブジェクト番号の画像のX座標アニメーション値を変更する。
	void SetTOPAnimationPositionY(int number, float move_speed = 0.0f);//top配列の指定のオブジェクト番号の画像のY座標アニメーション値を変更する。

	void SetTOPPositionYAdd(int number, float move_speed = 0.0f);//top配列の指定のオブジェクト番号の画像のY座標に値をたす。

	void SetTOPPosition(int number, VECTOR position = {0.0f,0.0f,0.0f});//top配列の指定のオブジェクト番号の画像の座標をセットする。


	void SetMIDAnimationPosition(int number, VECTOR move_speed = { 0,0,0 });//mid配列の指定のオブジェクト番号の画像の座標アニメーション値を変更する。
	void SetBOTAnimationPosition(int number, VECTOR move_speed = { 0,0,0 });//bot配列の指定のオブジェクト番号の画像の座標アニメーション値を変更する。

	void SetTOPAnimationAngle(int number, float angle = 0.0f);//top配列の指定のオブジェクト番号の画像の回転アニメーション値を変更する。
	void SetMIDAnimationAngle(int number, float angle = 0.0f);//mid配列の指定のオブジェクト番号の画像の回転アニメーション値を変更する。
	void SetBOTAnimationAngle(int number, float angle = 0.0f);//bot配列の指定のオブジェクト番号の画像の回転アニメーション値を変更する。

	void SetTOPAnimationSize(int number, VECTOR size = { 0,0,0 });//top配列の指定のオブジェクト番号の画像の大きさアニメーション値を変更する。
	void SetMIDAnimationSize(int number, VECTOR size = { 0,0,0 });//mid配列の指定のオブジェクト番号の画像の大きさアニメーション値を変更する。
	void SetBOTAnimationSize(int number, VECTOR size = { 0,0,0 });//bot配列の指定のオブジェクト番号の画像の大きさアニメーション値を変更する。

	void SetTOPAnimationScale(int number, float scale = 0.0f);//top配列の指定のオブジェクト番号の画像の拡大縮小アニメーション値を変更する。(使用非推奨。サイズ変更する場合は上記のSize()関数を使うこと)
	void SetMIDAnimationScale(int number, float scale = 0.0f);//mid配列の指定のオブジェクト番号の画像の拡大縮小アニメーション値を変更する。(使用非推奨。サイズ変更する場合は上記のSize()関数を使うこと)
	void SetBOTAnimationScale(int number, float scale = 0.0f);//bot配列の指定のオブジェクト番号の画像の拡大縮小アニメーション値を変更する。(使用非推奨。サイズ変更する場合は上記のSize()関数を使うこと)


	//オブジェクト番号を調べる関数。
	int GetTOPNumber(int target);//top配列の最初から数えてｘ番目のオブジェクト番号を取得する。
	int GetMIDNumber(int target);//mid配列の最初から数えてｘ番目のオブジェクト番号を取得する。
	int GetBOTNumber(int target);//bot配列の最初から数えてｘ番目のオブジェクト番号を取得する。

	//指定のオブジェクト番号を変更する関数。(要検証)
	void SetTOPNumber(int target_number, int set_number);//top配列の指定データのオブジェクト番号(number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)
	void SetMIDNumber(int target_number, int set_number);//mid配列の指定データのオブジェクト番号(number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)
	void SetBOTNumber(int target_number, int set_number);//bot配列の指定データのオブジェクト番号(number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)


	//レイヤー番号を調べる関数。
	int GetTOPLayerNumber(int target);//top配列の最初から数えてｘ番目のレイヤー番号を取得する。
	int GetMIDLayerNumber(int target);//mid配列の最初から数えてｘ番目のレイヤー番号を取得する。
	int GetBOTLayerNumber(int target);//bot配列の最初から数えてｘ番目のレイヤー番号を取得する。

	//指定のレイヤー番号を変更する関数。(要検証)
	void SetTOPLayerNumber(int target_number, int set_number);//top配列の指定データのレイヤー番号(layer_number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)
	void SetMIDLayerNumber(int target_number, int set_number);//mid配列の指定データのレイヤー番号(layer_number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)
	void SetBOTLayerNumber(int target_number, int set_number);//bot配列の指定データのレイヤー番号(layer_number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)

};