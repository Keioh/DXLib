#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	status.image.Load("texter/ui/status.png");//�X�e�[�^�X�摜�̃��[�h
	status_down.image.Load("texter/ui/status_down.png");//�X�e�[�^�X�����̉摜�̃��[�h
	nouku_setumei.image.Load("texter/ui/nouku_setumei.png");//�X�e�[�^�X�����̔_������摜�̃��[�h
	sanku_setumei.image.Load("texter/ui/sanku_setumei.png");//�X�e�[�^�X�����̎Y������摜�̃��[�h
	syouku_setumei.image.Load("texter/ui/syouku_setumei.png");//�X�e�[�^�X�����̏�������摜�̃��[�h
	kaitaku_setumei.image.Load("texter/ui/kaitaku_setumei.png");//�X�e�[�^�X�����̊J������摜�̃��[�h
	sarati_setumei.image.Load("texter/ui/sarati_setumei.png");//�X�e�[�^�X�����̍X�n�����摜�̃��[�h
	play_setumei.image.Load("texter/ui/play_setumei.png");//�X�e�[�^�X�����̃v���C�{�^�������摜�̃��[�h

	kaitaku.SwitchButtonBOX_Load("texter/command/kaitaku.png", 128, 64);//�J��{�^���̉摜�����[�h
	nougyou.SwitchButtonBOX_Load("texter/command/nougyou.png", 128, 64);//�_�Ƌ�{�^���̉摜�����[�h
	sangyou.SwitchButtonBOX_Load("texter/command/sangyou.png", 128, 64);//�Y�Ƌ�{�^���̉摜�����[�h
	syougyou.SwitchButtonBOX_Load("texter/command/syougyou.png", 128, 64);//���Ƌ�{�^���̉摜�����[�h
	sarati.SwitchButtonBOX_Load("texter/command/sarati.png", 128, 64);//�X�n��{�^���̉摜�����[�h
	zikkou.OneClickButtonBOX_Load("texter/command/zikkou.png", 128, 64);//���s�{�^���̉摜�����[�h
	play.OneClickButtonBOX_Load("texter/command/teisi.png", "texter/command/sokudo_1.png", "texter/command/sokudo_2.png", 128, 64);//�v���C�{�^���̉摜�����[�h

	for (int count = 0; count < 9; ++count)
	{
		kaitaku_nouku[count].image.Load("texter/field/nouku_kaitaku_tyu.png");//�_����J�񒆉摜�̃��[�h
		kaitaku_syouku[count].image.Load("texter/field/syouku_kaitaku_tyu.png");//������J�񒆉摜�̃��[�h
		kaitaku_sanku[count].image.Load("texter/field/sanku_kaitaku_tyu.png");//�Y����J�񒆉摜�̃��[�h
		kaitaku_sarati[count].image.Load("texter/field/sarati_kaitaku_tyu.png");//�X�n���J�񒆉摜�̃��[�h
		double_1_05[count].image.Load("texter/field/1_05.png");//1.05�{�摜�̃��[�h
		double_1_025[count].image.Load("texter/field/1_025.png");//1.025�{�摜�̃��[�h

		if (count == 4)
		{
			field[4].SwitchButtonBOX_Load("texter/field/tyuuou.png", 128, 128);//������{�^���̉摜�����[�h
		}
		else
		{
			field[count].SwitchButtonBOX_Load("texter/field/nasi.png", "texter/field/nouku.png", "texter/field/sanku.png", "texter/field/syouku.png", 128, 128);//�e���̏����摜�����[�h
		}
	}
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	for (int count = 0; count < 9; ++count)
	{
		sakumotu_scale[count] = 1.0f;
		sikinn_scale[count] = 1.0f;
		sannsyutu_scale[count] = 1.0f;
	}

	status.image.Init(VGet(384/2, 64, 0));//�X�e�[�^�X�摜�̏�����
	status_down.image.Init(VGet(1280 / 2, 720 - 16, 0));//�X�e�[�^�X�����摜�̏�����
	nouku_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//�X�e�[�^�X�����̔_������摜�̏�����
	sanku_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//�X�e�[�^�X�����̎Y������摜�̏�����
	syouku_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//�X�e�[�^�X�����̏�������摜�̏�����
	kaitaku_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//�X�e�[�^�X�����̊J������摜�̏�����
	sarati_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//�X�e�[�^�X�����̍X�n�����摜�̏�����
	play_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//�X�e�[�^�X�����̃v���C�{�^�������摜�̏�����

	mouse_point.point.mouse_point_move_flag = TRUE;
	diploidEngineImpact.PushPoint(mouse_point.point);

	field_position = VGet(1280 / 2 - 64, 720 / 2 - 32, 0);
	ku_position = VGet(0, 128, 0);

	//�����摜�̏�����
	{
		kaitaku_nouku[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//�_����J�񒆉摜�̏�����
		kaitaku_syouku[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//������J�񒆉摜�̏�����
		kaitaku_sanku[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//�Y����J�񒆉摜�̏�����
		kaitaku_sarati[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//�X�n���J�񒆉摜�̏�����
		double_1_05[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//1.05�{�摜�̏�����
		double_1_025[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//1.025�{�摜�̏�����

		kaitaku_nouku[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//�_����J�񒆉摜�̏�����
		kaitaku_syouku[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//������J�񒆉摜�̏�����
		kaitaku_sanku[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//�Y����J�񒆉摜�̏�����
		kaitaku_sarati[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//�X�n���J�񒆉摜�̏�����
		double_1_05[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//1.05�{�摜�̏�����
		double_1_025[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//1.025�{�摜�̏�����

		kaitaku_nouku[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//�_����J�񒆉摜�̏�����
		kaitaku_syouku[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//������J�񒆉摜�̏�����
		kaitaku_sanku[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//�Y����J�񒆉摜�̏�����
		kaitaku_sarati[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//�X�n���J�񒆉摜�̏�����
		double_1_05[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//1.05�{�摜�̏�����
		double_1_025[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//1.025�{�摜�̏�����

		kaitaku_nouku[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//�_����J�񒆉摜�̏�����
		kaitaku_syouku[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//������J�񒆉摜�̏�����
		kaitaku_sanku[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//�Y����J�񒆉摜�̏�����
		kaitaku_sarati[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//�X�n���J�񒆉摜�̏�����
		double_1_05[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//1.05�{�摜�̏�����
		double_1_025[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//1.025�{�摜�̏�����

		kaitaku_nouku[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//�_����J�񒆉摜�̏�����
		kaitaku_syouku[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//������J�񒆉摜�̏�����
		kaitaku_sanku[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//�Y����J�񒆉摜�̏�����
		kaitaku_sarati[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//�X�n���J�񒆉摜�̏�����
		double_1_05[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//1.05�{�摜�̏�����
		double_1_025[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//1.025�{�摜�̏�����

		kaitaku_nouku[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//�_����J�񒆉摜�̏�����
		kaitaku_syouku[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//������J�񒆉摜�̏�����
		kaitaku_sanku[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//�Y����J�񒆉摜�̏�����
		kaitaku_sarati[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//�X�n���J�񒆉摜�̏�����
		double_1_05[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//1.05�{�摜�̏�����
		double_1_025[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//1.025�{�摜�̏�����

		kaitaku_nouku[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//�_����J�񒆉摜�̏�����
		kaitaku_syouku[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//������J�񒆉摜�̏�����
		kaitaku_sanku[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//�Y����J�񒆉摜�̏�����
		kaitaku_sarati[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//�X�n���J�񒆉摜�̏�����
		double_1_05[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//1.05�{�摜�̏�����
		double_1_025[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//1.025�{�摜�̏�����

		kaitaku_nouku[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//�_����J�񒆉摜�̏�����
		kaitaku_syouku[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//������J�񒆉摜�̏�����
		kaitaku_sanku[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//�Y����J�񒆉摜�̏�����
		kaitaku_sarati[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//�X�n���J�񒆉摜�̏�����
		double_1_05[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//1.05�{�摜�̏�����
		double_1_025[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//1.025�{�摜�̏�����

		kaitaku_nouku[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//�_����J�񒆉摜�̏�����
		kaitaku_syouku[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//������J�񒆉摜�̏�����
		kaitaku_sanku[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//�Y����J�񒆉摜�̏�����
		kaitaku_sarati[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//�X�n���J�񒆉摜�̏�����
		double_1_05[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//1.05�{�摜�̏�����
		double_1_025[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//1.025�{�摜�̏�����

	}

	kaitaku.SwitchButtonBOX_Init(VGet(ku_position.x, ku_position.y, 0), VGet(128, 64, 0), "kaitaku");//�J��{�^���̏�����
	nougyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y, 0), VGet(128, 64, 0), "nougyou");//�_�Ƌ�{�^���̏�����
	sangyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + 64, 0), VGet(128, 64, 0), "sangyou");//�Y�Ƌ�{�^���̏�����
	syougyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + (64 * 2), 0), VGet(128, 64, 0), "syougyou");//���Ƌ�̏�����
	sarati.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + (64 * 3), 0), VGet(128, 64, 0), "sarati");//�X�n�̏�����

	zikkou.OneClickButtonBOX_Init(VGet(ku_position.x + (128 * 2), ku_position.y, 0), VGet(128, 64, 0), "zikkou");//���s�{�^���̏�����

	play.OneClickButtonBOX_Init(VGet(1280 - 128, 720 - 64 - 32, 0), VGet(128, 64, 0), "play");//�v���C�{�^���̏�����
	play.OneClickButtonBOX_Push(diploidEngineImpact);//�v���C�{�^���̒ǉ�

	//��̋��̏�����(4������)
	{
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
			play_type = 0;//��~�ɖ߂�B
		}
	}

	if (play_type == 1)//�Q�[�����x1�{�̂Ƃ��̏���
	{
		//���Ԃ̏���
		++fps_time;//���Ԃ𑝂₷�B

		if (fps_time >= 5)
		{
			++second;//�b�𑝂₷
			fps_time = 0;//������
		}

		if (second >= 1)
		{
			++minute;//���𑝂₷
			second = 0;//������
		}

		if (minute >= 1)
		{
			++hour;//���𑝂₷�B
			minute = 0;//������
		}

		if (hour >= 24)
		{
			day_flag = true;//�����������t���O���I���ɂ���B
			++day;//���𑝂₷�B
			hour = 0;//������
		}

		//�����i�񂾂�(for���O����)
		if (day_flag == true)
		{
			//�������̏�����
			sakumotu_syuunyuu = 0;
			sannsyutu_syuunyuu = 0;
			sikin_syuunyuu = 0;
		}

		//�J��Ǝ����̏���
		for (int count = 0; count < 9; ++count)
		{
			//�����i�񂾂�
			if (day_flag == true)
			{
				if (kaitaku_time[count] != 0)//�J�񎞊Ԃ�0�łȂ��Ȃ�
				{
					--kaitaku_time[count];//�J�񎞊Ԃ����炷
				}

				//��������
				switch (count)
				{
				case 0:
					if (field_type[0] == 1)//�_��ł����
					{
						sakumotu_scale[0] = 1.0f;

						if (field_type[1] == 1)
						{
							sakumotu_scale[0] += all_basic_scale;
						}
						if (field_type[3] == 1)
						{
							sakumotu_scale[0] += all_basic_scale;
						}	

						sakumotu += 5 * sakumotu_scale[0];//�앨�𑝂₷
						sakumotu_syuunyuu += 5 * sakumotu_scale[0];//�앨�̎������𑝂₷
					}
					if (field_type[0] == 2)//�Y��ł����
					{
						sannsyutu_scale[0] = 1.0f;

						if (field_type[1] == 2)
						{
							sannsyutu_scale[0] += all_basic_scale;
						}
						if (field_type[3] == 2)
						{
							sannsyutu_scale[0] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[0];//�Y�o�𑝂₷
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[0];//�Y�o�̎������𑝂₷
					}
					if (field_type[0] == 3)//����ł����
					{
						sikinn_scale[0] = 1.0f;

						if (field_type[1] == 3)
						{
							sikinn_scale[0] += all_basic_scale;
						}
						if (field_type[3] == 3)
						{
							sikinn_scale[0] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[0];//�Y�o�𑝂₷
						sikin_syuunyuu += 10 * sikinn_scale[0];//�Y�o�̎������𑝂₷

					}
					break;

				case 1:
					if (field_type[1] == 1)//�_��ł����
					{
						sakumotu_scale[1] = 1.0f;

						if (field_type[0] == 1)
						{
							sakumotu_scale[1] += all_basic_scale;
						}
						if (field_type[2] == 1)
						{
							sakumotu_scale[1] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[1];//�앨�𑝂₷
						sakumotu_syuunyuu += 5 * sakumotu_scale[1];//�앨�̎������𑝂₷
					}
					if (field_type[1] == 2)//�Y��ł����
					{
						sannsyutu_scale[1] = 1.0f;

						if (field_type[0] == 2)
						{
							sannsyutu_scale[1] += all_basic_scale;
						}
						if (field_type[2] == 2)
						{
							sannsyutu_scale[1] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[1];//�Y�o�𑝂₷
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[1];//�Y�o�̎������𑝂₷
					}
					if (field_type[1] == 3)//����ł����
					{
						sikinn_scale[1] = 1.0f;

						if (field_type[0] == 3)
						{
							sikinn_scale[1] += all_basic_scale;
						}
						if (field_type[2] == 3)
						{
							sikinn_scale[1] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[1];//�Y�o�𑝂₷
						sikin_syuunyuu += 10 * sikinn_scale[1];//�Y�o�̎������𑝂₷
					}
					break;

				case 2:
					if (field_type[2] == 1)//�_��ł����
					{
						sakumotu_scale[2] = 1.0f;

						if (field_type[1] == 1)
						{
							sakumotu_scale[2] += all_basic_scale;
						}
						if (field_type[5] == 1)
						{
							sakumotu_scale[2] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[2];//�앨�𑝂₷
						sakumotu_syuunyuu += 5 * sakumotu_scale[2];//�앨�̎������𑝂₷
					}
					if (field_type[2] == 2)//�Y��ł����
					{
						sannsyutu_scale[2] = 1.0f;

						if (field_type[1] == 2)
						{
							sannsyutu_scale[2] += all_basic_scale;
						}
						if (field_type[5] == 2)
						{
							sannsyutu_scale[2] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[2];//�Y�o�𑝂₷
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[2];//�Y�o�̎������𑝂₷
					}
					if (field_type[2] == 3)//����ł����
					{
						sikinn_scale[2] = 1.0f;

						if (field_type[1] == 3)
						{
							sikinn_scale[2] += all_basic_scale;
						}
						if (field_type[5] == 3)
						{
							sikinn_scale[2] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[2];//�Y�o�𑝂₷
						sikin_syuunyuu += 10 * sikinn_scale[2];//�Y�o�̎������𑝂₷
					}

				case 3:
					if (field_type[3] == 1)//�_��ł����
					{
						sakumotu_scale[3] = 1.0f;

						if (field_type[0] == 1)
						{
							sakumotu_scale[3] += all_basic_scale;
						}
						if (field_type[6] == 1)
						{
							sakumotu_scale[3] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[3];//�앨�𑝂₷
						sakumotu_syuunyuu += 5 * sakumotu_scale[3];//�앨�̎������𑝂₷
					}
					if (field_type[3] == 2)//�Y��ł����
					{
						sannsyutu_scale[3] = 1.0f;

						if (field_type[0] == 2)
						{
							sannsyutu_scale[3] += all_basic_scale;
						}
						if (field_type[6] == 2)
						{
							sannsyutu_scale[3] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[3];//�Y�o�𑝂₷
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[3];//�Y�o�̎������𑝂₷
					}
					if (field_type[3] == 3)//����ł����
					{
						sikinn_scale[3] = 1.0f;

						if (field_type[0] == 3)
						{
							sikinn_scale[3] += all_basic_scale;
						}
						if (field_type[6] == 3)
						{
							sikinn_scale[3] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[3];//�Y�o�𑝂₷
						sikin_syuunyuu += 10 * sikinn_scale[3];//�Y�o�̎������𑝂₷
					}
					break;

				case 5:
					if (field_type[5] == 1)//�_��ł����
					{
						sakumotu_scale[5] = 1.0f;

						if (field_type[2] == 1)
						{
							sakumotu_scale[5] += all_basic_scale;
						}
						if (field_type[8] == 1)
						{
							sakumotu_scale[5] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[5];//�앨�𑝂₷
						sakumotu_syuunyuu += 5 * sakumotu_scale[5];//�앨�̎������𑝂₷
					}
					if (field_type[5] == 2)//�Y��ł����
					{
						sannsyutu_scale[5] = 1.0f;

						if (field_type[2] == 2)
						{
							sannsyutu_scale[5] += all_basic_scale;
						}
						if (field_type[8] == 2)
						{
							sannsyutu_scale[5] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[5];//�Y�o�𑝂₷
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[5];//�Y�o�̎������𑝂₷
					}
					if (field_type[5] == 3)//����ł����
					{
						sikinn_scale[5] = 1.0f;

						if (field_type[2] == 3)
						{
							sikinn_scale[5] += all_basic_scale;
						}
						if (field_type[8] == 3)
						{
							sikinn_scale[5] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[5];//�Y�o�𑝂₷
						sikin_syuunyuu += 10 * sikinn_scale[5];//�Y�o�̎������𑝂₷
					}
					break;

				case 6:
					if (field_type[6] == 1)//�_��ł����
					{
						sakumotu_scale[6] = 1.0f;

						if (field_type[3] == 1)
						{
							sakumotu_scale[6] += all_basic_scale;
						}
						if (field_type[7] == 1)
						{
							sakumotu_scale[6] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[6];//�앨�𑝂₷
						sakumotu_syuunyuu += 5 * sakumotu_scale[6];//�앨�̎������𑝂₷
					}
					if (field_type[6] == 2)//�Y��ł����
					{
						sannsyutu_scale[6] = 1.0f;

						if (field_type[3] == 2)
						{
							sannsyutu_scale[6] += all_basic_scale;
						}
						if (field_type[7] == 2)
						{
							sannsyutu_scale[6] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[6];//�Y�o�𑝂₷
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[6];//�Y�o�̎������𑝂₷
					}
					if (field_type[6] == 3)//����ł����
					{
						sikinn_scale[6] = 1.0f;

						if (field_type[3] == 3)
						{
							sikinn_scale[6] += all_basic_scale;
						}
						if (field_type[7] == 3)
						{
							sikinn_scale[6] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[6];//�Y�o�𑝂₷
						sikin_syuunyuu += 10 * sikinn_scale[6];//�Y�o�̎������𑝂₷
					}
					break;

				case 7:
					if (field_type[7] == 1)//�_��ł����
					{
						sakumotu_scale[7] = 1.0f;

						if (field_type[6] == 1)
						{
							sakumotu_scale[7] += all_basic_scale;
						}
						if (field_type[8] == 1)
						{
							sakumotu_scale[7] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[7];//�앨�𑝂₷
						sakumotu_syuunyuu += 5 * sakumotu_scale[7];//�앨�̎������𑝂₷
					}
					if (field_type[7] == 2)//�Y��ł����
					{
						sannsyutu_scale[7] = 1.0f;

						if (field_type[6] == 2)
						{
							sannsyutu_scale[7] += all_basic_scale;
						}
						if (field_type[8] == 2)
						{
							sannsyutu_scale[7] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[7];//�Y�o�𑝂₷
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[7];//�Y�o�̎������𑝂₷
					}
					if (field_type[7] == 3)//����ł����
					{
						sikinn_scale[7] = 1.0f;

						if (field_type[6] == 3)
						{
							sikinn_scale[7] += all_basic_scale;
						}
						if (field_type[8] == 3)
						{
							sikinn_scale[7] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[7];//�Y�o�𑝂₷
						sikin_syuunyuu += 10 * sikinn_scale[7];//�Y�o�̎������𑝂₷
					}
					break;

				case 8:
					if (field_type[8] == 1)//�_��ł����
					{
						sakumotu_scale[8] = 1.0f;

						if (field_type[5] == 1)
						{
							sakumotu_scale[8] += all_basic_scale;
						}
						if (field_type[7] == 1)
						{
							sakumotu_scale[8] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[8];//�앨�𑝂₷
						sakumotu_syuunyuu += 5 * sakumotu_scale[8];//�앨�̎������𑝂₷
					}
					if (field_type[8] == 2)//�Y��ł����
					{
						sannsyutu_scale[8] = 1.0f;

						if (field_type[5] == 2)
						{
							sannsyutu_scale[8] += all_basic_scale;
						}
						if (field_type[7] == 2)
						{
							sannsyutu_scale[8] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[8];//�Y�o�𑝂₷
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[8];//�Y�o�̎������𑝂₷
					}
					if (field_type[8] == 3)//����ł����
					{
						sikinn_scale[8] = 1.0f;

						if (field_type[5] == 3)
						{
							sikinn_scale[8] += all_basic_scale;
						}
						if (field_type[7] == 3)
						{
							sikinn_scale[8] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[8];//�Y�o�𑝂₷
						sikin_syuunyuu += 10 * sikinn_scale[8];//�Y�o�̎������𑝂₷
					}
					break;

				default:
					break;
				}
			}

			if (kaitaku_time[count] <= 0)//�J�񎞊Ԃ�0�ɂȂ�����
			{
				field_type[count] = kaitaku_type[count];//���^�C�v��ύX
				kaitaku_time[count] = 0;//�J�񎞊Ԃ̏�����
			}
		}

		//�����i�񂾂�(for���㏈��)
		if (day_flag == true)
		{
			//�l���̏���
			if ((sakumotu - (jinkou * 0.5)) >= jinkou)//�앨�ۗ̕L�ʂ��l����5��������������葽�����
			{
				sakumotu -= jinkou * 0.5;//�l����5�����̍앨������
				jinkou += sakumotu * 0.05;//�앨��0.5�����̐l���𑝂₷

				jinkou_zouka = sakumotu * 0.05;//�l�������ʂ̏�����
				sakumotu_syouhi = -jinkou * 0.5;//�앨�̏���ʏ�����
			}
			else
			{
				sakumotu -= jinkou * 0.5;//�l����5�����̍앨������
				jinkou -= jinkou * 0.1;//�앨������Ȃ�������l����2�����炷�B

				jinkou_zouka = -jinkou * 0.1 - 1;//�l�������ʂ̏�����
				sakumotu_syouhi = -jinkou * 0.5;//�앨�̏���ʏ�����

			}
		}

		if (sakumotu <= 0)//�앨��0�ȉ��ɂȂ�����0�ɂ���B
		{
			sakumotu = 0;
		}


		day_flag = false;//�����i�񂾃t���O���I�t�ɂ���B
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

			//������ȊO��I�����Ă���Ƃ��̃R�}���h
			if (count != 4)
			{
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

						if ((sikinn - 200) >= 0)//��������200���炵�Ă�0�ɂȂ�Ȃ����
						{
							if ((sannsyutu - 2) >= 0)//�Y�o����2���炵�Ă�0�ɂȂ�Ȃ����
							{
								if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)//���s�{�^���̃A�b�v�f�[�g
								{
									kaitaku_time[count] = 7;//�J�񎞊Ԃ�90�ɐݒ�
									kaitaku_type[count] = 1;//�_��ɕύX
									sikinn -= 200;//���������炷�B
									sannsyutu -= 2;//�Y�o�����炷
								}
							}
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

						if ((sikinn - 300) >= 0)//��������300���炵�Ă�0�ɂȂ�Ȃ����
						{
							if ((sannsyutu - 4) >= 0)//�Y�o����4���炵�Ă�0�ɂȂ�Ȃ����
							{
								if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//���s�{�^���̃A�b�v�f�[�g
								{
									kaitaku_time[count] = 7;//�J�񎞊Ԃ�90�ɐݒ�
									kaitaku_type[count] = 2;//�Y��ɕύX
									sikinn -= 300;//���������炷�B
									sannsyutu -= 4;//�Y�o�����炷
								}
							}
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

						if ((sikinn - 500) >= 0)//��������500���炵�Ă�0�ɂȂ�Ȃ����
						{
							if ((sannsyutu - 3) >= 0)//�Y�o����3���炵�Ă�0�ɂȂ�Ȃ����
							{
								if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//���s�{�^���̃A�b�v�f�[�g
								{
									kaitaku_time[count] = 7;//�J�񎞊Ԃ�90�ɐݒ�
									kaitaku_type[count] = 3;//����ɕύX
									sikinn -= 500;//���������炷�B
									sannsyutu -= 3;//�Y�o�����炷
								}
							}
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

						if ((sikinn - 100) >= 0)//��������100���炵�Ă�0�ɂȂ�Ȃ����
						{
							if ((sannsyutu - 2) >= 0)//�Y�o����2���炵�Ă�0�ɂȂ�Ȃ����
							{
								if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//���s�{�^���̃A�b�v�f�[�g
								{
									kaitaku_time[count] = 7;//�J�񎞊Ԃ�90�ɐݒ�
									kaitaku_type[count] = 0;//�X�n�ɕύX
									sikinn -= 100;//���������炷�B
									sannsyutu -= 2;//�Y�o�����炷
								}
							}
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
			else//�R�}���h�{�^���̍폜�����������B
			{
				kaitaku.SwitchButton_Flag_Change(false);//�J��{�^����FALSE��
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
		//�R�}���h�̕\��
		if (field[count].GetSwitchButton_Flag() == true)
		{
			//������ȊO�̋���I�������Ƃ�
			if (count != 4)
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
		}

		//���̕`��
		field[count].SwitchButtonBOX_Draw(field_type[count]);	
		
		//�J�񒆂̏��\��
		if (kaitaku_time[count] != 0)
		{
			//���̊J���Ԃɂ���ĕ\����ς���
			switch (count)
			{
			case 0: DrawFormatString(field_position.x - 128 + 60, field_position.y - 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[0]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 1: DrawFormatString(field_position.x + 60, field_position.y - 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[1]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 2: DrawFormatString(field_position.x + 128 + 60, field_position.y - 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[2]);
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 3: DrawFormatString(field_position.x - 128 + 60, field_position.y + 60, GetColor(0, 0, 0), "%d", kaitaku_time[3]);	
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 4: DrawFormatString(field_position.x, field_position.y, GetColor(0, 0, 0), "%d", kaitaku_time[4]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 5: DrawFormatString(field_position.x + 128 + 60, field_position.y + 60, GetColor(0, 0, 0), "%d", kaitaku_time[5]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 6: DrawFormatString(field_position.x - 128 + 60, field_position.y + 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[6]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 7: DrawFormatString(field_position.x + 60, field_position.y + 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[7]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 8: DrawFormatString(field_position.x + 128 + 60, field_position.y + 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[8]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			default:
				break;
			}
		}

		//�����̕\��
		if ((sakumotu_scale[count] == 1.025f) || (sannsyutu_scale[count] == 1.025f) || (sikinn_scale[count] == 1.025f)) double_1_025[count].image.Draw();
		if ((sakumotu_scale[count] == 1.05f) || (sannsyutu_scale[count] == 1.05f) || (sikinn_scale[count] == 1.05f)) double_1_05[count].image.Draw();
	}

	//�X�e�[�^�X�̕`��
	status.image.Draw();//�X�e�[�^�X�摜�̕`��
	DrawFormatString(128, 20, GetColor(0, 0, 0), "%d", sikinn);//����
	DrawFormatString(128, 60, GetColor(0, 0, 0), "%d", sakumotu);//�앨
	DrawFormatString(128, 100, GetColor(0, 0, 0), "%d", sannsyutu);//���Y
	DrawFormatString(128 * 3 - 90, 100, GetColor(0, 0, 0), "%d", day);//��
	DrawFormatString(128 * 3 - 60, 20, GetColor(0, 0, 0), "%d", jinkou);//�l��

	//�X�e�[�^�X�����̕`��
	status_down.image.Draw();
	DrawFormatString(100, 698, GetColor(0, 0, 0), "%d", sannsyutu_syuunyuu);//�Y�o����
	DrawFormatString(128 * 2 - 28, 698, GetColor(0, 0, 0), "%d", sikin_syuunyuu);//��������
	DrawFormatString(128 * 3 - 24, 698, GetColor(0, 0, 0), "%d", sakumotu_syuunyuu);//�앨����
	DrawFormatString(128 * 4 + 8, 698, GetColor(0, 0, 0), "%d", jinkou_zouka);//�l��������
	DrawFormatString(128 * 5 + 34, 698, GetColor(0, 0, 0), "%d", sakumotu_syouhi);//�앨�����

	if (nougyou.GetSwitchButton_HitFlag() == true) nouku_setumei.image.Draw();//�_��̐���
	if (sangyou.GetSwitchButton_HitFlag() == true) sanku_setumei.image.Draw();//�Y��̐���
	if (syougyou.GetSwitchButton_HitFlag() == true) syouku_setumei.image.Draw();//����̐���
	if (kaitaku.GetSwitchButton_HitFlag() == true) kaitaku_setumei.image.Draw();//�J��R�}���h�̐���
	if (sarati.GetSwitchButton_HitFlag() == true) sarati_setumei.image.Draw();//�X�n�̐���
	if (play.GetOneClickButton_HitFlag() == true) play_setumei.image.Draw();//�v���C�{�^���̐���

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}