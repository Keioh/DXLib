#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{
	
}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^�Ȃ�)
{	
	test.image.Load("texter/test.png");
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	test.box.Init(VGet(100, 250, 0), VGet(100,120,0));
	test.box.mouse_point_move_flag = false;
	test.box.number = 0;
	test.box.destory = false;

	test.image.Init();
	test.image.mouse_point_move_flag = false;
	test.image.number = 1;
	test.image.destory = false;

	diploidEngineImpact.PushBox(test.box);
	diploidEngineLayer.PushTopGraphics(test.image);

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	//test.box.Update();
	//test.image.Updata();
	diploidEngineImpact.SetBoxAnimation(0, VGet(1, 0, 0), VGet(0, 1, 0));
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	//test.box.Draw();
	//test.image.Draw();

}