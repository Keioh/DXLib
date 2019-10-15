#include "data/game_data/EXPLORE/explore_test_map.h"

void Explore_TestMap::Load()
{
	//�}�b�v�̓ǂݍ���
	_MapLoad();

	//�v���[���[�̓ǂݍ���
	player_direction.Load();

	//���E��̓ǂݍ���
	player_visibility.image.Load("texter/game/character/shikai.png");


	//�퓬��ʂ̔w�i�摜�̓ǂݍ���
	combat_back_texter.image.Load("texter/game/battle/back.png");

	//�퓬�R�}���h�摜�̓ǂݍ���
	battle_command.SwitchButtonBOX_Load("texter/game/battle/battle.png", 60, 30);

}

void Explore_TestMap::Init(VECTOR position)
{		
	//�}�b�v�̏�����
	_MapInit(position);

	//�v���[���[�̏�����
	player_direction.Init(player_size);

	//���E��̏�����
	player_visibility.image.Init(VGet(1280 / 2, 720 / 2, 0));

	//�G�̏�����
	enemy_position = VGet(100, 0, 0);
	enemy_test.box.Init(VGet(1280 / 2 + enemy_position.x, 720 / 2 + enemy_position.y, 0), VGet(50,50,0));
	enemy_test.box.name_tag = "test_enemy";
	enemy_test.box.layer_number = DIPLOID_LAYER_02;

	//�퓬��ʂ̔w�i�摜�̏�����
	combat_back_texter.image.Init(VGet(1280/2, 720/2, 0));

	//�퓬�R�}���h�̏�����
	battle_command.SwitchButtonBOX_Init(VGet(100, 300, 0), VGet(60, 30, 0), "battle_command", DIPLOID_LAYER_03);
}

void Explore_TestMap::Push(DiploidEngineImpact& impact)
{	
	//�}�b�v�̃v�b�V��
	_MapPush(&impact);

	//�v���[���[�̃v�b�V��
	player_direction.Push(impact);

	//�G�̃v�b�V��
	impact.PushBox(enemy_test.box);

}

void Explore_TestMap::Updata(DiploidEngineImpact& impact, DiploidEngineInput& input, CommandUI& command_ui, StatusBar& status_bar, Clock& clock)
{	
	//�G���v���C���[�Ɠ������Ă�����
	if (impact.GetBoxImpactFlag_Sreach_Name_Tag("test_enemy") == true)
	{
		enemy_hit = true;
	}

	//�G�Ɠ������Ă��Ȃ��Ƃ�
	if (enemy_hit == false)
	{

		system.OneDeletePOINT_Impact(impact, "battle_command_point");//�퓬��ʂ̃}�E�X�|�C���g�ƍ폜
		system.OneDeleteBOX_Impact(impact, "battle_command");//�퓬�R�}���h�̍폜
		system.FlagReset_OnePushPOINT();//�ǂݍ��݃t���O��false��

		//�}�b�v�̃A�b�v�f�[�g
		_MapUpdate(&impact, &input, &command_ui, &status_bar, &clock);

		//�v���[���[�̃A�b�v�f�[�g
		player_direction.Updata(impact, input);
	}
	else if(enemy_hit == true)//�G�Ƃ̐퓬
	{

		system.FlagReset_OneDeletePOINT();//�폜�t���O��false��

		//�}�E�X�J�[�\��(�퓬���UI���)
		mouse_point.point.Init(VGet(0, 0, 0));
		mouse_point.point.mouse_point_move_flag = true;
		mouse_point.point.layer_number = DIPLOID_LAYER_03;
		mouse_point.point.name_tag = "battle_command_point";
		system.OnePushPOINT_Impact(impact, mouse_point.point);//�퓬��ʂ̃}�E�X�|�C���g��ǉ�
		system.OnePushBOX_Impact(impact, battle_command.box);//�퓬�R�}���h��ǉ��B


		battle_command.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, impact, input);//�퓬�R�}���h�̍X�V


		if (input.GetPressKey(KEY_INPUT_L) == true)
		{
			impact.DestoryBox_Name_Tag("test_enemy");

			enemy_hit = false;
		}
	}
}

