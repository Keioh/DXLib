#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{
	
}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	test.image.Load("texter/test.png");
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	for (int a = 0; a <= 10; ++a)
	{
		test.box.Init(VGet(a * 10, 300, 0), VGet(300, 300, 0));
		test.box.number = a;
		diploidEngineImpact.PushBox(test.box);

		test.image.Init(VGet((a * 10) + 150, 300 + 150, 0));
		test.image.number = a;
		diploidEngineLayer.PushTopGraphics(test.image);
	}

	/*
	for (int a = 0; a <= 10; ++a)
	{
		test.point.Init(VGet(300,100,0));
		test.point.number = a + 150;

		diploidEngineImpact.PushPoint(test.point);
	}
	*/

	//diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	//diploidEngineImpact.SetPointAnimation(0, VGet(0, 0, 0));
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Box object number = %d", diploidEngineImpact.GetBoxNumber(10));
	DrawFormatString(0, 20, GetColor(255, 255, 255), "Point object number = %d", diploidEngineImpact.GetPointNumber(0));

}