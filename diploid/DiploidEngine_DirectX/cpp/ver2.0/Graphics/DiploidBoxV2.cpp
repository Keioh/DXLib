#include "ver2.0/Graphics/DiploidBoxV2.h"

DiploidBoxV2::DiploidBoxV2()//デフォルトコンストラクタ
{

}

DiploidBoxV2::DiploidBoxV2(VECTOR position, VECTOR size)//コンストラクタ(位置と大きさを指定したBOXを作成)
{
	Transform::position = position;
	Transform::size = size;
}


void DiploidBoxV2::DrawGraphics(bool draw)//図形を描画します。
{
	if (draw == true)
	{
		DrawBox(Transform::position.x, Transform::position.y, Transform::position.x + Transform::size.x, Transform::position.y + Transform::size.y, GetColor(Transform::red, Transform::green, Transform::blue), TRUE);
	}
}