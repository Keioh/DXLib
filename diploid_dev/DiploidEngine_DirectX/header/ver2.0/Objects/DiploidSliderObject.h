#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Main/Collision.h"
#include "diploidInput/DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
//#include "ver2.0/Objects/DiploidSelectedUIV2.h"

class DiploidSliderObject
{
private:
	VECTOR position;//UIの位置(左上が基準)
	VECTOR object_size;//UIの大きさ
	float object_scale = 1.0f;

	DiploidBoxV2 box;//当たり判定用BOX。
	DiploidCollision collision;//当たり判定処理用変数。
	DiploidImageV2 image;//画像ハンドル

	float on_hit_color_scale = 0.8f;//boxとマウスが当たっていないときの色の暗さ(1.0fで100%)
	int bright_red = 255, bright_green = 255, bright_blue = 255;//画像の輝度の数値

	int mouse_x, mouse_y;
	int slider_type = 0;//0で自由移動。1でx軸方向固定移動。2でy軸方向固定移動。

	bool hit = false;
	bool click = false;
	int selected = -1;
	bool no_hit_flag = false;

	DiploidEngineInput input;

public:

	void Load(int graphics_handl);
	void Init(VECTOR pos, VECTOR size, int slider_type = 0, float scale = 1.0f);//UIを初期化します。
	void Updata(DiploidEngineInput& input);//UIを更新します。
	void Updata();//UIを更新します。
	void Draw(bool draw = true, bool debug = false);//UIを描画します。

	void SetPosition(int pos_x, int pos_y);//新しく位置を設定します。(左上基準)
	void SetSize(int size_x, int size_y);//新しく大きさを設定します。(バグ)
	void SetScale(float new_scale);//新しくスケール値を設定します。(バグ)
	void SetSelectedUI(int new_flag);
	void SetSliderType(int new_type);

	VECTOR GetPosition();//現在のUIの位置(左上)の座標を取得します。
	VECTOR GetSize();//現在のUIの大きさを取得します。
	VECTOR GetGraphicsSize();//画像の大きさを取得します。
	float GetScale();
	bool GetHit();//現在、UIにマウスがヒットしているかのフラグを取得します。(ヒットしていればtrue)
	bool GetClick();//UIがクリックされたかのフラグを取得します。(クリックされるとtrue)
	int GetSelectedUI();//UIが選択されているかのフラグを取得します。(選択されていればtrue)
	int GetSliderType();
};