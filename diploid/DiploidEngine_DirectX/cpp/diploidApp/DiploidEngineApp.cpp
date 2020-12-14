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

void DiploidEngineApp::Updata()
{	
	if (logo_scene.GetFinalScene() == false)
	{
		logo_scene.Updata();
	}
	else
	{
		title_scene.Updata();

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