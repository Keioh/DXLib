#include "diploidScreen/DiploidEngineAndroidScreen.h"

int DiploidEngineAndroidScreen::GetScreenSizeX()
{
	NativeActivity = GetNativeActivity();

	if (NativeActivity->vm->AttachCurrentThreadAsDaemon(&env, NULL) != JNI_OK)
	{
		return -1;
	}

	//javaのクラスを取得
	jclass_Diploid_Android = env->GetObjectClass(NativeActivity->clazz);

	//javaのクラスのメンバ関数のIDを取得
	jmethodID_Diploid_Android_RealScreenSize = env->GetMethodID(jclass_Diploid_Android, "RealScreenSize", "()V");

	//javaのクラスのメンバ関数からvoid関数を処理
	env->CallVoidMethod(NativeActivity->clazz, jmethodID_Diploid_Android_RealScreenSize);

	//javaのクラスのメンバ変数のIDを取得
	jfieldID_ScreenX = env->GetFieldID(jclass_Diploid_Android, "window_x", "I");

	//javaのクラスのメンバ変数から情報を取得
	window_x = env->GetIntField(NativeActivity->clazz, jfieldID_ScreenX);

	//javaのクラスの参照を削除
	env->DeleteLocalRef(jclass_Diploid_Android);

	// JavaVM とソフト実行用スレッドの関連付け終了
	NativeActivity->vm->DetachCurrentThread();

	return window_x;
}

int DiploidEngineAndroidScreen::GetScreenSizeY()
{
	NativeActivity = GetNativeActivity();

	if (NativeActivity->vm->AttachCurrentThreadAsDaemon(&env, NULL) != JNI_OK)
	{
		return -1;
	}

	//javaのクラスを取得
	jclass_Diploid_Android = env->GetObjectClass(NativeActivity->clazz);

	//javaのクラスのメンバ関数のIDを取得
	jmethodID_Diploid_Android_RealScreenSize = env->GetMethodID(jclass_Diploid_Android, "RealScreenSize", "()V");

	//javaのクラスのメンバ関数からvoid関数を処理
	env->CallVoidMethod(NativeActivity->clazz, jmethodID_Diploid_Android_RealScreenSize);

	//javaのクラスのメンバ変数のIDを取得
	jfieldID_ScreenY = env->GetFieldID(jclass_Diploid_Android, "window_y", "I");

	//javaのクラスのメンバ変数から情報を取得
	window_y = env->GetIntField(NativeActivity->clazz, jfieldID_ScreenY);

	//javaのクラスの参照を削除
	env->DeleteLocalRef(jclass_Diploid_Android);

	// JavaVM とソフト実行用スレッドの関連付け終了
	NativeActivity->vm->DetachCurrentThread();

	return window_y;
}