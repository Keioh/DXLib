#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()
{

}

void DiploidEngineApp::Load()
{	
	soft_date.Load("texter/test.png");
}

void DiploidEngineApp::Init()
{	
	soft_date.CreatGraphicsImage(8,8);
}

void DiploidEngineApp::Updata()
{
	test = std::sin(a)/8 + 1.0f;


	soft_date.SetGraphicsScale(test,test);

	a += 0.01f;
}

void DiploidEngineApp::Draw()
{
	soft_date.GraphicsDraw();
}

void DiploidEngineApp::Destory()
{

}

void DiploidEngineApp::End()
{

}