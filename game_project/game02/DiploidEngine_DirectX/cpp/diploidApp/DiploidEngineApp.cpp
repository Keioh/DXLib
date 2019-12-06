#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	kaitaku.SwitchButtonBOX_Load("texter/command/kaitaku.png", 128, 64);//�J��{�^���̉摜�����[�h
	nougyou.SwitchButtonBOX_Load("texter/command/nougyou.png", 128, 64);//�_�Ƌ�{�^���̉摜�����[�h
	sangyou.SwitchButtonBOX_Load("texter/command/sangyou.png", 128, 64);//�Y�Ƌ�{�^���̉摜�����[�h
	syougyou.SwitchButtonBOX_Load("texter/command/syougyou.png", 128, 64);//���Ƌ�{�^���̉摜�����[�h
	sarati.SwitchButtonBOX_Load("texter/command/sarati.png", 128, 64);//�X�n��{�^���̉摜�����[�h
	zikkou.OneClickButtonBOX_Load("texter/command/zikkou.png", 128, 64);//���s�{�^���̉摜�����[�h
	play.OneClickButtonBOX_Load("texter/command/teisi.png", "texter/command/sokudo_1.png", "texter/command/sokudo_2.png", 128, 64);//�v���C�{�^���̉摜�����[�h

	for (int count = 0; count < 9; ++count)
	{	
		field[count].SwitchButtonBOX_Load("texter/field/nasi.png", "texter/field/nouku.png", "texter/field/sanku.png", "texter/field/syouku.png", 128, 128);//�e���̏����摜�����[�h
	}
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	mouse_point.point.mouse_point_move_flag = TRUE;
	diploidEngineImpact.PushPoint(mouse_point.point);

	field_position = VGet(1280 / 2 - 64, 720 / 2 - 32, 0);
	ku_position = VGet(0, 128, 0);

	kaitaku.SwitchButtonBOX_Init(VGet(ku_position.x, ku_position.y, 0), VGet(128, 64, 0), "kaitaku");//�J��{�^���̏�����
	nougyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y, 0), VGet(128, 64, 0), "nougyou");//�_�Ƌ�{�^���̏�����
	sangyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + 64, 0), VGet(128, 64, 0), "sangyou");//�Y�Ƌ�{�^���̏�����
	syougyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + (64 * 2), 0), VGet(128, 64, 0), "syougyou");//���Ƌ�̏�����
	sarati.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + (64 * 3), 0), VGet(128, 64, 0), "sarati");//�X�n�̏�����

	zikkou.OneClickButtonBOX_Init(VGet(ku_position.x + (128 * 2), ku_position.y, 0), VGet(128, 64, 0), "zikkou");//���s�{�^���̏�����

	play.OneClickButtonBOX_Init(VGet(1280 - 128, 720 - 64, 0), VGet(128, 64, 0), "play");//�v���C�{�^���̏�����
	play.OneClickButtonBOX_Push(diploidEngineImpact);//�v���C�{�^���̒ǉ�

	//��̋��̏�����(4������)
	field[0].SwitchButtonBOX_Init(VGet(field_position.x - 128, field_position.y - 128, 0), VGet(128, 128, 0), "main_field_0", DIPLOID_LAYER_00);
	field[0].SwitchButtonBOX_Push(diploidEngineImpact);

	field[1].SwitchButtonBOX_Init(VGet(field_position.x, field_position.y - 128, 0), VGet(128, 128, 0), "main_field_1", DIPLOID_LAYER_00);
	field[1].SwitchButtonBOX_Push(diploidEngineImpact);

	field[2].SwitchButtonBOX_Init(VGet(field_position.x + 128, field_position.y - 128, 0), VGet(128, 128, 0), "main_field_2", DIPLOID_LAYER_00);
	field[2].SwitchButtonBOX_Push(diploidEngineImpact);

	field[3].SwitchButtonBOX_Init(VGet(field_position.x - 128, field_position.y, 0), VGet(128, 128, 0), "main_field_3", DIPLOID_LAYER_00);
	field[3].SwitchButtonBOX_Push(diploidEngineImpact);

	field[4].SwitchButtonBOX_Init(VGet(field_position.x, field_position.y, 0), VGet(128, 128, 0), "main_field_4", DIPLOID_LAYER_00);
	field[4].SwitchButtonBOX_Push(diploidEngineImpact);

	field[5].SwitchButtonBOX_Init(VGet(field_position.x + 128, field_position.y, 0), VGet(128, 128, 0), "main_field_5", DIPLOID_LAYER_00);
	field[5].SwitchButtonBOX_Push(diploidEngineImpact);

	field[6].SwitchButtonBOX_Init(VGet(field_position.x - 128, field_position.y + 128, 0), VGet(128, 128, 0), "main_field_6", DIPLOID_LAYER_00);
	field[6].SwitchButtonBOX_Push(diploidEngineImpact);

	field[7].SwitchButtonBOX_Init(VGet(field_position.x, field_position.y + 128, 0), VGet(128, 128, 0), "main_field_7", DIPLOID_LAYER_00);
	field[7].SwitchButtonBOX_Push(diploidEngineImpact);

	field[8].SwitchButtonBOX_Init(VGet(field_position.x + 128, field_position.y + 128, 0), VGet(128, 128, 0), "main_field_8", DIPLOID_LAYER_00);
	field[8].SwitchButtonBOX_Push(diploidEngineImpact);

}