void Explore_TestMap::Draw(bool draw)
{
	if (enemy_hit == false)
	{
		//�}�b�v�̕`��
		_MapDraw(draw);

		//�v���[���[�̕`��
		player_direction.Draw(draw);

		//���E��̕`��
		player_visibility.image.Draw(draw);
	}
	else
	{
		//�퓬��ʂ̔w�i�摜�̕`��
		combat_back_texter.image.Draw();

		//�퓬�R�}���h�̕`��
		battle_command.SwitchButtonBOX_Draw(draw);
	}
}




//�}�b�v�֘A�̊֐�
void Explore_TestMap::_MapLoad()
{
	//�}�b�v�֘A
	test_map.map.Load("texter/game/map/test_map.png", 12, 12);
	map_image_x = 12;
	map_image_y = 12;

	//�w�i�摜�̓ǂݍ���
	test_map_texter.image.Load("texter/game/map/test_map_texter.png");
}

void Explore_TestMap::_MapInit(VECTOR position)
{
	//�}�b�v�֘A
	map_chip_size = 400.0f;//�}�b�v�`�b�v�̑傫��

	player_size = map_chip_size * 0.2f;

	map_size = VGet((map_chip_size * map_image_x) / 2, (map_chip_size * map_image_y) / 2, 0);
	map_position = position;
	map_center_position_sub = VSub(map_position, map_size);//�}�b�v�T�C�Y����}�b�v�̔����̑傫�������߂�

	test_map.map.SetMapChipSize(map_chip_size);
	test_map.map.Create();

	//�w�i�摜�̏�����
	test_map_texter.image.Init(VGet((1280 / 2), (720 / 2), 0), 4.0f);
}

void Explore_TestMap::_MapPush(DiploidEngineImpact* impact)
{
	//�}�b�v�֘A
	for (auto count = test_map.map.MAP.begin(); count != test_map.map.MAP.end(); ++count)//map.MAP�z���size_t(auto)�Ŏ擾��MAP.end()�܂ŉ��L�̂��Ƃ��J��Ԃ�
	{
		if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))//���l��255�̎������̎�
		{
			test_map.box.Init(VGet((count->x * count->size) + map_center_position_sub.x, (count->y * count->size) + map_center_position_sub.y, 0), VGet(count->size, count->size, 0));
			test_map.box.layer_number = DIPLOID_LAYER_01;
			test_map.box.name_tag = "map_chip_wall_impact";
			impact->PushBox(test_map.box);

			map_number++;
		}
	}
}

