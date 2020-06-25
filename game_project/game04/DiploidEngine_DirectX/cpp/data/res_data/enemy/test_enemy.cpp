#include "data/res_data/enemy/test_enemy.h"

void _TestEnemy::SetEnemyData(EnemyData new_data)
{
	data = new_data;

	circle.SetLife(data.hit_point);
}

void _TestEnemy::LoadGraphics()
{
	counter_icon_image.Load("texter/res/effect/exclamation/0.png");

	move_image[0].Load("texter/res/enemy/enemy_00/0.png");
	move_image[1].Load("texter/res/enemy/enemy_00/1.png");
	move_image[2].Load("texter/res/enemy/enemy_00/2.png");
	move_image[3].Load("texter/res/enemy/enemy_00/3.png");
}

void _TestEnemy::LoadHandles(int handle)
{	

}

void _TestEnemy::Init()
{
	circle.Init(data.pos, data.size, GetColor(255, 0, 0), true);
	counter_icon_image.Init(VGet(data.pos.x, data.pos.y - (data.size + 10.0f), data.pos.z),false);
	counter_icon_image.SetScale(1.0f, 1.0f);

	//�A�j��	
	for (int count = 0; count <= anime_frame_volume; ++count)
	{
		move_image[count].Init(circle.GetPosition(), false);
	}
	

	//�ړ�����1
	move_data.move_time = 100.0f;
	move_data.speed = data.move_speed;
	move_data.wait_time = 30;
	move_pattern.PushBack(move_data);

	//�ړ�����2
	move_data.move_time = 80.0f;
	move_data.speed = data.move_speed * 2.0f;
	move_data.wait_time = 10;
	move_pattern.PushBack(move_data);

	//�ړ�����3
	move_data.move_time = 60.0f;
	move_data.speed = data.move_speed * 0.5f;
	move_data.wait_time = 60;
	move_pattern.PushBack(move_data);
}

void _TestEnemy::Updata()
{
	//Player�̍U�����̓J�E���^�[(�h��)������������
	if (circle.GetHitFlag() == true)
	{
		//�m�b�N�o�b�N����
		if (circle.GetPosition().x < 1280 / 2)
		{
			circle.SetMoveSpeed(VGet(-data.move_speed * data.knock_back_scale, 0, 0));

			if (!attack_list.empty())
			{
				attack_list.clear();
			}
		}
		else if (circle.GetPosition().x > 1280 / 2)
		{
			circle.SetMoveSpeed(VGet(data.move_speed * data.knock_back_scale, 0, 0));

			if (!attack_list.empty())
			{
				attack_list.clear();
			}
		}

		//�J�E���^�[�łȂ����
		if (counter_flag == false)
		{
			circle.SubLife(1.0f);//HP�����炷
		}		

		counter_time_buffer = 0.0f;//�J�E���^�[�o�b�t�@��������
		data_buffer.attack_speed = 0.0f;//�U���o�b�t�@��������
		counter_flag = false;//�J�E���^�[�t���O��false��
		circle.SetHitFlag(false);//�q�b�g�t���O��false��
	}
	else
	{			
		if (circle.GetPosition().x <= 1280 / 2 - 50)
		{
			circle.SetMoveSpeed(VGet(move_pattern.Move(), 0, 0));
			data.direction = 0;
			counter_flag = false;
		}
		else if (circle.GetPosition().x >= 1280 / 2 + 50)
		{
			circle.SetMoveSpeed(VGet(-move_pattern.Move(), 0, 0));		
			data.direction = 1;
			counter_flag = false;
		}
		else
		{
			circle.SetMoveSpeed(VGet(0, 0, 0));

			counter_flag = false;

			//�U�����x���o�b�t�@�Ɣ�r
			if (data.attack_speed <= data_buffer.attack_speed)
			{
				//�J�E���^�[��t���ԂƔ�r
				if (data.counter_time >= counter_time_buffer)
				{
					counter_flag = true;
					counter_time_buffer += 1;
				}
				else
				{		
					//�U������̒ǉ�
					attack.Init(circle.GetPosition(), data);
					attack_list.push_back(attack);

					data_buffer.attack_speed = 0.0f;
				}
			}
			else
			{
				if (!attack_list.empty())
				{
					attack_list.clear();
				}

				++data_buffer.attack_speed;
				counter_time_buffer = 0.0f;
			}
		}
	}

	circle.MoveUpdate();
	counter_icon_image.SetPosition(VGet(circle.GetPosition().x - 16, circle.GetPosition().y - (data.size + 40), circle.GetPosition().z));//�J�E���^�[�\�A�C�R���̈ړ�

	if (circle.GetLife() <= 0)
	{
		if (counter_flag == false)
		{
			move_pattern.Destory();
			circle.SetDestoryFlag(true);
		}
	}

	//�A�j��	
	++anime_time;
	for (int count = 0; count <= anime_frame_volume; ++count)
	{
		if (data.direction == 1)
		{
			move_image[count].SetTurnFlag(true);
			move_image[count].SetPosition(VGet(circle.GetPosition().x - (10 * (data.size * 0.1f)), circle.GetPosition().y - (20 * (data.size * 0.1f)), circle.GetPosition().z));
		}
		else
		{
			move_image[count].SetTurnFlag(false);
			move_image[count].SetPosition(VGet(circle.GetPosition().x - (20 * (data.size * 0.1f)), circle.GetPosition().y - (20 * (data.size * 0.1f)), circle.GetPosition().z));
		}
		move_image[count].SetScale(data.size * 0.1f, data.size * 0.1f);
	}
}

void _TestEnemy::Draw(bool draw)
{
	//circle.Draw(draw);

	for (auto itr = attack_list.begin(); itr != attack_list.end(); ++itr)
	{
		itr->Draw(draw);
	}

	//�A�j��	
	move_image[anime_count].Draw(draw);

	if (anime_time >= play_time)
	{
		if (anime_count >= anime_frame_volume - 1)
		{
			anime_count = 0;
			anime_time = 0;
		}
		else
		{
			++anime_count;
			anime_time = 0;
		}
	}
	

	if (counter_flag == true)
	{
		counter_icon_image.Draw(draw);//�т�����}�[�N�̕\��
		//DrawStringF(circle.GetPosition().x, circle.GetPosition().y - 20, "!", GetColor(255, 255, 255));
	}
}


void _TestEnemy::SetMoveSpeed(float new_speed)
{
	data.move_speed = new_speed;
}

void _TestEnemy::isSetDestoryFlag(bool new_flag)
{
	destory_flag = new_flag;
}


EnemyData* _TestEnemy::GetDataPtr()
{
	return& data;
}

bool _TestEnemy::GetCounterFlag()
{
	return counter_flag;
}


DiploidCircleV2* _TestEnemy::GetCirclePtr()
{
	return& circle;
}

std::list<EnemyAttack>* _TestEnemy::GetAttackListPtr()
{
	return& attack_list;

}