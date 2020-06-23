#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	
	//HPのUI画像を読み込む
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

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{		
	anime.Init(VGet(200, 200, 0), 4.0f, 2.0f);

	//グランドラインの初期化
	ground_line.Init(550.0f);

	//プレイヤーの初期化
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

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
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
			//敵のlistのイテレータを取得し、回す
			for (auto enemy_manager_itr = enemy_manager.GetPtr()->begin(); enemy_manager_itr != enemy_manager.GetPtr()->end(); ++enemy_manager_itr)
			{
				//プレイヤーの攻撃listのイテレータを取得し、回す。
				for (auto palyer_attack_itr = player.GetAttackListPtr()->begin(); palyer_attack_itr != player.GetAttackListPtr()->end(); ++palyer_attack_itr)
				{
					//プレイヤーの攻撃と敵本体との当たり判定
					collision.CircleAndCircleCollisionUpdate(palyer_attack_itr->GetAttackCircleObjectPtr(), enemy_manager_itr->GetCirclePtr());
				}
			}
		}

		if (!player.GetDefenseListPtr()->empty())
		{
			//敵のlistのイテレータを取得し、回す
			for (auto enemy_manager_itr = enemy_manager.GetPtr()->begin(); enemy_manager_itr != enemy_manager.GetPtr()->end(); ++enemy_manager_itr)
			{
				//カウンターフラグがtrueなら
				if (enemy_manager_itr->GetCounterFlag() == true)
				{
					//プレイヤーの攻撃listのイテレータを取得し、回す。
					for (auto palyer_defense_itr = player.GetDefenseListPtr()->begin(); palyer_defense_itr != player.GetDefenseListPtr()->end(); ++palyer_defense_itr)
					{
						//プレイヤーの攻撃と敵本体との当たり判定
						collision.CircleAndCircleCollisionUpdate(palyer_defense_itr->GetDefenseCircleObjectPtr(), enemy_manager_itr->GetCirclePtr());
					}
				}
			}
		}

		//敵のlistのイテレータを取得し、回す
		for (auto enemy_manager_itr = enemy_manager.GetPtr()->begin(); enemy_manager_itr != enemy_manager.GetPtr()->end(); ++enemy_manager_itr)
		{
			if (!enemy_manager_itr->GetAttackListPtr()->empty())
			{
				//敵の攻撃listのイテレータを取得し、回す。
				for (auto enemy_attack_itr = enemy_manager_itr->GetAttackListPtr()->begin(); enemy_attack_itr != enemy_manager_itr->GetAttackListPtr()->end(); ++enemy_attack_itr)
				{
					//プレイヤー本体と敵の攻撃との当たり判定
					collision.CircleAndCircleCollisionUpdate(player.PlayerCirclePtr(), enemy_attack_itr->GetCirclePtr());
				}
			}
		}
	}	
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	forest.Draw();

	player.Draw();

	ground_line.Draw();

	enemy_manager.Draw();

	hp_ui.Draw();

	anime.Draw();
}

void DiploidEngineApp::Destory()//ループ中に削除したいオブジェクト(ver1.0)がある場合はここで削除処理を書く。
{

}

void DiploidEngineApp::End()//engine終了前処理。
{

}