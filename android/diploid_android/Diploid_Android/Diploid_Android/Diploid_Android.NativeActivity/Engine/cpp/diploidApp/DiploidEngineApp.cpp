#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	test.Load();
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	test.Init();
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	input.Update();

	test.Update(&input);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	test.Draw(true);

	//��ʏ��
	DrawFormatString(0, 120, GetColor(255, 255, 255), "ScreenSizeX:%d", android_screen.GetScreenSizeX());
	DrawFormatString(0, 180, GetColor(255, 255, 255), "ScreenSizeY:%d", android_screen.GetScreenSizeY());
}

void DiploidEngineApp::Destory()//���[�v���ɍ폜�������I�u�W�F�N�g(ver1.0)������ꍇ�͂����ō폜�����������B
{

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}