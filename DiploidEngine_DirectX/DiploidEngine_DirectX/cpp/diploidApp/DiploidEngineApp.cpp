#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	object.Init(VGet(WindowSize().x / 2, WindowSize().y / 2, 0.0f), 50.0f);
	object.color = GetColor(255, 255, 255);
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{
	object.Update(VGet(1.0f, 0.0f, 0.0f), 0.0f);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	object.Draw();
}
