#pragma once
#include <memory>
#include "DxLib.h"
#include "ver2.0/Main/Transform.h"

class DiploidBoxV2 : public Transform//2D�̎l�p��`�悵�܂��B
{
private:

protected:

public:
	DiploidBoxV2();//�f�t�H���g�R���X�g���N�^
	DiploidBoxV2(VECTOR position, VECTOR size);//�R���X�g���N�^(�ʒu�Ƒ傫�����w�肵��BOX���쐬)

	void DrawGraphics(bool draw = true);//�}�`��`�悵�܂��B

};