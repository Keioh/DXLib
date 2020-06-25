#include "data/res_data/player/player.h"


void Player::LoadGraphics()
{
	//�U���A�j���[�V����
	attack_image.Load("texter/res/effect/sword/0.png");
	attack_anime.LoadHandles(attack_image.GetGraphicsHandl());

	attack_image.Load("texter/res/effect/sword/1.png");
	attack_anime.LoadHandles(attack_image.GetGraphicsHandl());

	attack_image.Load("texter/res/effect/sword/2.png");
	attack_anime.LoadHandles(attack_image.GetGraphicsHandl());

	attack_image.Load("texter/res/effect/sword/3.png");
	attack_anime.LoadHandles(attack_image.GetGraphicsHandl());

	attack_image.Load("texter/res/effect/sword/4.png");
	attack_anime.LoadHandles(attack_image.GetGraphicsHandl());

	attack_image.Load("texter/res/effect/sword/5.png");
	attack_anime.LoadHandles(attack_image.GetGraphicsHandl());

	//�h��A�j���[�V����
	defense_image.Load("texter/res/effect/defense/0.png");
	defense_anime.LoadHandles(defense_image.GetGraphicsHandl());

	defense_image.Load("texter/res/effect/defense/1.png");
	defense_anime.LoadHandles(defense_image.GetGraphicsHandl());

	defense_image.Load("texter/res/effect/defense/2.png");
	defense_anime.LoadHandles(defense_image.GetGraphicsHandl());

	defense_image.Load("texter/res/effect/defense/3.png");
	defense_anime.LoadHandles(defense_image.GetGraphicsHandl());

	defense_image.Load("texter/res/effect/defense/4.png");
	defense_anime.LoadHandles(defense_image.GetGraphicsHandl());

	defense_image.Load("texter/res/effect/defense/5.png");
	defense_anime.LoadHandles(defense_image.GetGraphicsHandl());

	defense_image.Load("texter/res/effect/defense/6.png");
	defense_anime.LoadHandles(defense_image.GetGraphicsHandl());

}

void Player::Init(VECTOR pos)
{
	player_pos = pos;

	player.SetLife(hit_point);

	player.Init(pos, player_size, GetColor(255, 255, 255), true);
}

void Player::Updata()
{
	input_left.Update();
	input_right.Update();

	//�U�����[�V����(�A�j���[�V����)��ture�Ȃ�(�U�����Ȃ�)
	if (is_attack == true)
	{
		//�A�j���[�V�������Ō�̃R�}�ł����
		if (attack_anime.isGetItr() == attack_anime.GetImageListPtr()->end())
		{
			is_attack = false;//�U�����ł͂Ȃ��B
		}
		else
		{
			if (attack_pos.x > 1280 / 2)//�������N���b�N�����Ƃ��̃A�j���[�V�����̏���
			{
				attack_anime.SetGraphicsTrun(true);
				attack_anime.Init(VGet(attack_pos.x - 48, attack_pos.y - 64, attack_pos.z), attack_speed, 1.5f);
			}
			else//�E��
			{
				attack_anime.SetGraphicsTrun(false);
				attack_anime.Init(VGet(attack_pos.x - 48, attack_pos.y - 64, attack_pos.z), attack_speed, 1.5f);
			}
		}
	}

	//�h�䃂�[�V����(�A�j���[�V����)��ture�Ȃ�(�h�䒆�Ȃ�)
	if (is_defense == true)
	{
		//�A�j���[�V�������Ō�̃R�}�ł����
		if (defense_anime.isGetItr() == defense_anime.GetImageListPtr()->end())
		{
			is_defense = false;//�h�䒆�ł͂Ȃ��B
		}
		else
		{
			defense_anime.Init(VGet(player_pos.x - 64, player_pos.y - 64, player_pos.z), defense_speed, 2.0f);
		}
	}

	//���N���b�N���������u��(�U��)
	if (input_left.GetPressMouse(MOUSE_INPUT_LEFT) == true)
	{
		//�U�����[�V�������I����Ă�����
		if (is_attack == false)
		{
			//�}�E�X���W��Player���W����N���b�N���Ă���p�x���v�Z
			attack_rote = std::atan2f(input_left.GetMousePosition().y - player_pos.y, input_left.GetMousePosition().x - player_pos.x);

			//�ɍ��W�̌v�Z
			attack_pos.x = (attack_range * std::cosf(attack_rote)) + player_pos.x;
			attack_pos.y = (attack_range * std::sinf(attack_rote)) + player_pos.y;

			//�U����list�ɒǉ�
			attack.Init(attack_pos);
			attack.SetAttackSize(attack_size);
			attack_list.push_back(attack);

			is_attack = true;
		}
	}
	else
	{
		if(!attack_list.empty())
		{
			//�U����list����폜
			attack_list.clear();
		}
	}
	

	//�E�N���b�N�������Ă����(�h��)
	if (input_right.GetPressMouse(MOUSE_INPUT_RIGHT) == true)
	{
		if ((is_defense == false) && (defense_point != 0))
		{
			defense_point -= 1.0f;//�h��|�C���g��1���炷�B

			defense.Init(player_pos);
			defense.SetDefenseSize(defense_size);
			defense_list.push_back(defense);

			is_defense = true;
		}
	}
	else
	{
		if (!defense_list.empty())
		{
			//�h���list����폜
			defense_list.clear();
		}
	}

	//�G�̍U�����������Ă�����
	if (player.GetHitFlag() == true)
	{
		player.SubLife(1.0f);//HP�����炷�B
	}

	player.SetHitFlag(false);
}

void Player::Draw(bool debug, bool draw)
{
	player.Draw(draw);

	if (!attack_list.empty())
	{
		for (auto itr = attack_list.begin(); itr != attack_list.end(); ++itr)
		{
			//�U����`��
			//itr->Draw(draw);
		}
	}

	if (!defense_list.empty())
	{
		for (auto itr = defense_list.begin(); itr != defense_list.end(); ++itr)
		{
			//�h���`��
			//itr->Draw(draw);
		}
	}

	if (is_attack == true)
	{
		attack_anime.Draw();
	}

	if (is_defense == true)
	{
		defense_anime.Draw();
	}

	//DrawFormatString(0, 20, GetColor(255, 255, 255), "HP = %.0f", player.GetLife());
	//DrawFormatString(0, 40, GetColor(255, 255, 255), "Hit = %d", player.GetHitFlag());
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "DF = %.0f", defense_point);
	//DrawFormatString(0, 80, GetColor(255, 255, 255), "EnemyDestroyVolumeOnHelthRecovery = %.0f", enemy_destory_volume);

}


void Player::SetPlayerSize(float new_size)
{
	player_size = new_size;
}

void Player::isEnemyDestoryHelthRecovery(float destory_enemy_volume)
{
	enemy_destory_volume = destory_enemy_volume;
}


float Player::GetPlayerSize()
{
	return player_size;
}

float Player::GetPlayerDefensePoint()
{
	return defense_point;
}

float Player::GetEnemyDestoryVolume()
{
	return enemy_destory_volume;
}


DiploidCircleV2* Player::PlayerCirclePtr()
{
	return& player;
}


std::list<PlayerAttack>* Player::GetAttackListPtr()
{
	return& attack_list;
}

std::list<PlayerDefense>* Player::GetDefenseListPtr()
{
	return& defense_list;
}


std::list<PlayerAttack>::iterator Player::GetAttackListIterator()
{
	return attack_list.begin();
}

std::list<PlayerDefense>::iterator Player::GetDefenseListIterator()
{
	return defense_list.begin();
}