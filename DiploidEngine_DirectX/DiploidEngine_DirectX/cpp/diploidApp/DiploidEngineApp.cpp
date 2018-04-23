#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	//�}�E�X�I�u�W�F�N�g
	point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(point);

	for (int n = 0; n < 5000; n++)
	{
		circle.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), GetRand(25));
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{
	diploidEngineImpact.AnimeUpdata();
	diploidEngineImpact.ImpactUpdata();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	diploidEngineImpact.Draw();
}