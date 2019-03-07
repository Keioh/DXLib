#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"


class DiploidEngineScreen : public DiploidEngineObjectInformation
{

private:
	int StartTime;         //����J�n����
	int Count;             //�J�E���^
	float Fps;             //fps
	int AvrSample = 60;//���ς����T���v����
	int SettingFPS = 60;	//�ݒ肵��FPS

public:

	void Init(int setting_fps = 60);
	void Update();
	void Draw(int x = 0, int y = 0, bool debug = false);
	void Wait();
};