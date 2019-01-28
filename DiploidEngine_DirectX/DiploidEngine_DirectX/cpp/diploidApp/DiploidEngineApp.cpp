#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{
	
}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	
	object.map.Load("texter/MAP/test_map.png", 128, 128);//マップ画像データを読み込み(最後のx,yは画像の大きさを指定)
	object.image.Load("texter/test_map_chip/01_ground_rock_32_32.png");
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	object.map.SetMapChipSize(96);//map_data画像の1ドットをどれだけ拡大するか指定
	object.map.Create();//画像データからマップデータを作成

	object.box.Init(VGet(1280/2,720/2 + 90,0), VGet(50, 10,0));//pointグラフィックをマウスに追従させる
	object.box.layer_number = DIPLOID_ENGINE_MAP_HIT_OBJECT;
	object.box.number = OBJECT_NUMBER_PLAYER_DOWN;//下
	object.box.name_tag = "player_down";
	diploidEngineImpact.PushBox(object.box);//pointグラフィックをImpact配列に追加

	object.box.Init(VGet(1280 / 2, 720 / 2 - 4, 0), VGet(50, 10, 0));//pointグラフィックをマウスに追従させる
	object.box.layer_number = DIPLOID_ENGINE_MAP_HIT_OBJECT;
	object.box.number = OBJECT_NUMBER_PLAYER_UP;//上
	object.box.name_tag = "player_up";
	diploidEngineImpact.PushBox(object.box);//pointグラフィックをImpact配列に追加

	object.box.Init(VGet(1280 / 2 - 5, 720 / 2 + 6, 0), VGet(10, 84, 0));//pointグラフィックをマウスに追従させる
	object.box.layer_number = DIPLOID_ENGINE_MAP_HIT_OBJECT;
	object.box.number = OBJECT_NUMBER_PLAYER_LEFT;//左
	object.box.name_tag = "player_left";
	diploidEngineImpact.PushBox(object.box);//pointグラフィックをImpact配列に追加

	object.box.Init(VGet(1280 / 2 + 45, 720 / 2+6, 0), VGet(10, 84, 0));//pointグラフィックをマウスに追従させる
	object.box.layer_number = DIPLOID_ENGINE_MAP_HIT_OBJECT;
	object.box.number = OBJECT_NUMBER_PLAYER_RIGHT;//右
	object.box.name_tag = "player_right";
	diploidEngineImpact.PushBox(object.box);//pointグラフィックをImpact配列に追加


	object.box.Init(VGet(1280 / 2 , 720 / 2, 0), VGet(50, 96, 0));//pointグラフィックをマウスに追従させる
	object.box.layer_number = DIPLOID_ENGINE_PLAYER_ENEMY_HIT_OBJECT;
	object.box.number = OBJECT_NUMBER_PLAYER_BODY;//本体
	object.box.name_tag = "player_body";
	diploidEngineImpact.PushBox(object.box);//pointグラフィックをImpact配列に追加


	for (auto count = object.map.MAP.begin(); count != object.map.MAP.end(); ++count)//map.MAP配列をsize_t(auto)で取得しMAP.end()まで下記のことを繰り返す
	{
		if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))//α値が255の時かつ黒の時
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

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	float gravity = object.physics.Gravity(0.4f, 12.0f);

	if (diploidEngineImpact.GetBoxImpactFlag(OBJECT_NUMBER_PLAYER_DOWN) == 0)//PLAYER下が衝突していないときの処理
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
	else//PLAYER下が衝突しているときの処理
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

void DiploidEngineApp::Draw()//結果を描写する処理
{

}

void DiploidEngineApp::End()//engine終了前処理。
{

}