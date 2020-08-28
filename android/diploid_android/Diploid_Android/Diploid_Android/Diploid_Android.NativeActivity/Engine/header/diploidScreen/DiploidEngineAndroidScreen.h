#pragma once
#include "DxLib.h"

//Android用のディスプレイ情報取得クラス(Android4.2以上から)
class DiploidEngineAndroidScreen
{
private:
	//JNI関連
	JNIEnv *env;
	const ANativeActivity *NativeActivity;

	jclass jclass_Diploid_Android;
	jmethodID jmethodID_Diploid_Android_RealScreenSize;

	jfieldID jfieldID_ScreenX;
	jfieldID jfieldID_ScreenY;

	//ウィンドウサイズ保存用変数
	int window_x;
	int window_y;

public:
	int GetScreenSizeX();
	int GetScreenSizeY();
};