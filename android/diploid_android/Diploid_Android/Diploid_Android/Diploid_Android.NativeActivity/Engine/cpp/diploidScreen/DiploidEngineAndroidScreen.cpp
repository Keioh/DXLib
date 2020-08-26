#include "diploidScreen/DiploidEngineAndroidScreen.h"

int DiploidEngineAndroidScreen::GetScreenSizeX()
{
	NativeActivity = GetNativeActivity();

	if (NativeActivity->vm->AttachCurrentThreadAsDaemon(&env, NULL) != JNI_OK)
	{
		return -1;
	}

	//java�̃N���X���擾
	jclass_Diploid_Android = env->GetObjectClass(NativeActivity->clazz);

	//java�̃N���X�̃����o�֐���ID���擾
	jmethodID_Diploid_Android_RealScreenSize = env->GetMethodID(jclass_Diploid_Android, "RealScreenSize", "()V");

	//java�̃N���X�̃����o�֐�����void�֐�������
	env->CallVoidMethod(NativeActivity->clazz, jmethodID_Diploid_Android_RealScreenSize);

	//java�̃N���X�̃����o�ϐ���ID���擾
	jfieldID_ScreenX = env->GetFieldID(jclass_Diploid_Android, "window_x", "I");

	//java�̃N���X�̃����o�ϐ���������擾
	window_x = env->GetIntField(NativeActivity->clazz, jfieldID_ScreenX);

	//java�̃N���X�̎Q�Ƃ��폜
	env->DeleteLocalRef(jclass_Diploid_Android);

	// JavaVM �ƃ\�t�g���s�p�X���b�h�̊֘A�t���I��
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

	//java�̃N���X���擾
	jclass_Diploid_Android = env->GetObjectClass(NativeActivity->clazz);

	//java�̃N���X�̃����o�֐���ID���擾
	jmethodID_Diploid_Android_RealScreenSize = env->GetMethodID(jclass_Diploid_Android, "RealScreenSize", "()V");

	//java�̃N���X�̃����o�֐�����void�֐�������
	env->CallVoidMethod(NativeActivity->clazz, jmethodID_Diploid_Android_RealScreenSize);

	//java�̃N���X�̃����o�ϐ���ID���擾
	jfieldID_ScreenY = env->GetFieldID(jclass_Diploid_Android, "window_y", "I");

	//java�̃N���X�̃����o�ϐ���������擾
	window_y = env->GetIntField(NativeActivity->clazz, jfieldID_ScreenY);

	//java�̃N���X�̎Q�Ƃ��폜
	env->DeleteLocalRef(jclass_Diploid_Android);

	// JavaVM �ƃ\�t�g���s�p�X���b�h�̊֘A�t���I��
	NativeActivity->vm->DetachCurrentThread();

	return window_y;
}