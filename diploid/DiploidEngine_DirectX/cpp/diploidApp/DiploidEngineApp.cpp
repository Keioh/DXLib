#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	object.box.SetSize(VGet(100, 100, 0));
	object.box.SetPosition(VGet(1280 / 2, 720 / 2, 0));
	object.box.SetColorGreen(150);
	object.box.SetColorRed(150);
	object.box.SetColorBlue(150);
}

void DiploidEngineApp::LoadUpdata()//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�Q�[�����Ƀ��[�h�������f�[�^�Ȃ�)
{

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{

}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	object.box.DrawGraphics();
}

void DiploidEngineApp::End()//engine�I���O�����B
{

}