#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	player_main.Init(VGet(GetWindowSize().x / 2, 600, 0.0f), 5.0f, GetColor(255, 100, 100), TRUE);//プレイヤー本体
	player_grays.Init(VGet(GetWindowSize().x / 2, 600, 0.0f), 30.0f, GetColor(100, 100, 255));//プレイヤーのグレイズ域
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	input.Update();


	if (input.GetKey(KEY_INPUT_LSHIFT) == true)//左シフトキーを押したら
	{
		slow = 0.5f;//プレイヤーの速さを0.5倍に		
	}
	else
	{
		slow = 1.0f;//プレイヤーの速さを等倍に
	}				

	if (input.GetReleaseKey(KEY_INPUT_LCONTROL) == true)//コントロールキーを押したら
	{
		if (grays_count > 50)//グレイズカウンターが50以上あったら
		{
			grays_count -= 50;//グレイズカウンターを50減らす

			for (auto& count : grays_bullet_list)
			{
				if (count.GetHitFlag() == true)//グレイズ域に入っていたら
				{


					//グレイズ用弾丸を反射
					count.SetMoveSpeed(VGet(-count.GetMoveSpeed().x, -count.GetMoveSpeed().y, 0.0f));
					count.SetDestoryFlag(true);//削除フラグをオンにする。

					//プレイヤー弾丸を作成
					player_bullet_list.push_back(player_bullet);//弾丸をリストに追加
					player_bullet_list.back().Init(VGet(count.GetPosition().x, count.GetPosition().y, 0.0f), count.GetRadius(), GetColor(255, 255, 255), TRUE);//弾丸が発射される位置を設定
					player_bullet_list.back().SetMoveSpeed(VGet((-GetRand(4) + GetRand(4)), -(GetRand(5) + 10), 0));//弾丸の速度と方向を設定。
				}
			}
		}
	}

	if (input.GetKey(KEY_INPUT_LCONTROL) == true)
	{
		ctr_count++;
		if (ctr_count > 70)ctr_count = 70;
		if ((ctr_count > 50) && (grays_count > 300))//コントロールキーを20ループ以上かつグレイズカウンターが250以上なら
		{
			grays_count -= 250;//グレイズカウンターを250減らす

			for (auto& count : grays_bullet_list)
			{
				if (count.GetHitFlag() == true)//グレイズ域に入っていたら
				{
					count.SetMoveSpeed(VGet(0.0f, 0.0f, 0.0f));
					count.SetDestoryFlag(true);//グレイズ用弾丸の削除フラグを立てる。

					//プレイヤーの弾丸を作成
					player_bullet_list.push_back(player_bullet);//弾丸をリストに追加
					player_bullet_list.back().Init(VGet(player_main.GetPosition().x, player_main.GetPosition().y - player_grays.GetRadius(), 0.0f), 10.0f, GetColor(255, 255, 255), TRUE);//弾丸が発射される位置を設定
					player_bullet_list.back().SetMoveSpeed(VGet((-GetRand(4) + GetRand(4)), -(GetRand(5) + 10), 0));//弾丸の速度と方向を設定。	
					
				}
				else
				{
					count.SetMoveSpeed(VGet(-(count.GetPosition().x - player_main.GetPosition().x) / ctr_count, -(count.GetPosition().y - player_main.GetPosition().y) / ctr_count, 0.0f));
				}
			}
		}
	}
	else
	{		
		ctr_count = 30;
	}


	if ((input.GetKey(KEY_INPUT_D) == true) || (input.GetKey(KEY_INPUT_RIGHT) == true))//Dキーを押したら
	{
		if (player_main.GetPosition().x < GetWindowSize().x - player_main.GetRadius())//画面外に行かないように
		{
			//プレイヤー本体の移動
			player_main.SetMoveSpeed(VGet(8.0f * slow, 0.0f, 0.0f));
			player_main.MoveUpdata();

			//プレイヤーグレイズ域の移動
			player_grays.SetMoveSpeed(VGet(8.0f * slow, 0.0f, 0.0f));
			player_grays.MoveUpdata();

		}
	}

	if ((input.GetKey(KEY_INPUT_A) == true) || (input.GetKey(KEY_INPUT_LEFT) == true))//Aキーを押したら
	{
		if (player_main.GetPosition().x > player_main.GetRadius())//画面外に行かないように
		{
			//プレイヤー本体の移動
			player_main.SetMoveSpeed(VGet(-8.0f * slow, 0.0f, 0.0f));
			player_main.MoveUpdata();

			//プレイヤーグレイズ域の移動
			player_grays.SetMoveSpeed(VGet(-8.0f * slow, 0.0f, 0.0f));
			player_grays.MoveUpdata();

		}
	}

	if ((input.GetKey(KEY_INPUT_W) == true) || (input.GetKey(KEY_INPUT_UP) == true))//Wキーを押したら
	{
		if (player_main.GetPosition().y > player_main.GetRadius())//画面外に行かないように
		{
			//プレイヤー本体の移動
			player_main.SetMoveSpeed(VGet(0.0f, -8.0f * slow, 0.0f));
			player_main.MoveUpdata();

			//プレイヤーグレイズ域の移動
			player_grays.SetMoveSpeed(VGet(0.0f, -8.0f * slow, 0.0f));
			player_grays.MoveUpdata();
		}
	}

	if ((input.GetKey(KEY_INPUT_S) == true) || (input.GetKey(KEY_INPUT_DOWN) == true))//Sキーを押したら
	{
		if (player_main.GetPosition().y < GetWindowSize().y - player_main.GetRadius())//画面外に行かないように
		{
			//プレイヤー本体の移動
			player_main.SetMoveSpeed(VGet(0.0f, 8.0f * slow, 0.0f));
			player_main.MoveUpdata();

			//プレイヤーグレイズ域の移動
			player_grays.SetMoveSpeed(VGet(0.0f, 8.0f * slow, 0.0f));
			player_grays.MoveUpdata();
		}
	}


	if (input.GetKey(KEY_INPUT_SPACE) == true)//SPACEキーを押したら
	{
		is_count += 1;
		if (is_count > 0 - (grays_count * 0.2))//グレイズカウンターが溜まっていったら打ち出す速度がアップ
		{
			//プレイヤーの弾丸を作成
			player_bullet_list.push_back(player_bullet);//弾丸をリストに追加
			player_bullet_list.back().Init(VGet(player_main.GetPosition().x, player_main.GetPosition().y - player_grays.GetRadius(), 0.0f), 10.0f, GetColor(255, 255, 255), TRUE);//弾丸が発射される位置を設定
			player_bullet_list.back().SetMoveSpeed(VGet((-GetRand(4) + GetRand(4)), -(GetRand(5) + 10), 0));//弾丸の速度と方向を設定。
			is_count = 0;
		}
	}

	//プレイヤー弾丸の更新
	for (auto& count : player_bullet_list)
	{
		count.MoveUpdata();//プレイヤーの弾丸移動の更新

		//プレイヤー弾丸の画面端の反射
		if (count.GetPosition().x < count.GetRadius())
		{		
			//プレイヤーの弾丸を反射
			count.SetMoveSpeed(VGet(-count.GetMoveSpeed().x, count.GetMoveSpeed().y, 0.0f));	
			count.SetDestoryFlag(true);//削除フラグをオンにする。

			//グレイズ用弾丸を作成
			grays_bullet_list.push_back(grays_bullet);
			grays_bullet_list.back().Init(count.GetPosition(), count.GetRadius(), GetColor(255, 50, 50), TRUE);
			grays_bullet_list.back().SetMoveSpeed(VGet(count.GetMoveSpeed().x * 0.3, count.GetMoveSpeed().y * 0.3, 0.0f));//速度を0.3倍に減速
		}

		if (count.GetPosition().y < count.GetRadius())
		{			
			//プレイヤーの弾丸を反射
			count.SetMoveSpeed(VGet(count.GetMoveSpeed().x, -count.GetMoveSpeed().y, 0.0f));	
			count.SetDestoryFlag(true);//削除フラグをオンにする。

			//グレイズ用弾丸を作成
			grays_bullet_list.push_back(grays_bullet);
			grays_bullet_list.back().Init(count.GetPosition(), count.GetRadius(), GetColor(255, 50, 50), TRUE);
			grays_bullet_list.back().SetMoveSpeed(VGet(count.GetMoveSpeed().x * 0.3, count.GetMoveSpeed().y * 0.3, 0.0f));//速度を0.3倍に減速
		}

		if (count.GetPosition().x > GetWindowSize().x - count.GetRadius())
		{	
			//プレイヤーの弾丸を反射
			count.SetMoveSpeed(VGet(-count.GetMoveSpeed().x, count.GetMoveSpeed().y, 0.0f));	
			count.SetDestoryFlag(true);//削除フラグをオンにする。

			//グレイズ用弾丸を作成
			grays_bullet_list.push_back(grays_bullet);
			grays_bullet_list.back().Init(count.GetPosition(), count.GetRadius(), GetColor(255, 50, 50), TRUE);
			grays_bullet_list.back().SetMoveSpeed(VGet(count.GetMoveSpeed().x * 0.3, count.GetMoveSpeed().y * 0.3, 0.0f));//速度を0.3倍に減速
		}

		if (count.GetPosition().y > GetWindowSize().y - count.GetRadius())
		{		
			//プレイヤーの弾丸を反射
			count.SetMoveSpeed(VGet(count.GetMoveSpeed().x, -count.GetMoveSpeed().y, 0.0f));	
			count.SetDestoryFlag(true);//削除フラグをオンにする。

			//グレイズ用弾丸を作成
			grays_bullet_list.push_back(grays_bullet);
			grays_bullet_list.back().Init(count.GetPosition(), count.GetRadius(), GetColor(255, 50, 50), TRUE);
			grays_bullet_list.back().SetMoveSpeed(VGet(count.GetMoveSpeed().x * 0.3, count.GetMoveSpeed().y * 0.3, 0.0f));//速度を0.3倍に減速
		}
	}

	//グレイズ用弾丸の更新
	for (auto& count : grays_bullet_list)
	{
		count.MoveUpdata();//グレイズ用弾丸移動の更新

		//グレイズ用弾丸の画面端の反射
		if (count.GetPosition().x < 0)
		{
			//グレイズ用弾丸を反射
			count.SetMoveSpeed(VGet(-count.GetMoveSpeed().x, count.GetMoveSpeed().y, 0.0f));
			count.AddLife(1.0f);
		}

		if (count.GetPosition().y < 0)
		{
			//グレイズ用弾丸を反射
			count.SetMoveSpeed(VGet(count.GetMoveSpeed().x, -count.GetMoveSpeed().y, 0.0f));
			count.AddLife(1.0f);
		}

		if (count.GetPosition().x > GetWindowSize().x)
		{
			//グレイズ用弾丸を反射
			count.SetMoveSpeed(VGet(-count.GetMoveSpeed().x, count.GetMoveSpeed().y, 0.0f));
			count.AddLife(1.0f);
		}

		if (count.GetPosition().y > GetWindowSize().y)
		{
			//グレイズ用弾丸を反射
			count.SetMoveSpeed(VGet(count.GetMoveSpeed().x, -count.GetMoveSpeed().y, 0.0f));
			count.AddLife(1.0f);
		}

	}

	//グレイズ域との当たり判定
	for (auto& count : grays_bullet_list)
	{
		collision.CircleAndCircleCollisionUpdata(&player_grays, &count);//グレイズ域との当たり判定

		if (count.GetHitFlag() == true)
		{
			grays_is_count += 1;

			if (grays_is_count > 20)
			{
				grays_count += 1;//グレイズしていたらグレイズのカウンターを上げる
				grays_is_count = 0;
			}
		}
	}
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	//グレイズ用弾丸弾丸の描画
	for (auto& count : grays_bullet_list)
	{
		count.Draw();//グレイズ用弾丸の描画
	}

	//プレイヤー弾丸の描画
	for (auto& count : player_bullet_list)
	{
		count.Draw();//プレイヤー弾丸の描画
	}

	player_main.Draw();//プレイヤーの描画
	player_grays.Draw();//プレイヤーのグレイズ域の描画

	//グレイズしたら
	for (auto& count : grays_bullet_list)
	{
		if (count.GetHitFlag() == true)
		{
			DrawString(player_main.GetPosition().x, player_main.GetPosition().y, "Grays!!", GetColor(255, 255, 255));//グレイズ文字を出す.

		}
	}

	DrawFormatString(0, 20, GetColor(255, 255, 255), "Grays Count %d NOW!!", grays_count);//グレイズカウンターの描画
}

void DiploidEngineApp::Destory()//ループ中に削除したいオブジェクトがある場合はここで削除処理を書く。
{
	//プレイヤー弾丸の削除処理
	if (!player_bullet_list.empty())
	{
		for (auto count = player_bullet_list.begin(); count != player_bullet_list.end();)
		{
			if (count->GetDestoryFlag() == true)//デストロイフラグがtrueなら弾丸を削除
			{
				count = player_bullet_list.erase(count);
				continue;
			}
			++count;
		}
	}

	//グレイズ用弾丸の削除処理
	if (!grays_bullet_list.empty())
	{
		for (auto count = grays_bullet_list.begin(); count != grays_bullet_list.end();)
		{
			if (count->GetDestoryFlag() == true)
			{
				count = grays_bullet_list.erase(count);
				continue;
			}

			if (count->GetLife() >= 10.0f)//寿命が1.0f以上なら弾丸を削除
			{
				count = grays_bullet_list.erase(count);
				continue;
			}
			++count;
		}
	}
}

void DiploidEngineApp::End()//engine終了前処理。
{

}