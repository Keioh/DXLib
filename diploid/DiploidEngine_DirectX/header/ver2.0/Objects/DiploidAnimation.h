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

	int sheets;
	int sheets_anime = 0;
public:

	void Load(const char* path);

	void Init(VECTOR pos, int sheet, float scale_x = 1.0f, float scale_y = 1.0f);

	void Update();
	void SetPosition(VECTOR  new_pos);
	void SetScale(float new_x, float new_y);
	void SetNextAnimationTime(int new_time);//次の画像へ行く時間を設定する。
	void SetAnimationSpeed(int new_Speed);//アニメーションのスピードを設定する。
	void Reset();//アニメーションを最初から再生(番号初期化)

	int GetAnimationNumber();//描画しているコマが何番目なのかを調べます。
	int GetAnimationSpeed();//現在のアニメーションのスピードを調べます。

	void Draw(bool debug = false);//一枚づつ描画
	void OneCellDraw(int number = 0, bool draw = true);//一枚だけ描画
	void StackDraw(bool debug = false);//重ねて描画

	void AllPop();

	size_t GetImagesVectorSize();
};