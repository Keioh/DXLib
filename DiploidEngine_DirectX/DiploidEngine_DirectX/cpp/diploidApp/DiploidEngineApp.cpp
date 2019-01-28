#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{
	
}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	object.map.Load("texter/MAP/test_map.png", 128, 128);//�}�b�v�摜�f�[�^��ǂݍ���(�Ō��x,y�͉摜�̑傫�����w��)
	object.image.Load("texter/test_map_chip/01_ground_rock_32_32.png");
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	object.map.SetMapChipSize(96);//map_data�摜��1�h�b�g���ǂꂾ���g�傷�邩�w��
	object.map.Create();//�摜�f�[�^����}�b�v�f�[�^���쐬

	object.box.Init(VGet(1280/2,720/2 + 90,0), VGet(50, 10,0));//point�O���t�B�b�N���}�E�X�ɒǏ]������
	object.box.layer_number = DIPLOID_ENGINE_MAP_HIT_OBJECT;
	object.box.number = OBJECT_NUMBER_PLAYER_DOWN;//��
	object.box.name_tag = "player_down";
	diploidEngineImpact.PushBox(object.box);//point�O���t�B�b�N��Impact�z��ɒǉ�

	object.box.Init(VGet(1280 / 2, 720 / 2 - 4, 0), VGet(50, 10, 0));//point�O���t�B�b�N���}�E�X�ɒǏ]������
	object.box.layer_number = DIPLOID_ENGINE_MAP_HIT_OBJECT;
	object.box.number = OBJECT_NUMBER_PLAYER_UP;//��
	object.box.name_tag = "player_up";
	diploidEngineImpact.PushBox(object.box);//point�O���t�B�b�N��Impact�z��ɒǉ�

	object.box.Init(VGet(1280 / 2 - 5, 720 / 2 + 6, 0), VGet(10, 84, 0));//point�O���t�B�b�N���}�E�X�ɒǏ]������
	object.box.layer_number = DIPLOID_ENGINE_MAP_HIT_OBJECT;
	object.box.number = OBJECT_NUMBER_PLAYER_LEFT;//��
	object.box.name_tag = "player_left";
	diploidEngineImpact.PushBox(object.box);//point�O���t�B�b�N��Impact�z��ɒǉ�

	object.box.Init(VGet(1280 / 2 + 45, 720 / 2+6, 0), VGet(10, 84, 0));//point�O���t�B�b�N���}�E�X�ɒǏ]������
	object.box.layer_number = DIPLOID_ENGINE_MAP_HIT_OBJECT;
	object.box.number = OBJECT_NUMBER_PLAYER_RIGHT;//�E
	object.box.name_tag = "player_right";
	diploidEngineImpact.PushBox(object.box);//point�O���t�B�b�N��Impact�z��ɒǉ�


	object.box.Init(VGet(1280 / 2 , 720 / 2, 0), VGet(50, 96, 0));//point�O���t�B�b�N���}�E�X�ɒǏ]������
	object.box.layer_number = DIPLOID_ENGINE_PLAYER_ENEMY_HIT_OBJECT;
	object.box.number = OBJECT_NUMBER_PLAYER_BODY;//�{��
	object.box.name_tag = "player_body";
	diploidEngineImpact.PushBox(object.box);//point�O���t�B�b�N��Impact�z��ɒǉ�


	for (auto count = object.map.MAP.begin(); count != object.map.MAP.end(); ++count)//map.MAP�z���size_t(auto)�Ŏ擾��MAP.end()�܂ŉ��L�̂��Ƃ��J��Ԃ�
	{
		if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))//���l��255�̎������̎�
		{
			int n = 0;
			n++;

			object.box.Init(VGet((count->x * count->size) - 200, (count->y * count->size) - 200, 0), VGet(count->size, count->size, 0));
			object.box.layer_number = DIPLOID_ENGINE_MAP_HIT_OBJECT;
			object.box.number = OBJECT_NUMBER_PLAYER_MAX + n;
			object.box.name_tag = "01_ground_rock";
			diploidEngineImpact.PushBox(object.box);

			object.image.Init(VGet((count->x * count->size + 32 * 1.5) - 200, (count->y * count->size + 32 * 1.5) - 200, 0), 3.0f);
			object.image.layer_number = DIPLOID_ENGINE_MAP_HIT_OBJECT;
			object.image.number = object.box.number;
			diploidEngineLayer.PushTopGraphics(object.image);
		}
	}
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	float gravity = object.physics.Gravity(0.4f, 12.0f);

	if (diploidEngineImpact.GetBoxImpactFlag(OBJECT_NUMBER_PLAYER_DOWN) == 0)//PLAYER�����Փ˂��Ă��Ȃ��Ƃ��̏���
	{

		for (int count = OBJECT_NUMBER_PLAYER_MAX; count != diploidEngineImpact.box_vector.size(); ++count)
		{
			diploidEngineImpact.SetBoxPositionAnimation(count, VGet(0, gravity, 0));
			diploidEngineLayer.SetTOPAnimationPosition(count, VGet(0, gravity, 0));
		}

		if ((diploidEngineInput.GetPressKey(KEY_INPUT_D) == 1) && (diploidEngineImpact.GetBoxImpactFlag(OBJECT_NUMBER_PLAYER_RIGHT) == 0))
		{
			for (int count = OBJECT_NUMBER_PLAYER_MAX; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(-4, gravity, 0));
				diploidEngineLayer.SetTOPAnimationPosition(count, VGet(-4, gravity, 0));
			}
		}

		if ((diploidEngineInput.GetPressKey(KEY_INPUT_A) == 1) && (diploidEngineImpact.GetBoxImpactFlag(OBJECT_NUMBER_PLAYER_LEFT) == 0))
		{
			for (int count = OBJECT_NUMBER_PLAYER_MAX; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(4, gravity, 0));
				diploidEngineLayer.SetTOPAnimationPosition(count, VGet(4, gravity, 0));
			}
		}
	}
	else//PLAYER�����Փ˂��Ă���Ƃ��̏���
	{
		object.physics.GravityReset();

		for (int count = OBJECT_NUMBER_PLAYER_MAX; count != diploidEngineImpact.box_vector.size(); ++count)
		{
			diploidEngineImpact.SetBoxPositionAnimation(count, VGet(0, 0, 0));
			diploidEngineLayer.SetTOPAnimationPosition(count, VGet(0, 0, 0));
		}

		if ((diploidEngineInput.GetPressKey(KEY_INPUT_D) == 1) && (diploidEngineImpact.GetBoxImpactFlag(OBJECT_NUMBER_PLAYER_RIGHT) == 0))
		{
			for (int count = OBJECT_NUMBER_PLAYER_MAX; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(-4, 0, 0));
				diploidEngineLayer.SetTOPAnimationPosition(count, VGet(-4, 0, 0));
			}
		}

		if ((diploidEngineInput.GetPressKey(KEY_INPUT_A) == 1) && (diploidEngineImpact.GetBoxImpactFlag(OBJECT_NUMBER_PLAYER_LEFT) == 0))
		{
			for (int count = OBJECT_NUMBER_PLAYER_MAX; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(4, 0, 0));
				diploidEngineLayer.SetTOPAnimationPosition(count, VGet(4, 0, 0));
			}
		}
	}
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}