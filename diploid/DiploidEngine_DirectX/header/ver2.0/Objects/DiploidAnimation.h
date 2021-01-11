#pragma  once
#include "vector"
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"

class DiploidAnimation
{
private:

	std::vector<DiploidImageV2> images;

	DiploidImageV2 image;

	int animation_image_number = 1;
	int animation_speed = 5;
	int time;
	int next_time = 60;

public:

	void Load(const char* path);

	void Init(VECTOR pos, float scale_x = 1.0f, float scale_y = 1.0f);

	void Update();
	void SetPosition(VECTOR  new_pos);
	void SetScale(float new_x, float new_y);
	void SetNextAnimationTime(int new_time);//Ÿ‚Ì‰æ‘œ‚Ös‚­ŠÔ‚ğİ’è‚·‚éB

	void Draw(bool debug = false);//ˆê–‡‚Ã‚Â•`‰æ
	void StackDraw(bool debug = false);//d‚Ë‚Ä•`‰æ

};