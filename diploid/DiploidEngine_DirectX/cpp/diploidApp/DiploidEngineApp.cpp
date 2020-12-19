#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate(DiploidEngineApp* app)
{

}

void DiploidEngineApp::Load(DiploidEngineApp* app)
{	
	logo_scene.Load();
	title_scene.Load();
}

void DiploidEngineApp::Init(DiploidEngineApp* app)
{	
	logo_scene.Init();
	title_scene.Init();
}

void DiploidEngineApp::Updata(DiploidEngineApp* app)
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
			app->diploidEngineSetting.SetExit(1);
		}

		//���������Ă��Ȃ���
		if (title_scene.GetFinalScene() == GAME_NONE)
		{

		}
	}
}

void DiploidEngineApp::Draw(DiploidEngineApp* app)
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

void DiploidEngineApp::Destory(DiploidEngineApp* app)
{

}

void DiploidEngineApp::End(DiploidEngineApp* app)
{

}