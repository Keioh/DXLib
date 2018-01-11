#pragma once
#include "Object_Base.h"

class Logo : public ObjectBase
{
private:
	int logo_D, logo_d, logo_i, logo_l, logo_o, logo_p;//画像ハンドル保存用


public:
	Logo();

	int timer;//アニメタイマー
	float anime_pos_x = -anime_x;//アニメ初期開始位
	float anime_x = 25.0f;//アニメのために座標ずらす分
	int alph_graphics;//画像α値


	void LoadGraphics();
	void Inti();
	void DrawLogo(int x, int y);
};