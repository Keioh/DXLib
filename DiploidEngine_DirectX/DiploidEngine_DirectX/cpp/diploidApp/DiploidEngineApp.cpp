#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	box.Init(VGet(0, 0, 0), VGet(200, 100, 0));
	box.mouse_point_move_flag = true;
	box.color = GetColor(255, 255, 255);
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{	
	//diploidEngineImpact.Updata();

	box.Update();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	//diploidEngineImpact.Draw();

	box.Draw();
}