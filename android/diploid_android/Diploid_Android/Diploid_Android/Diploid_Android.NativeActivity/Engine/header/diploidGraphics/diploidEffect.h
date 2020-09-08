#pragma once
#include <vector>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"
#include  "ver2.0/Graphics/DiploidBoxV2.h"

using namespace std;

class DiploidEffect
{
private:
	vector<DiploidImageV2> image_vector;//画像配列(仮)
	vector<DiploidCircleV2> circle_vector;//円配列(仮)
	vector<DiploidBoxV2> box_vecter;//箱配列

public:
	void PushImage(DiploidImageV2 image);//画像の追加。(仮)
	void PushCirlce(DiploidCircleV2 circle);//円の追加。(仮)
	void PushBox(DiploidBoxV2 box);//箱の追加。

	void UpdateImage();//アニメーションなどのアップデート(仮)
	void UpdateCircle();//アニメーションなどのアップデート(仮)
	void UpdateBox();//アニメーションなどのアップデート


	void DrawImage(bool draw = true, bool debug = false);//エフェクトを描画(仮)
	void DrawCircle(bool draw = true, bool debug = false);//エフェクトを描画(仮)
	void DrawBox(bool draw = true, bool debug = false);//エフェクトを描画

};