#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	box.Init(VGet(0, 0, 0), VGet(50,50,0));
	box.mouse_point_move_flag = true;
	diploidEngineImpact.PushBox(box);

	box.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), VGet(GetRand(100) + 50, GetRand(100) + 50, 0));
	box.mouse_point_move_flag = false;
	diploidEngineImpact.PushBox(box);
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{	
	diploidEngineImpact.Updata();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	diploidEngineImpact.Draw();
}