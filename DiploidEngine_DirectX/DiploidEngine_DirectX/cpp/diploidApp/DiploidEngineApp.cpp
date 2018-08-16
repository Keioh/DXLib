#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//ゲーム起動時にロードするデータ
{	
	image.Load("texter/test.png");

	sound.Load("sound/01.wav");
}

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	
	point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(point);


	//サイズ変更は仮実装
	for (int n = 0; n < 50; n++)
	{	
		VECTOR pos;
		pos.x = GetRand(WindowSize().x);
		pos.y = GetRand(WindowSize().y);
		pos.z = 0;

		image.Init(pos, 0.3f);
		box.Init(VGet(pos.x - (150 * 0.3f), pos.y - (150 * 0.3f), 0), VGet(300 * 0.3f, 300 * 0.3f, 0));

		//番号は同じのをなるべく使用しない。(オブジェクトを削除するときに同じ番号だといっしょに消えます)
		image.number += 1;
		box.number += 1;

		image.destory = box.destory = true;

		diploidEngineImpact.PushBox(box);
		diploidEngineLayer.PushTopGraphics(image);
	}
	
	//番号の引継ぎ
	circle.number = box.number;
	
	for (int n = 0; n < 50; n++)
	{
		VECTOR pos;
		pos.x = GetRand(WindowSize().x);
		pos.y = GetRand(WindowSize().y);
		//pos.z = 0;

		image.Init(pos, 0.3f);
		circle.Init(pos, 150 * 0.3f);

		//番号は同じのをなるべく使用しない。(オブジェクトを削除するときに同じ番号だといっしょに消えます)
		image.number += 1;
		circle.number += 1;

		image.destory = circle.destory = true;

		diploidEngineImpact.PushCircle(circle);
		diploidEngineLayer.PushMidGraphics(image);
	}
	
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。
{	
	//sound.Play();
	diploidEngineInput.GetMouse(MOUSE_INPUT_LEFT);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{

}