#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	r = 50.0f;
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{
	DrawCircleAA(WindowSize().x / 2, WindowSize().y / 2, r, 64, GetColor(255, 255, 255), TRUE);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{

}