void Explore_TestMap::_MapUpdate(DiploidEngineImpact* impact, DiploidEngineInput* input, CommandUI* command_ui, StatusBar* status_bar, Clock* clock)
{
	//�w�i�摜�̃A�b�v�f�[�g
	test_map_texter.image.Updata();

	//�����Ă���Ƃ��ƕ����Ă���Ƃ��̋�̏���
	if (movement_type == PLAYER_RUN)
	{
		if (clock->isSecondFlag() == true)
		{		
			command_ui->information_command.AddStaminaEXP(1);//���v�͂̌o���l��1�グ��

			status_bar->SubSP(1, command_ui->information_command);//�X�^�~�i�|�C���g(SP)���P���炷
		}

	}
	else if(movement_type == PLAYER_WALK)
	{
		if (command_ui->information_command.GetStaminaPoint() < command_ui->information_command.GetMaxStaminaPoint())//�X�^�~�i�|�C���g��0�łȂ����
		{
			if (clock->isSecondFlag() == true)
			{
				status_bar->AddSP(1, command_ui->information_command);//�X�^�~�i�|�C���g(SP)���P�񕜂���
			}
		}
	}

	//����
	if ((input->GetKey(KEY_INPUT_LSHIFT) == true) && (((input->GetKey(KEY_INPUT_A) == true) || ((input->GetKey(KEY_INPUT_D) == true)) || ((input->GetKey(KEY_INPUT_W) == true) || ((input->GetKey(KEY_INPUT_S) == true))))))
	{
		if (command_ui->information_command.GetStaminaPoint() != 0)//�X�^�~�i�|�C���g��0�łȂ����
		{
			movement_type = PLAYER_RUN;//�ړ���Ԃ��u����v�ɂ���

		}
		else
		{
			movement_type = PLAYER_WALK;//�ړ���Ԃ��u����v�ɂ���
		}
	}
	else
	{
		movement_type = PLAYER_WALK;//�ړ���Ԃ��u����v�ɂ���
	}	

	//���֍s��
	if (input->GetKey(KEY_INPUT_A) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_left") == false)//�����������Ă��Ȃ����
		{
			//����
			if (movement_type == PLAYER_WALK)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", movement_speed);//�ړ�	
					test_map_texter.image.move_speed.x = movement_speed;

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("test_enemy", movement_speed);//�ړ�	

				}
			}

			//����
			if (movement_type == PLAYER_RUN)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", movement_speed * movement_run_scale);//�ړ�	
					test_map_texter.image.move_speed.x = movement_speed * movement_run_scale;

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("test_enemy", movement_speed * movement_run_scale);//�ړ�	


				}
			}
		}
	}

	//�E�֍s��
	if (input->GetKey(KEY_INPUT_D) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_right") == false)//�E���������Ă��Ȃ����
		{
			//����
			if (movement_type == PLAYER_WALK)
			{
				for (int count = 0; count <= map_number; count++)
				{

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", -movement_speed);//�ړ�
					test_map_texter.image.move_speed.x = -movement_speed;

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("test_enemy", -movement_speed);//�ړ�	

				}
			}

			//����
			if (movement_type == PLAYER_RUN)
			{
				for (int count = 0; count <= map_number; count++)
				{

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", -movement_speed * movement_run_scale);//�ړ�
					test_map_texter.image.move_speed.x = -movement_speed * movement_run_scale;

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("test_enemy", -movement_speed * movement_run_scale);//�ړ�	

				}
			}
		}
	}

	//��֍s��
	if (input->GetKey(KEY_INPUT_W) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_up") == false)//�オ�������Ă��Ȃ����
		{
			//����
			if (movement_type == PLAYER_WALK)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", movement_speed);//�ړ�
					test_map_texter.image.move_speed.y = movement_speed;

					impact->SetBoxPositionAnimationY_Sreach_Object_Name("test_enemy", movement_speed);//�ړ�
				}
			}

			//����
			if (movement_type == PLAYER_RUN)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", movement_speed * movement_run_scale);//�ړ�
					test_map_texter.image.move_speed.y = movement_speed * movement_run_scale;

					impact->SetBoxPositionAnimationY_Sreach_Object_Name("test_enemy", movement_speed * movement_run_scale);//�ړ�

				}
			}
		}
	}

	//���֍s��
	if (input->GetKey(KEY_INPUT_S) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_down") == false)//�����������Ă��Ȃ����
		{
			//����
			if (movement_type == PLAYER_WALK)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", -movement_speed);//�ړ�
					test_map_texter.image.move_speed.y = -movement_speed;

					impact->SetBoxPositionAnimationY_Sreach_Object_Name("test_enemy", -movement_speed);//�ړ�
				}
			}

			//����
			if (movement_type == PLAYER_RUN)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", -movement_speed * movement_run_scale);//�ړ�
					test_map_texter.image.move_speed.y = -movement_speed * movement_run_scale;

					impact->SetBoxPositionAnimationY_Sreach_Object_Name("test_enemy", -movement_speed * movement_run_scale);//�ړ�
				}
			}
		}
	}
}

void Explore_TestMap::_MapDraw(bool draw)
{
	//�w�i�摜�̕`��
	if (draw == true)
	{
		test_map_texter.image.Draw();
	}
}


bool Explore_TestMap::GetEnemyHitFlag()
{
	return enemy_hit;
}