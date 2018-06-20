#pragma once
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidApp\DiploidEngineApp.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DiploidEngineApp diploid_engine_app;//���[�v�Ȃǂ̏����������

	diploid_engine_app.diploidEngineSetting.Init();//�G���W��������

	diploid_engine_app.Load();//�Q�[���N�����Ƀf�[�^��ǂݍ��ޏ���

	diploid_engine_app.Init();//�G���W�����������񂾂����������鏈��

	diploid_engine_app.diploidEngineNetwork.Init();//�l�b�g����������

	while (ProcessMessage() == 0)
	{
		diploid_engine_app.diploidEngineNetwork.Update();//�l�b�g�����̍X�V
		diploid_engine_app.diploidEngineImpact.Init();//�Փˏ����̏�����

		ClearDrawScreen();//��ʂɕ`�ʂ���Ă�����̂��폜

		//diploid_engine_app.diploidEngineImpact.
		//diploid_engine_app.diploidEngineLayer.Updata();

		diploid_engine_app.Updata();//���C�����[�v

		//diploid_engine_app.diploidEngineImpact.Updata();
		//diploid_engine_app.diploidEngineLayer.Draw();

		diploid_engine_app.Draw();//���C���`��

		ScreenFlip();//�\��ʂ֕`��
	}

	diploid_engine_app.diploidEngineSound.End();//�������ɂ���T�E���h�����ׂč폜
	diploid_engine_app.diploidEngineNetwork.End();//�l�b�g�����̏I��
	InitGraph();//��������ɂ���摜�f�[�^�����ׂč폜
	diploid_engine_app.diploidEngineSetting.End();//�G���W���̏I��

	return 0;
}