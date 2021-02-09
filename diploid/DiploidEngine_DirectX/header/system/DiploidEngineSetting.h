//			DXLIB関連の設定をいじるクラス
//
//
//

#pragma once
#include "DxLib.h"

class DiploidEngineSetting
{
private:
	bool reload = false;//リロードflag(画面サイズ変更をしたときに変化)

public:
	DiploidEngineSetting();

	int buffer_window_x, buffer_window_y, buffer_window_bit;
	int window_x, window_y, window_bit, refresh_rate;//ウィンドウサイズとリフレッシュレート
	int window_mode;//TRUEでウィンドウモード
	const char* window_name;//アプリケーションの名前

	int screen_handle;
	int sim_window_x, sim_window_y;//仮想ウィンドウサイズ

	int exit = 0;//終了フラグ(1になったらメインのwhileを抜ける)


	void Init();//DxLib初期化処理。初期化に失敗(-1)した場合はアプリケーションを終了します。
	void SetBegin();//DxLib初期化処理より前に設定する項目。
	void SetEnd();//DxLib初期化処理後に設定する項目。
	void End();//ゲーム終了をするときに呼ぶDxLib終了処理。

	void Updata();

	void SetExit(int flag);//終了フラグを設定する。
	void SetWindowSize(int new_window_x, int new_window_y);

	int GetExit();//終了フラグを取得する。

	bool GetReloadFlag();//再度画像を読み込むflagを取得する。
	void SetReloadFlag(bool new_flag);//再度画像を読み込むflagを変更する。
};