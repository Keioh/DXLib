#include "ver2.0/Graphics/DiploidBoxV2.h"

DiploidBoxV2::DiploidBoxV2()//�f�t�H���g�R���X�g���N�^
{

}

DiploidBoxV2::DiploidBoxV2(VECTOR position, VECTOR size)//�R���X�g���N�^(�ʒu�Ƒ傫�����w�肵��BOX���쐬)
{
	Transform::position = position;
	Transform::size = size;
}


void DiploidBoxV2::DrawGraphics(bool draw)//�}�`��`�悵�܂��B
{
	if (draw == true)
	{
		DrawBox(Transform::position.x, Transform::position.y, Transform::position.x + Transform::size.x, Transform::position.y + Transform::size.y, GetColor(Transform::red, Transform::green, Transform::blue), TRUE);
	}
}