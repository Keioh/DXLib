//�����ł��B

#pragma once
#include "DxLib.h"
#include "diploidApp\DiploidEngineMain.h"
#include "diploidObject\DiploidEngineObject.h"
#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidBox.h"
#include "diploidGraphics\diploidImage.h"

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidCircle circle;
	DiploidPoint point;
	DiploidBox box;

	DiploidImage image;

public:
	void Init();//�ŏ��Ɉ�񂾂��������������������L�q�B
	void Update();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��.
};