#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()
{

}

void DiploidEngineApp::Load()
{	
	//soft_date.Load("texter/test.png");

	image.Load("texter/hd.jpg");
}

void DiploidEngineApp::Init()
{	
	//soft_date.CreatGraphicsImage(8,8);

	image.Init(VGet(0, 0, 0), false);

	circle.Init(VGet(1280/2, 720/2, 0), 50, GetColor(50, 255, 50), true);
}

void DiploidEngineApp::Updata()
{	
	input.Update();

	circle.SetPosition(input.GetMousePosition());

	//scr_gra.Creat(160, 90);

	//test = std::sin(a);

	//circle.SetMoveSpeed(VGet(2.f, 0, 0));
	//circle.MoveUpdate();
	//soft_date.SetGraphicsScale(test,test);

	a += 0.001f;

	if (a > 1)
	{
		a = 0.0f;
	}

}

void DiploidEngineApp::Draw()
{
	//soft_date.GraphicsDraw();

	image.Draw();
	circle.Draw();

	scr_gra.Draw(a);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "モザイク度:%.3f (1.0fが最大値)", a);
}

void DiploidEngineApp::Destory()
{

}

void DiploidEngineApp::End()
{

}