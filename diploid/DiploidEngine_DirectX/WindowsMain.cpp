#pragma once
#include <memory>
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidApp\DiploidEngineApp.h"

//debug��񂠂�Ə�����Ă��镨�̓����[�X����Ƃ���false�ɂ��邱�ƁB
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DiploidEngineApp *diploid_engine_app = new DiploidEngineApp();//���[�v�Ȃǂ̏����������
	
	//std::shared_ptr<DiploidEngineApp> diploid_engine_app;

	//DiploidEngineApp diploid_engine_app;

	diploid_engine_app->diploidEngineSetting.Init();//�G���W��������
	
	diploid_engine_app->FileCreate(diploid_engine_app);//�Q�[���N�����Ƀt�@�C�����쐬

	diploid_engine_app->SoundLoad(diploid_engine_app);//�Q�[���N�����ɉ��f�[�^��ǂݍ��ޏ���

	diploid_engine_app->SoundInit(diploid_engine_app);//�G���W�����������񂾂����̏��������鏈��

	diploid_engine_app->GraphicsLoad(diploid_engine_app);//�Q�[���N�����ɉ摜�f�[�^��ǂݍ��ޏ���

	diploid_engine_app->GraphicsInit(diploid_engine_app);//�G���W�����������񂾂��摜�̏��������鏈��

	diploid_engine_app->diploidEngineNetwork.Init();//�l�b�g����������

	diploid_engine_app->diploidEngineInput.Init();//���͋@�평����

	diploid_engine_app->diploidEngineScreen.FrameCount();//60�t���[���̎��Ԃ��v�Z

	while ((ProcessMessage() == 0) && (diploid_engine_app->diploidEngineSetting.GetExit() == 0))
	{		
		//�𑜓x���ύX�ύX���ꂽ�Ƃ��Ƀf�[�^���Ăѓǂݍ���
		if (diploid_engine_app->diploidEngineSetting.GetReloadFlag() == true)
		{
			diploid_engine_app->GraphicsLoad(diploid_engine_app);//�Q�[���N�����Ƀf�[�^��ǂݍ��ޏ���

			diploid_engine_app->GraphicsInit(diploid_engine_app);//�摜�̏��������鏈��

			SetDrawScreen(DX_SCREEN_BACK);//����ʏ������I��

			diploid_engine_app->diploidEngineSetting.SetReloadFlag(false);//flag��false��
		}
		//else if(diploid_engine_app->diploidEngineSetting.GetReloadFlag() == false)
		//{
			diploid_engine_app->diploidEngineSetting.Updata();

			diploid_engine_app->diploidEngineScreen.Init(diploid_engine_app->diploidEngineSetting.refresh_rate);//FPS������

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

			diploid_engine_app->diploidEngineScreen.Wait();//FPS�ҋ@
		//}
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