#pragma once
#include "DxLib.h"
#include "diploidGraphics\diploidImage.h"

class DiploidImage
{
private:

public:
	int handl;
	VECTOR position;

	void Load(const char* path);//画像読み込み
	void Init(VECTOR pos);//初期位置
	void Updata();//位置やアニメーションなどの更新(つまり主に座標移動)
	void Draw(bool draw = true);//画像を表示
};