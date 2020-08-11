#pragma once
#include <list>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"

using namespace std;

class DiploidCollision
{
private:
	int upadata_count;//いつ更新するかのカウント(画面外など、頻繁に判定をしたくない場所で計算回数を減らすための変数)
	int window_size_x = 1080, window_size_y = 1920;

protected:

public:
	bool CircleAndCircleCollisionUpdate(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two, int updata_rate = 0);//円と円の当たり判定を実行します。(戻り値は二つの円がヒットしていたらtrueを返します。)
	VECTOR CircleAndCircleCollisionPointsUpdate(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two, int updata_rate = 0);//円と円が当たった瞬間の位置を得ます。(戻り値は当たった場所の位置を返します。zには半径が入っています。)
	
	bool BoxAndMouseCollisionUpdate(DiploidBoxV2* box, int mouse_x, int mouse_y, int updata_rate = 0);//四角とマウスの当たり判定を実行します。(戻り値はマウスと四角がヒットしていたらtrueを返します。)
	bool BoxAndTouchCollisionUpdate(DiploidBoxV2* box, int touch_x, int touch_y, int updata_rate = 0);//四角とタッチの当たり判定を実行します。(戻り値はタッチと四角がヒットしていたらtrueを返します。)


	int GetUpdateCounter();//更新頻度を数えるカウンターを取得します。
};