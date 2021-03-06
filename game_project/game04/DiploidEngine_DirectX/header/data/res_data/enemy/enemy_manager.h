#pragma once
#include <list>
#include "DxLib.h"

#include "data/res_data/enemy/test_enemy.h"

class EnemyManager
{
private:
	std::list<_TestEnemy>_test_enemy_list;
	std::list<_TestEnemy>::iterator _test_enemy_itr;

	float destory_enmey_volume = 0.0f;//撃破数
	bool destroy_flag = false;//撃破されたときにtrueを返す

public:
	void PushBackEnemy(_TestEnemy _test_enemy);
	void DestoryEnemy();

	void Updata();
	void Draw(bool draw = true);

	void SetDestroyEnemyVolume(float new_vol);

	float GetDestoryEnemyVolume();

	bool GetDestoryFlag();

	std::list<_TestEnemy>::iterator GetIterator();
	std::list<_TestEnemy>* GetPtr();

};