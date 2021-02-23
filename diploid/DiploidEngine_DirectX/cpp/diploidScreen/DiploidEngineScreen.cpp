#include "diploidScreen\DiploidEngineScreen.h"

void DiploidEngineScreen::FrameCountStart()
{

	if (deltatime_frame_count == 0)//1�t���[���ڂȂ玞�����L��
	{
		deltatime_start = GetNowCount();

	}

	deltatime_frame_count++;
}

void DiploidEngineScreen::FrameCountEnd()
{
	if (deltatime_frame_count == 1) //1�t���[���ڂȂ畽�ς��v�Z����
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
	AvrSample = SettingFPS = setting_fps;
}

void DiploidEngineScreen::Update()
{
	if (Count == 0)//1�t���[���ڂȂ玞�����L��
	{ 
		StartTime = GetNowCount();
	}

	if (Count == AvrSample) //AvrSample�t���[���ڂȂ畽�ς��v�Z����
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
	int tookTime = GetNowCount() - StartTime;	//������������

	int waitTime = Count * 1000 / AvrSample - tookTime;	//�҂ׂ�����

	if (waitTime > 0) 
	{	

		Sleep(waitTime);	//�ҋ@
	}
}