#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Main/Collision.h"
#include "diploidInput/DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"

class DiploidSlider
{
private:

public:

	void Load(int graphics_handl);
	void Init(VECTOR pos, VECTOR size, float scale = 1.0f);//UIを初期化します。
	void Updata(DiploidEngineInput* input);//UIを更新します。
	void Draw(bool draw = true, bool debug = false);//UIを描画します。

	void SetPosition(int pos_x, int pos_y);//新しく位置を設定します。(左上基準)
	void SetSize(int size_x, int size_y);//新しく大きさを設定します。(バグ)
	void SetScale(float new_scale);//新しくスケール値を設定します。(バグ)
	void SetSelectedUI(int new_flag);

	VECTOR GetPosition();//現在のUIの位置(左上)の座標を取得します。
	VECTOR GetSize();//現在のUIの大きさを取得します。
	float GetScale();
	bool GetHit();//現在、UIにマウスがヒットしているかのフラグを取得します。(ヒットしていればtrue)
	bool GetClick();//UIがクリックされたかのフラグを取得します。(クリックされるとtrue)
	int GetSelectedUI();//UIが選択されているかのフラグを取得します。(選択されていればtrue)
};