#include "diploidScreen\DiploidEngineScreen.h"

void DiploidEngineScreen::FrameCountStart()
{

	if (deltatime_frame_count == 0)//1フレーム目なら時刻を記憶
	{
		deltatime_start = GetNowCount();

	}

	deltatime_frame_count++;
}

void DiploidEngineScreen::FrameCountEnd()
{
	if (deltatime_frame_count == 1) //1フレーム目なら平均を計算する
	{
		deltatime_end = (GetNowCount() - deltatime_start);

		deltatime_frame_count = 0;
	}
}


float DiploidEngineScreen::GetFrameTime()
{
	return deltatime_end / 1000.0f;
}


void DiploidEngineScreen::Init(int setting_fps)
{
	SettingFPS = setting_fps;
	AvrSample = setting_fps;
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