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

	diploid_engine_app->diploidEngineSetting.Init();//�G���W��������
	
	diploid_engine_app->FileCreate();//�Q�[���N�����Ƀt�@�C�����쐬

	diploid_engine_app->Load();//�Q�[���N�����Ƀf�[�^��ǂݍ��ޏ���

	diploid_engine_app->Init();//�G���W�����������񂾂����������鏈��

	diploid_engine_app->diploidEngineNetwork.Init();//�l�b�g����������

	diploid_engine_app->diploidEngineInput.Init();//���͋@�평����

	while (ProcessMessage() == 0)
	{		
		diploid_engine_app->diploidEngineScreen.Init();//FPS������

		diploid_engine_app->diploidEngineNetwork.Update();//�l�b�g�����̍X�V

		diploid_engine_app->DestorySync();//�f�X�g���C�����𓯊�(�����ΏہFImpact / Layer)
		diploid_engine_app->diploidEngineLayer.Destory();//destory�ϐ���true�̂��̂��폜(Impact�������O�ɋL�q)
		diploid_engine_app->diploidEngineImpact.Destory();//�Փ˂��Ă�����̂��폜

		diploid_engine_app->diploidEngineImpact.Init();//�Փˏ����̏�����

		ClearDrawScreen();//��ʂɕ`�ʂ���Ă�����̂��폜

		diploid_engine_app->diploidEngineImpact.Updata();//�Փ˔���
		diploid_engine_app->diploidEngineLayer.Updata();//���C���[�摜���A�b�v�f�[�g

		diploid_engine_app->Updata();//���C�����[�v
		
		diploid_engine_app->diploidEngineInput.Update();//���͋@��A�b�v�f�[�g

		diploid_engine_app->diploidEngineLayer.Draw(false);//���C���[�摜��\��(debug��񂠂�)
		diploid_engine_app->diploidEngineImpact.Draw(true);//�Փ˔͈͂�`��(debug��񂠂�)

		diploid_engine_app->Draw();//���C���`��

		diploid_engine_app->Destory();//�Q�[�����̓��I�폜�����B

		diploid_engine_app->diploidEngineInput.Draw(1000, 0);//���͔���̕\��(debug��񂠂�)

		diploid_engine_app->diploidEngineScreen.Update();//FPS���A�b�v�f�[�g

		diploid_engine_app->diploidEngineScreen.Draw(0,0,true);//FPS��\��(debug��񂠂�)

		ScreenFlip();//�\��ʂ֕`��

		diploid_engine_app->diploidEngineScreen.Wait();//FPS�ҋ@
	}

	diploid_engine_app->End();//�G���W���I���O�����B
	diploid_engine_app->diploidEngineNetwork.End();//�l�b�g�����̏I��
	InitSoftImage();//��������ɂ���\�t�g�E�F�A�摜�����ׂč폜
	InitGraph();//��������ɂ���摜�f�[�^�����ׂč폜
	InitSoundMem();//�������ɂ���T�E���h�����ׂč폜
	InitKeyInput();//���ׂẴL�[���͂��폜
	diploid_engine_app->diploidEngineSetting.End();//�G���W���̏I��

	delete diploid_engine_app;

	//diploid_engine_app.reset();

	return 0;
}