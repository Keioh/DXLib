#pragma once
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include <memory>
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidApp\DiploidEngineApp.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	// �E�C���h�E���[�h�ŋN��
//	ChangeWindowMode(TRUE);
//
//	// �c�w���C�u�����̏�����
//	if (DxLib_Init() < 0) return -1;
//
//	int font = 0, err = 0, size = 0;
//	font = CreateFontToHandle(NULL, 20, 4, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
//	err = GetFontStateToHandle(NULL, &size, NULL, font);
//
//	DrawFormatString(0, 0, GetColor(255, 255, 255), "font:0x%x  err:%d  size:%d", font, err, size);
//
//	WaitKey();
//
//	// �c�w���C�u�����̌�n��
//	DxLib_End();
//
//	// �\�t�g�̏I��
//	return 0;
//}

//debug��񂠂�Ə�����Ă��镨�̓����[�X����Ƃ���false�ɂ��邱�ƁB
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DiploidEngineApp *diploid_engine_app = new DiploidEngineApp();//���[�v�Ȃǂ̏����������

	Py_Initialize();//Python�̏�����

	//std::shared_ptr<DiploidEngineApp> diploid_engine_app;

	//DiploidEngineApp diploid_engine_app;

	diploid_engine_app->diploidEngineSetting.Init();//�G���W��������
	
	diploid_engine_app->FileCreate(diploid_engine_app);//�Q�[���N�����Ƀt�@�C�����쐬

	diploid_engine_app->OnceLoad(diploid_engine_app);//�Q�[���N�����ɉ��f�[�^��ǂݍ��ޏ���

	diploid_engine_app->OnceInit(diploid_engine_app);//�G���W�����������񂾂����̏��������鏈��

	diploid_engine_app->Load(diploid_engine_app);//�Q�[���N�����ɉ摜�f�[�^��ǂݍ��ޏ���

	diploid_engine_app->Init(diploid_engine_app);//�G���W�����������񂾂��摜�̏��������鏈��

	diploid_engine_app->diploidEngineNetwork.Init();//�l�b�g����������

	diploid_engine_app->diploidEngineInput.Init();//���͋@�평����


	while ((ProcessMessage() == 0) && (diploid_engine_app->diploidEngineSetting.GetExit() == 0))
	{	
		diploid_engine_app->diploidEngineScreen.FrameCountEnd();//1�t���[���̎��Ԃ��v�Z���I��

		diploid_engine_app->diploidEngineScreen.FrameCountStart();//1�t���[���̎��Ԃ��v�Z���J�n

		//�𑜓x���ύX�ύX���ꂽ�Ƃ��Ƀf�[�^���Ăѓǂݍ���
		if (diploid_engine_app->diploidEngineSetting.GetReloadFlag() == true)
		{	
			InitFontToHandle();//���ׂẴt�H���g�n���h�����폜

			diploid_engine_app->Load(diploid_engine_app);//�Q�[���N�����Ƀf�[�^��ǂݍ��ޏ���

			diploid_engine_app->Init(diploid_engine_app);//�摜�̏��������鏈��

			SetDrawScreen(DX_SCREEN_BACK);//����ʏ������I��

			diploid_engine_app->diploidEngineSetting.SetReloadFlag(false);//flag��false��
		}

		diploid_engine_app->diploidEngineSetting.Updata();

		diploid_engine_app->diploidEngineScreen.Init(diploid_engine_app->diploidEngineSetting.GetSystemData().refreshrate);//FPS������

		diploid_engine_app->diploidEngineNetwork.Update();//�l�b�g�����̍X�V

		diploid_engine_app->DestorySync();//�f�X�g���C�����𓯊�(�����ΏہFImpact / Layer)
		diploid_engine_app->diploidEngineLayer.Destory();//destory�ϐ���true�̂��̂��폜(Impact�������O�ɋL�q)
		diploid_engine_app->diploidEngineImpact.Destory();//�Փ˂��Ă�����̂��폜

		diploid_engine_app->diploidEngineImpact.Init();//�Փˏ����̏�����

		ClearDrawScreen();//��ʂɕ`�ʂ���Ă�����̂��폜

		diploid_engine_app->diploidEngineImpact.Updata();//�Փ˔���
		diploid_engine_app->diploidEngineLayer.Updata();//���C���[�摜���A�b�v�f�[�g

		diploid_engine_app->Updata(diploid_engine_app);//���C�����[�v

		diploid_engine_app->diploidEngineInput.Update();//���͋@��A�b�v�f�[�g

		diploid_engine_app->diploidEngineLayer.Draw(false);//���C���[�摜��\��(debug��񂠂�)
		diploid_engine_app->diploidEngineImpact.Draw(true);//�Փ˔͈͂�`��(debug��񂠂�)

		diploid_engine_app->Draw(diploid_engine_app);//���C���`��

		diploid_engine_app->Destory(diploid_engine_app);//�Q�[�����̓��I�폜�����B

		diploid_engine_app->diploidEngineInput.Draw(1000, 0);//���͔���̕\��(debug��񂠂�)

		diploid_engine_app->diploidEngineScreen.Update();//FPS���A�b�v�f�[�g

		diploid_engine_app->diploidEngineScreen.Draw(800, 0, true);//FPS��\��(debug��񂠂�)

		ScreenFlip();//�\��ʂ֕`��

		//diploid_engine_app->diploidEngineScreen.FrameCountEnd();//1�t���[���̎��Ԃ��v�Z���I��

		diploid_engine_app->diploidEngineScreen.Wait();//FPS�ҋ@
	}

	diploid_engine_app->End(diploid_engine_app);//�G���W���I���O�����B
	diploid_engine_app->diploidEngineNetwork.End();//�l�b�g�����̏I��
	InitSoftImage();//��������ɂ���\�t�g�E�F�A�摜�����ׂč폜
	InitGraph();//��������ɂ���摜�f�[�^�����ׂč폜
	InitSoundMem();//�������ɂ���T�E���h�����ׂč폜
	InitKeyInput();//���ׂẴL�[���͂��폜
	InitFontToHandle();//���ׂẴt�H���g�n���h�����폜
	diploid_engine_app->diploidEngineSetting.End();//�G���W���̏I��

	delete diploid_engine_app;

	//diploid_engine_app.reset();

	return 0;
}