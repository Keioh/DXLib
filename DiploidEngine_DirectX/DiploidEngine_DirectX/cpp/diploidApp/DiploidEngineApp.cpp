#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	object.Init(VGet(0, 0, 0), 50.0f);
	object.color = GetColor(255, 255, 255);
	object.fill = true;
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{
	object.Update(VGet(0.0f, 0.0f, 0.0f), 0.0f, true);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	object.Draw();
}
