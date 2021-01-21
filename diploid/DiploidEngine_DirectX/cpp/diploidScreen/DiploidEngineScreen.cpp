#include "diploidScreen\DiploidEngineScreen.h"

void DiploidEngineScreen::FrameCount()
{
	SetAlwaysRunFlag(TRUE);	

	flip_count = 0;
	deltatime_start = GetNowCount();

	for(;;)
	{
		// ‰æ–ÊØ‚è‘Ö‚¦‚ğs‚Á‚Ä‚u‚x‚r‚m‚b‘Ò‚¿‚ğ‚·‚é
		ScreenFlip();

		// ‚P•bŒo‰ß‚µ‚Ä‚¢‚½‚çƒ‹[ƒv‚©‚ç”²‚¯‚é
		if (GetNowCount() - StartTime >= 1000)
			break;

		// ScreenFlip ‚ğs‚Á‚½‰ñ”‚ğƒCƒ“ƒNƒŠƒƒ“ƒg
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
	if (Count == 0)//1ƒtƒŒ[ƒ€–Ú‚È‚ç‚ğ‹L‰¯
	{ 
		StartTime = GetNowCount();
	}

	if (Count == AvrSample) //AvrSampleƒtƒŒ[ƒ€–Ú‚È‚ç•½‹Ï‚ğŒvZ‚·‚é
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
	int tookTime = GetNowCount() - StartTime;	//‚©‚©‚Á‚½ŠÔ

	int waitTime = Count * 1000 / AvrSample - tookTime;	//‘Ò‚Â‚×‚«ŠÔ

	if (waitTime > 0) 
	{	

		Sleep(waitTime);	//‘Ò‹@
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