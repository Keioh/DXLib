#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//ゲーム起動時にロードするデータ
{	
	image.Load("texter/test.png");

	//sound.Load("sound/01.wav");
}

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{	
	point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(point);
	
	for (int n = 0; n < 50; n++)
	{
		VECTOR pos;
		pos.x = GetRand(WindowSize().x);
		pos.y = GetRand(WindowSize().y);
		//pos.z = 0;

		image.Init(pos, 0.3f);
		circle.Init(pos, 150 * 0.3f);

		//番号は同じのをなるべく使用しない。(オブジェクトを削除するときに同じ番号だといっしょに消えます)
		image.layer_number = 0;
		image.number += 1;

		circle.layer_number = 1;
		circle.number += 1;

		image.destory = circle.destory = true;

		diploidEngineImpact.PushCircle(circle);
		diploidEngineLayer.PushMidGraphics(image);
	}
	
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。
{	
	//sound.Play();
	diploidEngineInput.GetPressKey(KEY_INPUT_A);
	diploidEngineInput.GetPressMouse(MOUSE_INPUT_LEFT);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{

}