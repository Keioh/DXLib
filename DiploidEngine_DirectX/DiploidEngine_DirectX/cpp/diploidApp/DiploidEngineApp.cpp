#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{
	
}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^�Ȃ�)
{	

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	test.box.Init(VGet(100, 250, 0), VGet(150, 250, 0));
	test.box.mouse_point_move_flag = false;
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	test.box.Update();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	test.box.Draw();

}
