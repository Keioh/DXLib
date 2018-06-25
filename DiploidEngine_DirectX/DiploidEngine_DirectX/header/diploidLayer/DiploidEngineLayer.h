//オブジェクトを描写する順番を決めるためのレイヤーシステム

#pragma once
#include <vector>
#include "DxLib.h"
#include "diploidGraphics\diploidImage.h"

class DiploidEngineLayer
{
private:

	float top_byte;
	float mid_byte;
	float bot_byte;
	int top_size;
	int mid_size;
	int bot_size;

public:
	std::vector<DiploidImage> image_top_vector;
	std::vector<DiploidImage> image_mid_vector;
	std::vector<DiploidImage> image_bot_vector;

	void GetSize();//各配列の大きさを取得

	void PushTopGraphics(DiploidImage image);
	void PushMidGraphics(DiploidImage image);
	void PushBotGraphics(DiploidImage image);

	void Updata();
	void Draw(bool debug = false, bool draw = true);
	void Destory();//destory変数がtureの場合、要素を削除

	void DestoryTop();//top配列から要素を削除
	void DestoryMid();//mid配列から要素を削除
	void DestoryBot();//bot配列から要素を削除

};