//�����ł��B

#pragma once
#include "DxLib.h"
#include "diploidApp\DiploidEngineMain.h"
#include "diploidObject\DiploidEngineObject.h"
#include "diploidGraphics\diploidCircle.h"

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidCircle circle;
	

public:
	void Init();//�ŏ��Ɉ�񂾂��������������������L�q�B
	void Update();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��.
};