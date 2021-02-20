#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"

class LoadStringImage
{
private:
	//Optionの画像
	VECTOR position = VGet(0, 0, 0);
	DiploidImageV2 option_string_images[5];

	int position_animation_x[5];//アニメーションをするｘ座標
	int option_string_alpha[5];//各画像のアルファ値

	int anime_pos_init = -25;

	int alpha_speed = 5;//透過速度
	int animation_speed = 1;//アニメーションの速さ

public:
	void Load();
	void Init(VECTOR pos);
	void Updata();
	void Draw(bool draw = true, bool debug = false);

	void Reset();//アニメーションをリセットします。
};