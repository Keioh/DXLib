#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()
{

}

void DiploidEngineApp::Load()
{	
	logo_scene.Load();
	title_scene.Load();
}

void DiploidEngineApp::Init()
{	
	logo_scene.Init();
	title_scene.Init();
}

void DiploidEngineApp::Updata(DiploidEngineSetting* setting, DiploidEngineInput* input)
{	
	if (logo_scene.GetFinalScene() == false)
	{
		logo_scene.Updata();
	}
	else
	{		
		title_scene.Updata();

		//�X�^�[�g�{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_START)
		{

		}

		//���[�h�{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_LOAD)
		{

		}

		//�I�v�V�����{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_OPTION)
		{

		}

		//�I���{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_EXIT)
		{
			setting->SetExit(1);
		}

		//���������Ă��Ȃ���
		if (title_scene.GetFinalScene() == GAME_NONE)
		{

		}
	}
}

void DiploidEngineApp::Draw()
{
	if (logo_scene.GetFinalScene() == false)
	{
		logo_scene.Draw();
	}
	else
	{
		title_scene.Draw();
	}

	//scr_gra.Draw(0.3f);
}

void DiploidEngineApp::Destory()
{

}

void DiploidEngineApp::End()
{

}