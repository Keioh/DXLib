#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{
	
}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^�Ȃ�)
{	

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	for (int a = 0; a <= 150; ++a)
	{
		test.box.Init(VGet(a * 3, 100, 0), VGet(50,50,0));
		test.box.number = a;

		diploidEngineImpact.PushBox(test.box);
	}

	for (int a = 0; a <= 180; ++a)
	{
		test.point.Init(VGet(a * 3,100,0));
		test.point.number = a + 150;

		diploidEngineImpact.PushPoint(test.point);
	}
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	//diploidEngineImpact.SetPointAnimation(0, VGet(0, 0, 0));
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "test = %d", diploidEngineImpact.GetMaxArrayNumber());
}