#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	map.Load();//�}�b�v�̃��[�h
	ui.Load();
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	input.Init();//�C���v�b�g�̏�����

	map.Init(VGet(0, 0, 0));//�}�b�v�̏�����

	ui.Init(VGet(0, 128, 0), 0.2f);
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	input.Update();//�C���v�b�g�̍X�V

	map.Updata(&input);//�}�b�v�̃A�b�v�f�[�g

	//�^�C�����𓾂�
	if (map.GetHitFildInfomation().GetHit() == true)
	{
		ui_info_type = map.GetHitFildInfomation().GetTerrainType();
	}
	else
	{
		ui_info_type = TERRAIN_TYPE_NOTHING;
	}

	//�I�������}�b�v������𓾂�
	if (map.GetClickedFildInfomation().GetClick() == 1)//�}�b�v�̂ǂ������N���b�N���Ă�����
	{

		//�����_�������Ă�������UI�t���O�𗧂Ă�
		if (map.GetClickedFildInfomation().GetBuildingType() == BUILDING_TYPE_MY_BASE)
		{
			ui_type = UI_MY_BASE;//�����_UI�̕\���t���O�𗧂Ă�
		}
		else
		{
			ui_type = UI_NO_SELECTED;
			ui.ResetFlag();//�R�}���h�t���O��S�ă��Z�b�g
		}

		//UI_NO_SELECTED�łȂ����
		if (ui_type > UI_NO_SELECTED)
		{
			//UI�̍X�V
			ui.Updata(&input);
		}

		//UI�ɃJ�[�\���������Ă������Ƀ}�b�v��I�������Ȃ��悤�ɂ��鏈��
		if (ui.GetHit() == true)
		{
			map.SetCollisionActiveFlag(false);
		}
		else
		{
			map.SetCollisionActiveFlag(true);
		}
	}
	else
	{
		//�ǂ����N���b�N���Ă��Ȃ�
		ui_type = UI_NO_SELECTED;
		ui.ResetFlag();//�R�}���h�t���O��S�ă��Z�b�g
	}
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	bool debug = true;

	map.Draw(true, debug);//�}�b�v�̕`��

	//UI�̕\��
	if (ui_type == UI_MY_BASE)//�����_�pUI
	{
		ui.Draw(true, debug);
	}

	//�I�������^�C���̏��(��)
	if (ui_info_type == TERRAIN_TYPE_GRASS)
	{
		DrawBoxAA(0, 0, 200, 30, GetColor(200, 200, 200), TRUE);
		DrawString(10, 5, "�n�`�^�C�v : ����", GetColor(0, 0, 0));
	}

	if (ui_info_type == TERRAIN_TYPE_ROCKS)
	{
		DrawBoxAA(0, 0, 200, 30, GetColor(200, 200, 200), TRUE);

		DrawString(10, 5, "�n�`�^�C�v : ���", GetColor(0, 0, 0));
	}

	if (ui_info_type == TERRAIN_TYPE_MOUNTAIN)
	{
		DrawBoxAA(0, 0, 200, 30, GetColor(200, 200, 200), TRUE);

		DrawString(10, 5, "�n�`�^�C�v : �R�x", GetColor(0, 0, 0));
	}

}

void DiploidEngineApp::Destory()//���[�v���ɍ폜�������I�u�W�F�N�g������ꍇ�͂����ō폜�����������B
{

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}