#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	test.circle.Init(VGet(GetWindowSize().x / 2, GetWindowSize().y / 2, 0.0f), 50.0f, GetColor(255, 255, 255), FALSE);
}

void DiploidEngineApp::LoadUpdata()//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�Q�[�����Ƀ��[�h�������f�[�^�Ȃ�)
{

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	anime += 0.5f;

	test.circle.SetRadius(anime);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	test.circle.Draw();
}

void DiploidEngineApp::End()//engine�I���O�����B
{

}