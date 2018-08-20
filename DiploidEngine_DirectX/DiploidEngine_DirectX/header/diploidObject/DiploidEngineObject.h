//�I�u�W�F�N�g�܂Ƃ�

#pragma once
#include "DxLib.h"
#include "diploidGraphics\diploidBox.h"
#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"
#include "diploidGraphics\diploidImage.h"
#include "diploidSound\diploidEnigneSound.h"

class DiploidObject
{
private:

public:
	DiploidBox box;//�l�p
	DiploidCircle circle;//�~
	DiploidPoint point;//�_

	DiploidImage image;//�摜

	DiploidEngineSound sound;//��

	void Init();
	void Updata();
	void Draw(bool debug = true);

};