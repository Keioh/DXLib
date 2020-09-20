//			DXLIB関連の設定をいじるクラス
//
//
//

#pragma once
#include "DxLib.h"
#include "diploidScreen/DiploidEngineAndroidScreen.h"

class DiploidEngineSetting
{
private:
	DiploidEngineAndroidScreen android_screen;//Androidデバイスのディスプレイステータス確認

public:
	DiploidEngineSetting();

	int window_x, window_y, window_bit, refresh_rate;//ウィンドウサイズとリフレッシュレート
	int window_mode;//TRUEでウィンドウモード
	const char* window_name;//アプリケーションの名前

	void Init();//DxLib初期化処理。初期化に失敗(-1)した場合はアプリケーションを終了します。
	void SetBegin();//DxLib初期化処理より前に設定する項目。
	void SetEnd();//DxLib初期化処理後に設定する項目。
	void End();//ゲーム終了をするときに呼ぶDxLib終了処理。
};