#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"


class DiploidEngineScreen : public DiploidEngineObjectInformation
{

private:
	int StartTime;         //測定開始時刻
	int Count;             //カウンタ
	float Fps;             //fps
	int AvrSample = 60;//平均を取るサンプル数
	int SettingFPS = 60;	//設定したFPS

public:

	void Init(int setting_fps = 60);
	void Update();
	void Draw(int x = 0, int y = 0, bool debug = false);
	void Wait();
};