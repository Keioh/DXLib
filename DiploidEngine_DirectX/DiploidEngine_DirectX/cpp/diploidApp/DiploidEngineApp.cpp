#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//�Q�[���N�����Ƀ��[�h����f�[�^
{	
	image.Load("texter/test.png");
}

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	for (int n = 0; n < 100; n++)
	{	
		image.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0),0.3f);
		image.move_angle = DX_PI / 180 * (GetRand(2)+1);

		diploidEngineLayer.PushTopGraphics(image);
	}
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B
{	

}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{

}