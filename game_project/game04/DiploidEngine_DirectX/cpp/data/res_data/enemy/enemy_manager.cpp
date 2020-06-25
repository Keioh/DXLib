#include "data/res_data/enemy/enemy_manager.h"

void EnemyManager::PushBackEnemy(_TestEnemy _test_enemy)
{
	_test_enemy_list.push_back(_test_enemy);
}

void EnemyManager::DestoryEnemy()
{
	if (!_test_enemy_list.empty())
	{
		for (auto itr = _test_enemy_list.begin(); itr != _test_enemy_list.end();)
		{
			if (itr->GetCirclePtr()->GetDestoryFlag() == true)
			{
				destory_enmey_volume += 1.0f;
				destroy_flag = true;
				itr = _test_enemy_list.erase(itr);
			}
			else
			{
				++itr;
			}
		}
	}
}

void EnemyManager::Updata()
{
	if (!_test_enemy_list.empty())
	{
		for (auto itr = _test_enemy_list.begin(); itr != _test_enemy_list.end(); ++itr)
		{
			itr->Updata();
		}
	}
}

void EnemyManager::Draw(bool draw)
{
	if (!_test_enemy_list.empty())
	{
		for (auto itr = _test_enemy_list.begin(); itr != _test_enemy_list.end(); ++itr)
		{
			itr->Draw(draw);
		}
	}

	destroy_flag = false;
}


std::list<_TestEnemy>::iterator EnemyManager::GetIterator()
{
	return _test_enemy_list.begin();
}

std::list<_TestEnemy>* EnemyManager::GetPtr()
{
	return &_test_enemy_list;
}


float EnemyManager::GetDestoryEnemyVolume()
{
	return destory_enmey_volume;
}

bool EnemyManager::GetDestoryFlag()
{
	return destroy_flag;
}