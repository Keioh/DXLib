#pragma once
#include <string>
#include "DxLib.h"

class DiploidEngineObjectInformation
{
private:

public:
	std::string name_tag = "no_name";//付けたい名前を入れる。型はstring型です。

	bool mouse_point_move_flag = false;//trueにするとマウスに追従
	bool center_position_draw_flag = false;//trueにすると中央に設定されている場所に点が表示される(マウス追従の場合は無効)
	VECTOR position;//位置
	VECTOR size;//大きさ(zは円の半径)	
	int mouse_position_x, mouse_position_y;//マウスの現在の位置
	unsigned int color;//色
	int fill;//塗りつぶし
	int thickness;//太さ

	//実際に動かすときに変更する変数
	VECTOR move_speed;//移動速度
	VECTOR move_size;//大きさ変更

	//Impactしたかどうかのフラグ
	bool impacted = false;//trueで当たっている
	bool destory = false;//trueで削除

	int name_tag_flag;//name_tagの表示フラグ


	//例)1-29　→　識別番号 - オブジェクト番号
	//識別番号はUIなのかゲームオブジェクトなのかなどを判別するための変数。
	//識別番号の中で何個目のオブジェクトなのかの判別するための変数。
	int number;//オブジェクト番号(番号はなるべくかぶらないように)
	int layer_number;//識別番号

	//仮追加(エラーが出る場合は削除)
	DiploidEngineObjectInformation();//コンストラクタ
	~DiploidEngineObjectInformation();//デストラクタ

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};

	virtual void Destory() { impacted = destory = true; };//オブジェクト削除関数
};