#pragma once
#include <list>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"

class Animation
{
private:
	DiploidImageV2 _image;
	DiploidImageV2* _image_ptr = &_image;

	std::list<DiploidImageV2> image_list;
	std::list<DiploidImageV2>* image_list_ptr = &image_list;
	std::list<DiploidImageV2>::iterator image_list_itr = image_list.begin();

	float time = 0.0f;
	float play = 60.0f;

public:
	void LoadPushImageV2(DiploidImageV2 imageV2);//オブジェクトとして読み込む(非推奨)
	void LoadHandles(int handle);//ハンドルだけ読み込む(推奨)

	void Init(VECTOR pos, float play_speed, float scale, bool shift_flag = false);
	void Draw(bool draw = true);

	void SetGraphicsTrun(bool new_flag);
	void SetGraphicsAngle(bool new_angle);
	void SetPosition(VECTOR new_pos);

	std::list<DiploidImageV2>* GetImageListPtr();
	std::list<DiploidImageV2>::iterator isGetItr();
};