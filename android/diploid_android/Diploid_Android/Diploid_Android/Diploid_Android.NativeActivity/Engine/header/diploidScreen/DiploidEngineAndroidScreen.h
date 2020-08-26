#pragma once
#include "DxLib.h"

//Android�p�̃f�B�X�v���C���擾�N���X(Android4.2�ȏォ��)
class DiploidEngineAndroidScreen
{
private:
	JNIEnv *env;
	const ANativeActivity *NativeActivity;

	jclass jclass_Diploid_Android;
	jmethodID jmethodID_Diploid_Android_RealScreenSize;

	jfieldID jfieldID_ScreenX;
	jfieldID jfieldID_ScreenY;

	int window_x;
	int window_y;

public:
	int GetScreenSizeX();
	int GetScreenSizeY();
};