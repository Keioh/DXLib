#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "system\DiploidEngineMath.h"
#include "ver2.0/Objects/DiploidSliderObject.h"
#include "ver2.0/Graphics/DiploidTriangle.h"


//現状はx軸方向のスライドのみサポート
class DiploidSlider
{
private:
	DiploidImageV2 slider_image;
	DiploidSliderObject slider_button;

	DiploidTriangle triangle;
	TRIANGLE t_data;
	DiploidBoxV2 box;

	VECTOR position;//UIの位置(左上が基準)
	VECTOR object_size;//スライダーの動かせる範囲を指定。(x軸のみの場合はVGet(ここに数値,0,0));
	float object_scale = 1.0f;

	int slider_object_type = 1;//0で自由移動。1でx軸方向固定移動。2でy軸方向固定移動。

	DiploidEngineInput input;

public:
	void Load();
	void Init(VECTOR pos, VECTOR size, int slider_type = 1, float scale = 1.0f);//UIを初期化します。
	void Updata();//UIを更新します。
	void Draw(bool draw = true, bool debug = false);//UIを描画します。

	void SetPosition(int pos_x, int pos_y);//新しく位置を設定します。(左上基準)
	void SetSelectedUI(int new_flag);
	void SetSliderType(int new_type);
	void SetParameter(VECTOR new_parameter);//指定する値はsizeで指定した値より大きくても小さくてもダメ。

	bool GetHit();//現在、UIにマウスがヒットしているかのフラグを取得します。(ヒットしていればtrue)
	bool GetClick();//UIがクリックされたかのフラグを取得します。(クリックされるとtrue)
	int GetSelectedUI();//UIが選択されているかのフラグを取得します。(選択されていればtrue)
	int GetSliderType();
	VECTOR GetParameter();//現在のスライダーの値を取得します。
};