#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()
{

}

void DiploidEngineApp::Load()
{	
	soft_date.Load("texter/a.jpg");
}

void DiploidEngineApp::Init()
{	
	soft_date.CreatSoftImage(1.5f,1.5f);
	//soft_date.SetFill(true);
}

void DiploidEngineApp::Updata()
{
	test += 0.25f;
	//soft_date.SetPosition(VGet(100, 100, 0));	
	//soft_date.SetPixelSize(test, test);

}

void DiploidEngineApp::Draw()
{
	soft_date.SoftwareDraw();
}

void DiploidEngineApp::Destory()
{

}

void DiploidEngineApp::End()
{

}