#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//�Q�[���N�����Ƀ��[�h����f�[�^
{	
	image.Load("texter/test.png");

}

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	for (int n = 0; n < 5000; n++)
	{	

		image.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0),0.2f);
		image.move_angle = DX_PI / 180 * (GetRand(2)+1);
		//image.move_size = 0.1f;
		//image.mouse_point_move_flag = true;
		diploidEngineLayer.PushTopGraphics(image);
	}
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B
{	
	//diploidEngineImpact.Updata();
	diploidEngineLayer.Updata();
	//image.Updata();

}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	//diploidEngineImpact.Draw();
	diploidEngineLayer.Draw();
	//image.Draw();
}