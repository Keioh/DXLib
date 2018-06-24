#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//�Q�[���N�����Ƀ��[�h����f�[�^
{	
	image.Load("texter/test.png");
}

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	for (int n = 0; n < 1000; n++)
	{	
		image.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0),0.1f);
		image.move_angle = DX_PI / 180 * (GetRand(4)+1);
		image.destory = GetRand(1);

		diploidEngineLayer.PushTopGraphics(image);
	}

	for (int n = 0; n < 1000; n++)
	{
		image.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), 0.2f);
		image.move_angle = DX_PI / 180 * (GetRand(4) + 1);
		image.destory = GetRand(1);

		diploidEngineLayer.PushMidGraphics(image);
	}

	for (int n = 0; n < 1000; n++)
	{
		image.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), 0.3f);
		image.move_angle = DX_PI / 180 * (GetRand(4) + 1);
		image.destory = GetRand(1);

		diploidEngineLayer.PushBotGraphics(image);
	}
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B
{	

}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{

}