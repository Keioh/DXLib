#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	//�}�E�X�I�u�W�F�N�g
	point.Init(VGet(0, 0, 0));
	point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(point);

	for (int n = 0; n < 500; n++)
	{
		circle.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), GetRand(30) + 10);
		circle.move_size = 0.1f;
		//circle.mouse_point_move_flag = false;
		circle.destory = false;
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{	
	diploidEngineImpact.Updata();

	diploidEngineImpact.DestoryCircle();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	diploidEngineImpact.Draw();
}