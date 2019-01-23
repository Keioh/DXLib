#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{
	
}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	
	object.map.Load("texter/MAP/test_map.png", 128, 128);//マップ画像データを読み込み(最後のx,yは画像の大きさを指定)
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	object.map.SetMapChipSize(100);//画像の1ドットをどれだけ拡大するか指定
	object.map.Create();//画像データからマップデータを作成

	object.box.Init(VGet(300,400,0), VGet(50,100,0));//pointグラフィックをマウスに追従させる
	object.box.layer_number = 0;
	object.box.number = 0;
	diploidEngineImpact.PushBox(object.box);//pointグラフィックをImpact配列に追加

	for (auto count = object.map.MAP.begin(); count != object.map.MAP.end(); ++count)//map.MAP配列をsize_t(auto)で取得しMAP.end()まで下記のことを繰り返す
	{
		if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))//α値が255の時かつ黒の時
		{
			object.box.Init(VGet(count->x * count->size, count->y * count->size, 0), VGet(count->size, count->size, 0));
			object.box.layer_number = 0;
			object.box.number += 1;
			diploidEngineImpact.PushBox(object.box);
		}
	}
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	if (diploidEngineImpact.GetBoxImpactFlag(0) == 0)//衝突していないときの処理
	{
		for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
		{
			diploidEngineImpact.SetBoxPositionAnimation(count, VGet(0, -4, 0));
		}

		if (diploidEngineInput.GetPressKey(KEY_INPUT_D) == 1)
		{
			for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(-4, -4, 0));
			}
		}

		if (diploidEngineInput.GetPressKey(KEY_INPUT_A) == 1)
		{
			for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(4, -4, 0));
			}
		}
	}
	else//衝突しているときの処理
	{
		for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
		{
			diploidEngineImpact.SetBoxPositionAnimation(count, VGet(0, 0, 0));
		}

		if (diploidEngineInput.GetPressKey(KEY_INPUT_D) == 1)
		{
			for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(-4, 0, 0));
			}
		}

		if (diploidEngineInput.GetPressKey(KEY_INPUT_A) == 1)
		{
			for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(4, 0, 0));
			}
		}
	}



}

void DiploidEngineApp::Draw()//結果を描写する処理
{

}

void DiploidEngineApp::End()//engine終了前処理。
{

}