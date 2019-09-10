//スタート画面やロード画面などシーンの変更をするクラス。
#pragma once
#include "DxLib.h"

class DiploidEngineScene
{
private:

public:
	int SceneLoad();//シーンに変化があった際に次のシーンのデータを読み込むための関数。

	int LoadingScene();
	int StartScene();
	int LoadScene();
	int SaveScene();
	int EndScene();
	int GameScene();
};