#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	/*
	box.Init(VGet(0, 0, 0), VGet(50,50,0));
	box.mouse_point_move_flag = true;
	diploidEngineImpact.PushBox(box);

	box.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), VGet(GetRand(100) + 50, GetRand(100) + 50, 0));
	box.mouse_point_move_flag = false;
	diploidEngineImpact.PushBox(box);
	*/

	for (int n = 0; n < 1000; ++n)
	{
		circle.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), GetRand(30) + 10);
		point.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0));

		diploidEngineImpact.PushCircle(circle);
		diploidEngineImpact.PushPoint(point);
	}
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{	
	diploidEngineImpact.Updata();

	diploidEngineImpact.PopBackCircle();
	diploidEngineImpact.PopBackPoint();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	diploidEngineImpact.Draw();
}