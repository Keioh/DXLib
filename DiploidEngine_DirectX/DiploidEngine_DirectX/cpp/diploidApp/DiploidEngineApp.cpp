#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	for (int n = 0; n < 10000; n++)
	{
		circle.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), GetRand(25));
		circle.color = GetColor(GetRand(255), GetRand(255), GetRand(255));
		circle.fill = true;
		
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{
	//diploidEngineImpact.AnimeUpdata(0.0f,0.0f, VGet(0,0,0.05f));
	diploidEngineImpact.ImpactUpdata();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	diploidEngineImpact.Draw();
}