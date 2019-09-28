#include "data/game_data/EXPLORE/explore_test_map.h"

void Explore_TestMap::Load()
{
	//�}�b�v�̓ǂݍ���
	_MapLoad();

	//�v���[���[�̓ǂݍ���
	player_direction.Load();
}

void Explore_TestMap::Init(VECTOR position)
{		
	//�}�b�v�̏�����
	_MapInit(position);

	//�v���[���[�̏�����
	player_direction.Init(player_size);
}

void Explore_TestMap::Push(DiploidEngineImpact& impact)
{	
	//�}�b�v�̃v�b�V��
	_MapPush(&impact);

	//�v���[���[�̃v�b�V��
	player_direction.Push(impact);
}

void Explore_TestMap::Updata(DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	//�}�b�v�̃A�b�v�f�[�g
	_MapUpdate(&impact, &input);

	//�v���[���[�̃A�b�v�f�[�g
	player_direction.Updata(impact, input);
}

void Explore_TestMap::Draw(bool draw)
{
	//�}�b�v�̕`��
	_MapDraw(draw);

	//�v���[���[�̕`��
	player_direction.Draw(draw);
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
	test_map_texter.image.Init(VGet((1280 / 2), (720 / 2), 0), 40.0f);
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

void Explore_TestMap::_MapUpdate(DiploidEngineImpact* impact, DiploidEngineInput* input)
{	
	//�w�i�摜�̃A�b�v�f�[�g
	test_map_texter.image.Updata();

	//���֍s��
	if (input->GetKey(KEY_INPUT_A) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_left") == false)//�����������Ă��Ȃ����
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", movement_speed);//�ړ�	
				test_map_texter.image.move_speed.x = movement_speed;
			}
		}
	}

	//�E�֍s��
	if (input->GetKey(KEY_INPUT_D) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_right") == false)//�E���������Ă��Ȃ����
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", -movement_speed);//�ړ�
				test_map_texter.image.move_speed.x = -movement_speed;
			}
		}
	}

	//��֍s��
	if (input->GetKey(KEY_INPUT_W) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_up") == false)//�オ�������Ă��Ȃ����
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", movement_speed);//�ړ�
				test_map_texter.image.move_speed.y = movement_speed;
			}
		}
	}

	//���֍s��
	if (input->GetKey(KEY_INPUT_S) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_down") == false)//�����������Ă��Ȃ����
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", -movement_speed);//�ړ�
				test_map_texter.image.move_speed.y = -movement_speed;
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