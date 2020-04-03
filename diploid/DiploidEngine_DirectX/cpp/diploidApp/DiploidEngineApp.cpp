#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	
	for (int one = 0; one != 10; ++one)
	{
		for (int two = 0; two != 5; ++two)
		{
			fild[two][one].Load();
		}
	}
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	input.Init();//インプットの初期化

	for (int one = 0; one != 10; ++one)
	{
		for (int two = 0; two != 5; ++two)
		{
			fild[two][one].Init(VGet(one * (1024 * 0.125f), two * (1024 * 0.125f), 0), 0.125f);
			fild[two][one].SetTerrainType(GetRand(1));
		}
	}

	fild[2][8].SetBuildingType(1);//自拠点の決定
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	input.Update();//インプットの更新

	for (int one = 0; one != 10; ++one)
	{
		for (int two = 0; two != 5; ++two)
		{
			fild[two][one].Updata(&input);
		}
	}
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	for (int one = 0; one != 10; ++one)
	{
		for (int two = 0; two != 5; ++two)
		{
			fild[two][one].Draw();
		}
	}
}

void DiploidEngineApp::Destory()//ループ中に削除したいオブジェクトがある場合はここで削除処理を書く。
{

}

void DiploidEngineApp::End()//engine終了前処理。
{

}