void DiploidEngineApp::LoadUpdata()//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�Q�[�����Ƀ��[�h�������f�[�^�Ȃ�)
{

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	//�v���C�{�^���̏���
	if (play.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
	{
		play_type += 1;

		if (play_type > 2)
		{
			play_type = 0;
		}
	}

	for (int count = 0; count < 9; ++count)
	{
		//�ǂꂩ�̋���I�����Ă����
		if (field[count].SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
		{
			//�N���b�N�����ꏊ�ȊO�̃t���O��FALSE�ɕύX����
			for (int flag_count = 0; flag_count < 9; ++flag_count)
			{
				if (count != flag_count)
				{
					if (field[flag_count].GetSwitchButton_Flag() == true)
					{
						field[flag_count].SwitchButton_Flag_Change(false);//�I���������ȊO�̋��̑I��������

						kaitaku.SwitchButton_Flag_Change(false);//�J��{�^����FALSE��
						nougyou.SwitchButton_Flag_Change(false);//�_�Ƌ�{�^����FALSE��
						sangyou.SwitchButton_Flag_Change(false);//�Y�Ƌ�{�^����FALSE��
						syougyou.SwitchButton_Flag_Change(false);//���Ƌ�{�^����FALSE��
						sarati.SwitchButton_Flag_Change(false);//�X�n�{�^����FALSE��
					}
				}
			}
			
			kaitaku_system.OnePushBOX_Impact(diploidEngineImpact, kaitaku.box);//�J��{�^���̒ǉ�
			kaitaku_system.FlagReset_OneDeleteBOX();//�J��{�^���̍폜�t���O�����Z�b�g			

			//�J��{�^��
			if (kaitaku.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
			{	
				nougyou_system.OnePushBOX_Impact(diploidEngineImpact, nougyou.box);//�_�Ƌ�{�^���̒ǉ�
				sangyou_system.OnePushBOX_Impact(diploidEngineImpact, sangyou.box);//�Y�Ƌ�{�^���̒ǉ�
				syougyou_system.OnePushBOX_Impact(diploidEngineImpact, syougyou.box);//���Ƌ�{�^���̒ǉ�
				sarati_system.OnePushBOX_Impact(diploidEngineImpact, sarati.box);//�X�n�{�^���̒ǉ�

				nougyou_system.FlagReset_OneDeleteBOX();//�_�Ƌ�{�^���̍폜�t���O�����Z�b�g
				sangyou_system.FlagReset_OneDeleteBOX();//�Y�Ƌ�{�^���̍폜�t���O�����Z�b�g
				syougyou_system.FlagReset_OneDeleteBOX();//���Ƌ�{�^���̍폜�t���O�����Z�b�g
				sarati_system.FlagReset_OneDeleteBOX();//�X�n�{�^���̍폜�t���O�����Z�b�g

				//�_�Ƌ��{�^���̃A�b�v�f�[�g
				if (nougyou.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
				{
					sangyou.SwitchButton_Flag_Change(false);//�Y�Ƌ�̃{�^�����I�t�ɂ���B
					syougyou.SwitchButton_Flag_Change(false);//���Ƌ�̃{�^�����I�t�ɂ���B
					sarati.SwitchButton_Flag_Change(false);//�X�n�̃{�^�����I�t�ɂ���B

					zikkou_system.OnePushBOX_Impact(diploidEngineImpact, zikkou.box);//���s�{�^���̒ǉ�
					zikkou_system.FlagReset_OneDeleteBOX();//���s�{�^���̍폜�t���O�����Z�b�g����B

					if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)//���s�{�^���̃A�b�v�f�[�g
					{
						field_type[count] = 1;//�_��ɕύX
					}
				}

				//�Y�Ƌ��{�^���̃A�b�v�f�[�g
				if (sangyou.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
				{
					nougyou.SwitchButton_Flag_Change(false);//�_�Ƌ�̃{�^�����I�t�ɂ���B
					syougyou.SwitchButton_Flag_Change(false);//���Ƌ�̃{�^�����I�t�ɂ���B
					sarati.SwitchButton_Flag_Change(false);//�X�n�̃{�^�����I�t�ɂ���B

					zikkou_system.OnePushBOX_Impact(diploidEngineImpact, zikkou.box);//���s�{�^���̒ǉ�
					zikkou_system.FlagReset_OneDeleteBOX();//���s�{�^���̍폜�t���O�����Z�b�g����B

					if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//���s�{�^���̃A�b�v�f�[�g
					{
						field_type[count] = 2;//�Y��ɕύX
					}
				}

				//���Ƌ��{�^���̃A�b�v�f�[�g
				if (syougyou.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
				{
					nougyou.SwitchButton_Flag_Change(false);//�_�Ƌ�̃{�^�����I�t�ɂ���B
					sangyou.SwitchButton_Flag_Change(false);//�Y�Ƌ�̃{�^�����I�t�ɂ���B
					sarati.SwitchButton_Flag_Change(false);//�X�n�̃{�^�����I�t�ɂ���B

					zikkou_system.OnePushBOX_Impact(diploidEngineImpact, zikkou.box);//���s�{�^���̒ǉ�
					zikkou_system.FlagReset_OneDeleteBOX();//���s�{�^���̍폜�t���O�����Z�b�g����B

					if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//���s�{�^���̃A�b�v�f�[�g
					{
						field_type[count] = 3;//����ɕύX
					}
				}				

				//�X�n�{�^���̃A�b�v�f�[�g
				if (sarati.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
				{
					nougyou.SwitchButton_Flag_Change(false);//�_�Ƌ�̃{�^�����I�t�ɂ���B
					sangyou.SwitchButton_Flag_Change(false);//�Y�Ƌ�̃{�^�����I�t�ɂ���B
					syougyou.SwitchButton_Flag_Change(false);//���Ƌ�̃{�^�����I�t�ɂ���B

					zikkou_system.OnePushBOX_Impact(diploidEngineImpact, zikkou.box);//���s�{�^���̒ǉ�
					zikkou_system.FlagReset_OneDeleteBOX();//���s�{�^���̍폜�t���O�����Z�b�g����B

					if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//���s�{�^���̃A�b�v�f�[�g
					{
						field_type[count] = 0;//�X�n�ɕύX
					}
				}

				//���{�^���̃t���O�v�Z����
				nougyou_sangyou_syougou_flags = (nougyou.GetSwitchButton_Flag() || sangyou.GetSwitchButton_Flag() || syougyou.GetSwitchButton_Flag() || sarati.GetSwitchButton_Flag());

				if (nougyou_sangyou_syougou_flags == false)//���{�^�����ׂĂ��I�t�Ȃ�
				{
					zikkou_system.OneDeleteBOX_Impact(diploidEngineImpact, "zikkou");//���s�{�^���̍폜
					zikkou_system.FlagReset_OnePushBOX();//���s�{�^���̒ǉ��t���O�����Z�b�g
				}
			}
			else//�J��{�^�����I�t�̂Ƃ�
			{
				nougyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "nougyou");//�_�Ƌ�{�^���̍폜
				sangyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "sangyou");//�Y�Ƌ�{�^���̍폜
				syougyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "syougyou");//���Ƌ�{�^���̍폜
				sarati_system.OneDeleteBOX_Impact(diploidEngineImpact, "sarati");//�X�n�{�^���̍폜
				zikkou_system.OneDeleteBOX_Impact(diploidEngineImpact, "zikkou");//���s�{�^���̍폜

				nougyou_system.FlagReset_OnePushBOX();//�_�Ƌ�{�^���̒ǉ��t���O�����Z�b�g
				sangyou_system.FlagReset_OnePushBOX();//�Y�Ƌ�{�^���̒ǉ��t���O�����Z�b�g
				syougyou_system.FlagReset_OnePushBOX();//���Ƌ�{�^���̒ǉ��t���O�����Z�b�g
				sarati_system.FlagReset_OnePushBOX();//�X�n�{�^���̒ǉ��t���O�����Z�b�g
				zikkou_system.FlagReset_OnePushBOX();//���s�{�^���̒ǉ��t���O�����Z�b�g
			}
		}		
	}	

	//���^�C���̃t���O�̌v�Z����
	field_all_flag = field[0].GetSwitchButton_Flag() || field[1].GetSwitchButton_Flag() || field[2].GetSwitchButton_Flag() || field[3].GetSwitchButton_Flag() || field[4].GetSwitchButton_Flag() || field[5].GetSwitchButton_Flag() || field[6].GetSwitchButton_Flag() || field[7].GetSwitchButton_Flag() || field[8].GetSwitchButton_Flag();
	
	//�{�^���ނ̍폜�Ə���������
	if (field_all_flag == false)
	{
		kaitaku.SwitchButton_Flag_Change(false);//�J��{�^����FALSE��
		nougyou.SwitchButton_Flag_Change(false);//�_�Ƌ�{�^����FALSE��
		sangyou.SwitchButton_Flag_Change(false);//�Y�Ƌ�{�^����FALSE��
		syougyou.SwitchButton_Flag_Change(false);//���Ƌ�{�^����FALSE��
		sarati.SwitchButton_Flag_Change(false);//�X�n�{�^����FALSE��

		kaitaku_system.OneDeleteBOX_Impact(diploidEngineImpact, "kaitaku");//�J��{�^���̍폜
		kaitaku_system.FlagReset_OnePushBOX();//�J��{�^���̒ǉ��t���O�����Z�b�g

		nougyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "nougyou");//�_�Ƌ�{�^���̍폜
		sangyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "sangyou");//�Y�Ƌ�{�^���̍폜
		syougyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "syougyou");//���Ƌ�{�^���̍폜
		sarati_system.OneDeleteBOX_Impact(diploidEngineImpact, "sarati");//�X�n�{�^���̍폜
		zikkou_system.OneDeleteBOX_Impact(diploidEngineImpact, "zikkou");//���s�{�^���̍폜

		nougyou_system.FlagReset_OnePushBOX();//�_�Ƌ�{�^���̒ǉ��t���O�����Z�b�g
		sangyou_system.FlagReset_OnePushBOX();//�Y�Ƌ�{�^���̒ǉ��t���O�����Z�b�g
		syougyou_system.FlagReset_OnePushBOX();//���Ƌ�{�^���̒ǉ��t���O�����Z�b�g
		zikkou_system.FlagReset_OnePushBOX();//���s�{�^���̒ǉ��t���O�����Z�b�g
		sarati_system.FlagReset_OnePushBOX();//�X�n�{�^���̒ǉ��t���O�����Z�b�g

	}
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	//�v���C�{�^���̕`��
	play.OneClickButtonBOX_Draw(play_type);

	//���ƃR�}���h�{�^���̕\��
	for (int count = 0; count < 9; ++count)
	{
		if (field[count].GetSwitchButton_Flag() == true)
		{
			//�J��{�^���̕`��
			kaitaku.SwitchButtonBOX_Draw();

			//�J��{�^�����I���Ȃ�
			if (kaitaku.GetSwitchButton_Flag() == true)
			{
				nougyou.SwitchButtonBOX_Draw();
				sangyou.SwitchButtonBOX_Draw();
				syougyou.SwitchButtonBOX_Draw();
				sarati.SwitchButtonBOX_Draw();

				if ((nougyou.GetSwitchButton_Flag() || sangyou.GetSwitchButton_Flag() || syougyou.GetSwitchButton_Flag() || sarati.GetSwitchButton_Flag()) == true)
				{
					zikkou.OneClickButtonBOX_Draw();
				}
			}
		}

		//���̕`��
		field[count].SwitchButtonBOX_Draw(field_type[count]);
	}
}

void DiploidEngineApp::End()//engine�I���O�����B
{

}