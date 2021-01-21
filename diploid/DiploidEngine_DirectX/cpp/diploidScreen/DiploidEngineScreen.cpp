#include "diploidScreen\DiploidEngineScreen.h"

void DiploidEngineScreen::FrameCount()
{
	SetAlwaysRunFlag(TRUE);	

	flip_count = 0;
	deltatime_start = GetNowCount();

	for(;;)
	{
		// 画面切り替えを行ってＶＹＳＮＣ待ちをする
		ScreenFlip();

		// １秒経過していたらループから抜ける
		if (GetNowCount() - StartTime >= 1000)
			break;

		// ScreenFlip を行った回数をインクリメント
		flip_count++;
	}


	SetAlwaysRunFlag(FALSE);

	deltatime_complate = 1000 / flip_count;
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
		int t = GetNowCount();
		Fps = 1000.f / ((t - StartTime) / (float)AvrSample);
		Count = 0;
		StartTime = t;
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
		
	deltatime_complate = (GetNowCount() - deltatime_start);

}

float DiploidEngineScreen::GetDeltaTime()
{
	deltatime = ((deltatime_complate)/1000.0f);

	if (deltatime > 0.05f)
	{
		deltatime = 0.05f;
	}

	return deltatime;
}