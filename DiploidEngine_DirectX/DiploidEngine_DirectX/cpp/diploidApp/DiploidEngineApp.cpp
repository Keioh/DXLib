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
		circle.move_size = 0.0f;
		//circle.mouse_point_move_flag = false;
		circle.destory = true;
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{	
	diploidEngineImpact.Updata();

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		diploidEngineImpact.DestoryCircle();
	}
	else if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)
	{
		int x, y;
		GetMousePoint(&x, &y);
		circle.Init(VGet(x, y, 0), GetRand(30) + 10);
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	diploidEngineImpact.Draw();
}