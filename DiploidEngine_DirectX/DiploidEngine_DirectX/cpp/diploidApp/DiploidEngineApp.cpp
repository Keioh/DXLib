#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	for (int n = 0; n < 1000; ++n)
	{
		circle.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), GetRand(30) + 10);
		point.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0));
		box.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), VGet(GetRand(50) + 10, GetRand(50) + 10, 0));

		diploidEngineImpact.PushCircle(circle);
		diploidEngineImpact.PushPoint(point);
		diploidEngineImpact.PushBox(box);
	}
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{	
	diploidEngineImpact.Updata();

	diploidEngineImpact.PopBackCircle();
	diploidEngineImpact.PopBackPoint();
	diploidEngineImpact.PopBackBox();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	diploidEngineImpact.Draw();
}