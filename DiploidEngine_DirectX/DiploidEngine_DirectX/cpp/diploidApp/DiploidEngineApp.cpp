#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	//�}�E�X�I�u�W�F�N�g
	circle.Init(VGet(0, 0, 0), 30);
	circle.mouse_point_move_flag = true;
	//diploidEngineImpact.PushCircle(circle);

	for (int n = 0; n < 5; n++)
	{
		circle.Init(VGet(WindowSize().x / 2 + n * 50, WindowSize().y / 2, 0), 30);
		circle.mouse_point_move_flag = false;
		//circle.destory = true;
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{
	//diploidEngineImpact.DestoryCircle();
	diploidEngineImpact.Updata();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	diploidEngineImpact.Draw();
}