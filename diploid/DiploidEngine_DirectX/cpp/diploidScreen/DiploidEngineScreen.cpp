#include "diploidScreen\DiploidEngineScreen.h"

void DiploidEngineScreen::FrameCount()
{

}

float DiploidEngineScreen::GetFrameTime()
{
	return 0.0f;
}


void DiploidEngineScreen::Init(int setting_fps)
{
	AvrSample = SettingFPS = setting_fps;
}

void DiploidEngineScreen::Update()
{
	if (Count == 0)//1フレーム目なら時刻を記憶
	{ 
		StartTime = GetNowCount();
	}

	if (Count == AvrSample) //AvrSampleフレーム目なら平均を計算する
	{
		//int t = GetNowCount();
		Fps = 1000.f / ((GetNowCount() - StartTime) / (float)AvrSample);
		Count = 0;
		StartTime = GetNowCount();
	}

	Count++;
}

void DiploidEngineScreen::Draw(int x, int y, bool debug)
{
	if (debug == true)
	{
		DrawFormatString(x, y, GetColor(255, 255, 255), "%.2f fps", Fps);
	}
}

void DiploidEngineScreen::Wait()
{
	int tookTime = GetNowCount() - StartTime;	//かかった時間

	int waitTime = Count * 1000 / AvrSample - tookTime;	//待つべき時間

	if (waitTime > 0) 
	{	

		Sleep(waitTime);	//待機
	}
}

float DiploidEngineScreen::GetDeltaTime()
{


	return deltatime;
}