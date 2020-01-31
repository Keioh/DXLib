#pragma once
#include <string>
#include "DxLib.h"

using namespace std;

//2Dの円に関するクラス(スタンドアローンなクラスとして実装)
class DiploidCircleV2
{
private:
	string name;//オブジェクトの名前(主に検索するときに使用)
	int layer_number;//レイヤーの番号(主に当たり判定時にどの層に居るのか判別するのに使用)

	VECTOR position;//オブジェクトの位置
	float radius;//円の半径(実質、Size)

	unsigned int object_color;//色
	bool object_fill;//塗りつぶし
	float object_thickness;//太さ

protected:

public:

	void Init(VECTOR pos, float radi, unsigned int color, bool fill = TRUE, float thickness = 1.0f);
	void Updata();
	void Draw(bool draw = true);//円を描画します。(drawにfalseを入れることで描画しない)

	void SetColor(unsigned int color);//新しい色を設定します。
	void SetPosition(VECTOR new_pos);//新しい位置を設定します。
	void SetRadius(float new_radius);//新しい半径を設定します。
	void SetFill(bool new_fill);//新たに塗りつぶしを設定します。
	void SetThickness(float new_thickness);//新たに線の太さを設定します。

	VECTOR GetPosition();//現在の位置を取得します。
	float GetRadius();//現在の半径を取得します。
	float GetThickness();//現在の線の太さを取得します。
	unsigned int GetColor();//現在の色を取得します。
	bool GetFill();//現在の塗りつぶしの設定を取得します。
};
