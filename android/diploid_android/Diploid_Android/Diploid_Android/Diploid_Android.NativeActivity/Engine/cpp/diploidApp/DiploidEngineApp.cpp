#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{		
	button.Init(VGet(400, 1000, 0), VGet(400, 300, 0));
	button.SetTouchFlag(true);
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	input.Update();

	button.Updata(&input);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{	
	DrawBox(0, 0, test.GetScreenSizeX(), test.GetScreenSizeY(), GetColor(100, 100, 100), TRUE);

	button.Draw(true, true);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "Touch Time:%d", button.GetTime());
	DrawFormatString(0, 120, GetColor(255, 255, 255), "ScreenSizeX:%d", test.GetScreenSizeX());
	DrawFormatString(0, 180, GetColor(255, 255, 255), "ScreenSizeY:%d", test.GetScreenSizeY());

}

void DiploidEngineApp::Destory()//���[�v���ɍ폜�������I�u�W�F�N�g(ver1.0)������ꍇ�͂����ō폜�����������B
{

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}