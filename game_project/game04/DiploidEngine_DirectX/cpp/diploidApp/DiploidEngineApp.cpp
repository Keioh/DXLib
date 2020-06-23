#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	//HP��UI�摜��ǂݍ���
	hp_ui.LoadGraphics();
	hp_ui.LoadGraphicsHandle();

	ground_line.LoadGraphics();
	forest.Load("texter/res/stage/forest.png");
	
	
	test.Load("texter/res/dp/0.png");
	anime.LoadHandles(test.GetGraphicsHandl());

	test.Load("texter/res/dp/1.png");
	anime.LoadHandles(test.GetGraphicsHandl());

	test.Load("texter/res/dp/2.png");
	anime.LoadHandles(test.GetGraphicsHandl());

	test.Load("texter/res/dp/3.png");
	anime.LoadHandles(test.GetGraphicsHandl());

	test.Load("texter/res/dp/4.png");
	anime.LoadHandles(test.GetGraphicsHandl());

	test.Load("texter/res/dp/5.png");
	anime.LoadHandles(test.GetGraphicsHandl());

	test.Load("texter/res/dp/6.png");
	anime.LoadHandles(test.GetGraphicsHandl());
	
	test.Load("texter/res/dp/7.png");
	anime.LoadHandles(test.GetGraphicsHandl());

	test.Load("texter/res/dp/8.png");
	anime.LoadHandles(test.GetGraphicsHandl());


	player.LoadGraphics();
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{		
	anime.Init(VGet(200, 200, 0), 4.0f, 2.0f);

	//�O�����h���C���̏�����
	ground_line.Init(550.0f);

	//�v���C���[�̏�����
	player.Init(VGet(1280/2, ground_line.GetGroundLine() - player.GetPlayerSize(), 0));

	hp_ui.Init(VGet(24, 24, 0), 1.5f);

	for (int n = 0; n <= 5; ++n)
	{	
		
		enemy_data.pos = VGet(GetRand(1280), ground_line.GetGroundLine() - 20, 0);
		enemy_data.size = 20.0f;
		enemy_data.move_speed = 1.0f;
		enemy_data.hit_point = 3;
		enemy_data.attack_speed = 80.0f;
		enemy_data.attack_size = enemy_data.size * 1.5f;
		enemy_data.counter_time = 20.0f;
		enemy_data.knock_back_scale = 50.0f;

		test_enemy.LoadGraphics();
		test_enemy.SetEnemyData(enemy_data);
		test_enemy.Init();

		enemy_manager.PushBackEnemy(test_enemy);
	}

	forest.Init(VGet(0, 0, 0), false);
	forest.SetScale(1.5f, 1.5f);
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	input.Update();

	player.Updata();

	hp_ui.Updata(player);

	enemy_manager.Updata();

	enemy_manager.DestoryEnemy();


	if (!enemy_manager.GetPtr()->empty())
	{
		if (!player.GetAttackListPtr()->empty())
		{
			//�G��list�̃C�e���[�^���擾���A��
			for (auto enemy_manager_itr = enemy_manager.GetPtr()->begin(); enemy_manager_itr != enemy_manager.GetPtr()->end(); ++enemy_manager_itr)
			{
				//�v���C���[�̍U��list�̃C�e���[�^���擾���A�񂷁B
				for (auto palyer_attack_itr = player.GetAttackListPtr()->begin(); palyer_attack_itr != player.GetAttackListPtr()->end(); ++palyer_attack_itr)
				{
					//�v���C���[�̍U���ƓG�{�̂Ƃ̓����蔻��
					collision.CircleAndCircleCollisionUpdate(palyer_attack_itr->GetAttackCircleObjectPtr(), enemy_manager_itr->GetCirclePtr());
				}
			}
		}

		if (!player.GetDefenseListPtr()->empty())
		{
			//�G��list�̃C�e���[�^���擾���A��
			for (auto enemy_manager_itr = enemy_manager.GetPtr()->begin(); enemy_manager_itr != enemy_manager.GetPtr()->end(); ++enemy_manager_itr)
			{
				//�J�E���^�[�t���O��true�Ȃ�
				if (enemy_manager_itr->GetCounterFlag() == true)
				{
					//�v���C���[�̍U��list�̃C�e���[�^���擾���A�񂷁B
					for (auto palyer_defense_itr = player.GetDefenseListPtr()->begin(); palyer_defense_itr != player.GetDefenseListPtr()->end(); ++palyer_defense_itr)
					{
						//�v���C���[�̍U���ƓG�{�̂Ƃ̓����蔻��
						collision.CircleAndCircleCollisionUpdate(palyer_defense_itr->GetDefenseCircleObjectPtr(), enemy_manager_itr->GetCirclePtr());
					}
				}
			}
		}

		//�G��list�̃C�e���[�^���擾���A��
		for (auto enemy_manager_itr = enemy_manager.GetPtr()->begin(); enemy_manager_itr != enemy_manager.GetPtr()->end(); ++enemy_manager_itr)
		{
			if (!enemy_manager_itr->GetAttackListPtr()->empty())
			{
				//�G�̍U��list�̃C�e���[�^���擾���A�񂷁B
				for (auto enemy_attack_itr = enemy_manager_itr->GetAttackListPtr()->begin(); enemy_attack_itr != enemy_manager_itr->GetAttackListPtr()->end(); ++enemy_attack_itr)
				{
					//�v���C���[�{�̂ƓG�̍U���Ƃ̓����蔻��
					collision.CircleAndCircleCollisionUpdate(player.PlayerCirclePtr(), enemy_attack_itr->GetCirclePtr());
				}
			}
		}
	}	
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	forest.Draw();

	player.Draw();

	ground_line.Draw();

	enemy_manager.Draw();

	hp_ui.Draw();

	anime.Draw();
}

void DiploidEngineApp::Destory()//���[�v���ɍ폜�������I�u�W�F�N�g(ver1.0)������ꍇ�͂����ō폜�����������B
{

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}