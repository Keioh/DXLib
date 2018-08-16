#include "diploidScreen\DiploidEngineScreen.h"

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

	if (Count == AvrSample) //60�t���[���ڂȂ畽�ς��v�Z����
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
	DrawFormatString(x, y, GetColor(255, 255, 255), "%.2f fps", Fps);
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