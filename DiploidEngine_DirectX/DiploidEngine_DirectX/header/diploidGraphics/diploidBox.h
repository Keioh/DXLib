#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"


class DiploidBox : public DiploidEngineObjectInformation
{
private:
	VECTOR center_position;//四角の中心点の座標
	VECTOR anime_position, anime_size;//アニメーション用バッファ
	VECTOR origin_position, origin_size;//オリジナルの大きさ
	//int mouse_x, mouse_y;

public:

	DiploidBox();
	~DiploidBox();


	void Init(VECTOR position = { 0,0,0 }, VECTOR size = { 0,0,0 });//マウスに追従させる場合は{0,0,0}を代入
	void Update();//ポジションなどの数値を変更したら必ず呼ばないと結果が反映されない。
	void Draw(bool wire = true);

	VECTOR SetCenterPosition(VECTOR new_center_position);//中央ポジションを任意の数値に変更する。(戻り値はnew_center_positionを返す)

	VECTOR GetSize();//縦と横の大きさを返します。
	VECTOR GetPosition(VECTOR get_pos = { 0,0,0 });//指定した場所の位置を返します。例)get_posに{1,0,0}を代入→四角の右上のポジションを指定→位置をVECTOR型で返す。
	VECTOR GetCenterPosition();//中央の位置を返します。

	void Destory() { impacted = destory = true; };//削除します。
};