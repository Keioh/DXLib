#include "region\world.h"

void World::Load()
{
	back_map.image.Load("game_res/texter/region/test_map.png");

	region_01.LoadTexter("game_res/texter/region/01.png");
	region_02.LoadTexter("game_res/texter/region/02.png");
	region_03.LoadTexter("game_res/texter/region/03.png");
	region_04.LoadTexter("game_res/texter/region/04.png");
	region_05.LoadTexter("game_res/texter/region/05.png");
	region_06.LoadTexter("game_res/texter/region/06.png");
	region_07.LoadTexter("game_res/texter/region/07.png");
	region_08.LoadTexter("game_res/texter/region/08.png");
	region_09.LoadTexter("game_res/texter/region/09.png");
	region_10.LoadTexter("game_res/texter/region/10.png");
	region_11.LoadTexter("game_res/texter/region/11.png");
	region_12.LoadTexter("game_res/texter/region/12.png");

}

void World::SetTerritory()
{
	//領土占有の状態をセット
	region_01.region_lule.player_or_enemy = PLAYER;
	region_02.region_lule.player_or_enemy = UNEXPLORED;
	region_03.region_lule.player_or_enemy = UNEXPLORED;
	region_04.region_lule.player_or_enemy = UNEXPLORED;
	region_05.region_lule.player_or_enemy = UNEXPLORED;
	region_06.region_lule.player_or_enemy = UNEXPLORED;
	region_07.region_lule.player_or_enemy = UNEXPLORED;
	region_08.region_lule.player_or_enemy = ENEMY;
	region_09.region_lule.player_or_enemy = UNEXPLORED;
	region_10.region_lule.player_or_enemy = UNEXPLORED;
	region_11.region_lule.player_or_enemy = UNEXPLORED;
	region_12.region_lule.player_or_enemy = UNEXPLORED;
}

void World::SetPopulation()
{
	region_01.region_lule.population = 1000;
	region_02.region_lule.population = 0;
	region_03.region_lule.population = 0;
	region_04.region_lule.population = 5000;
	region_05.region_lule.population = 0;
	region_06.region_lule.population = 0;
	region_07.region_lule.population = 0;
	region_08.region_lule.population = 1000;
	region_09.region_lule.population = 0;
	region_10.region_lule.population = 0;
	region_11.region_lule.population = 6000;
	region_12.region_lule.population = 0;

}

void World::SetNetworkLevel()
{
	region_01.region_lule.network_level = 1;
	region_02.region_lule.network_level = 0;
	region_03.region_lule.network_level = 0;
	region_04.region_lule.network_level = 0;
	region_05.region_lule.network_level = 0;
	region_06.region_lule.network_level = 0;
	region_07.region_lule.network_level = 0;
	region_08.region_lule.network_level = 1;
	region_09.region_lule.network_level = 0;
	region_10.region_lule.network_level = 0;
	region_11.region_lule.network_level = 0;
	region_12.region_lule.network_level = 0;
}

void World::SetProductivity()
{
	region_01.region_lule.productivity = 1000;
	region_02.region_lule.productivity = 0;
	region_03.region_lule.productivity = 0;
	region_04.region_lule.productivity = 0;
	region_05.region_lule.productivity = 0;
	region_06.region_lule.productivity = 0;
	region_07.region_lule.productivity = 0;
	region_08.region_lule.productivity = 1000;
	region_09.region_lule.productivity = 0;
	region_10.region_lule.productivity = 0;
	region_11.region_lule.productivity = 0;
	region_12.region_lule.productivity = 0;
}

void World::SetEconomics()
{
	region_01.region_lule.economics = 10000;
	region_02.region_lule.economics = 0;
	region_03.region_lule.economics = 0;
	region_04.region_lule.economics = 0;
	region_05.region_lule.economics = 0;
	region_06.region_lule.economics = 0;
	region_07.region_lule.economics = 0;
	region_08.region_lule.economics = 10000;
	region_09.region_lule.economics = 0;
	region_10.region_lule.economics = 0;
	region_11.region_lule.economics = 0;
	region_12.region_lule.economics = 0;
}

void World::Init(VECTOR position)
{
	back_map.image.Init(position, 8);

	SetTerritory();
	SetPopulation();
	SetNetworkLevel();
	SetProductivity();
	SetEconomics();

	region_01.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_01.SetObjectNumber(REGION_01);
	region_01.image.Init(position, 8);
	region_01.box.Init(VGet(position.x + 120, position.y - 220, 0), VGet(128,64,0));

	region_02.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_02.SetObjectNumber(REGION_02);
	region_02.image.Init(position, 8);
	region_02.box.Init(VGet(position.x + 60, position.y - 120, 0), VGet(48, 48, 0));

	region_03.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_03.SetObjectNumber(REGION_03);
	region_03.image.Init(position, 8);
	region_03.box.Init(VGet(position.x + 110, position.y - 80, 0), VGet(48, 48, 0));

	region_04.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_04.SetObjectNumber(REGION_04);
	region_04.image.Init(position, 8);
	region_04.box.Init(VGet(position.x + 110, position.y, 0), VGet(48, 48, 0));

	region_05.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_05.SetObjectNumber(REGION_05);
	region_05.image.Init(position, 8);
	region_05.box.Init(VGet(position.x + 50, position.y + 25, 0), VGet(48, 126, 0));

	region_06.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_06.SetObjectNumber(REGION_06);
	region_06.image.Init(position, 8);
	region_06.box.Init(VGet(position.x + 100, position.y + 100, 0), VGet(64, 128, 0));

	region_07.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_07.SetObjectNumber(REGION_07);
	region_07.image.Init(position, 8);
	region_07.box.Init(VGet(position.x - 60, position.y + 100, 0), VGet(64, 128, 0));

	region_08.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_08.SetObjectNumber(REGION_08);
	region_08.image.Init(position, 8);
	region_08.box.Init(VGet(position.x - 180, position.y + 140, 0), VGet(64, 64, 0));

	region_09.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_09.SetObjectNumber(REGION_09);
	region_09.image.Init(position, 8);
	region_09.box.Init(VGet(position.x - 90, position.y - 40, 0), VGet(64, 86, 0));

	region_10.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_10.SetObjectNumber(REGION_10);
	region_10.image.Init(position, 8);
	region_10.box.Init(VGet(position.x - 160, position.y - 120, 0), VGet(64, 64, 0));

	region_11.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_11.SetObjectNumber(REGION_11);
	region_11.image.Init(position, 8);
	region_11.box.Init(VGet(position.x - 220, position.y - 200, 0), VGet(160, 64, 0));

	region_12.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_12.SetObjectNumber(REGION_12);
	region_12.image.Init(position, 8);
	region_12.box.Init(VGet(position.x - 40 , position.y - 160, 0), VGet(64, 115, 0));

}

void World::Push(DiploidEngineImpact& impact, DiploidEngineLayer& layer)
{
	impact.PushBox(region_01.GetBox());
	layer.PushMidGraphics(region_01.GetImage());

	impact.PushBox(region_02.GetBox());
	layer.PushMidGraphics(region_02.GetImage());

	impact.PushBox(region_03.GetBox());
	layer.PushMidGraphics(region_03.GetImage());

	impact.PushBox(region_04.GetBox());
	layer.PushMidGraphics(region_04.GetImage());

	impact.PushBox(region_05.GetBox());
	layer.PushMidGraphics(region_05.GetImage());

	impact.PushBox(region_06.GetBox());
	layer.PushMidGraphics(region_06.GetImage());

	impact.PushBox(region_07.GetBox());
	layer.PushMidGraphics(region_07.GetImage());

	impact.PushBox(region_08.GetBox());
	layer.PushMidGraphics(region_08.GetImage());

	impact.PushBox(region_09.GetBox());
	layer.PushMidGraphics(region_09.GetImage());

	impact.PushBox(region_10.GetBox());
	layer.PushMidGraphics(region_10.GetImage());

	impact.PushBox(region_11.GetBox());
	layer.PushMidGraphics(region_11.GetImage());

	impact.PushBox(region_12.GetBox());
	layer.PushMidGraphics(region_12.GetImage());

}

void World::InputUpadata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	TerritoryMap(layer, input);
	PopulationMap(layer, input);
	NetworkMap(layer, input);
	ProductivityMap(layer, input);
	EconomicsMap(layer, input);
	NormalMap(layer, input);
}

bool World::EconomicsMap(DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	//経済力マップがオフの時
	if (input.GetPressKey(KEY_INPUT_E))
	{
		world_map_lule.economics_map = true;//経済力マップ
		world_map_lule.productivity_map = false;//生産力マップ
		world_map_lule.network_map = false;//ネットワークマップ
		world_map_lule.population_map = false;//人口マップ
		world_map_lule.territory_map = false;//領土マップ
	}

	//経済力マップがオンの時
	if (world_map_lule.economics_map == true)
	{
		for (auto layer_count = layer.image_mid_vector.begin(); layer_count != layer.image_mid_vector.end(); ++layer_count)
		{
			//生産力が0でないとき、オレンジに表示する
			if ((layer_count->number == REGION_01) && (region_01.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_01.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_01.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_02) && (region_02.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_02.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_02.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_03) && (region_03.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_03.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_03.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_04) && (region_04.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_04.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_04.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_05) && (region_05.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_05.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_05.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_06) && (region_06.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_06.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_06.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_07) && (region_07.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_07.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_07.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_08) && (region_08.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_08.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_08.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_09) && (region_09.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_09.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_09.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_10) && (region_10.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_10.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_10.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_11) && (region_11.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_11.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_11.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_12) && (region_12.region_lule.economics != 0))
			{
				layer_count->red_bright *= region_12.region_lule.economics * 0.0001;
				layer_count->green_bright *= region_12.region_lule.economics * 0.0001;
				layer_count->blue_bright *= 0;
			}
		}

		return true;
	}

}

bool World::ProductivityMap(DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	//生産力マップがオフの時
	if (input.GetPressKey(KEY_INPUT_I))
	{
		world_map_lule.productivity_map = true;//生産力マップ
		world_map_lule.network_map = false;//ネットワークマップ
		world_map_lule.population_map = false;//人口マップ
		world_map_lule.territory_map = false;//領土マップ
		world_map_lule.economics_map = false;//経済力マップ
	}

	//生産力マップがオンの時
	if (world_map_lule.productivity_map == true)
	{
		for (auto layer_count = layer.image_mid_vector.begin(); layer_count != layer.image_mid_vector.end(); ++layer_count)
		{
			//生産力が0でないとき、オレンジに表示する
			if ((layer_count->number == REGION_01) && (region_01.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_01.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_01.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_02) && (region_02.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_02.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_02.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_03) && (region_03.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_03.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_03.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_04) && (region_04.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_04.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_04.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_05) && (region_05.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_05.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_05.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_06) && (region_06.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_06.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_06.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_07) && (region_07.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_07.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_07.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_08) && (region_08.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_08.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_08.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_09) && (region_09.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_09.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_09.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_10) && (region_10.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_10.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_10.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_11) && (region_11.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_11.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_11.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_12) && (region_12.region_lule.productivity != 0))
			{
				layer_count->red_bright *= region_12.region_lule.productivity * 0.001;
				layer_count->green_bright *= region_12.region_lule.productivity * 0.0005;
				layer_count->blue_bright *= 0;
			}
		}

		return true;
	}

}

bool World::NetworkMap(DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	//ネットワークマップがオフの時
	if (input.GetPressKey(KEY_INPUT_W))
	{
		world_map_lule.network_map = true;//ネットワークマップ
		world_map_lule.population_map = false;//人口マップ
		world_map_lule.territory_map = false;//領土マップ
		world_map_lule.economics_map = false;//経済力マップ
	}

	//ネットワークマップがオンの時
	if (world_map_lule.network_map == true)
	{
		for (auto layer_count = layer.image_mid_vector.begin(); layer_count != layer.image_mid_vector.end(); ++layer_count)
		{
			//ネットワークが0でないとき、緑に表示する
			if ((layer_count->number == REGION_01) && (region_01.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_01.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_02) && (region_02.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_02.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_03) && (region_03.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_03.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_04) && (region_04.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_04.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_05) && (region_05.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_05.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_06) && (region_06.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_06.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_07) && (region_07.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_07.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_08) && (region_08.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_08.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_09) && (region_09.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_09.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_10) && (region_10.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_10.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_11) && (region_11.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_11.region_lule.network_level * 0.1;
			}

			if ((layer_count->number == REGION_12) && (region_12.region_lule.network_level != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= region_12.region_lule.network_level * 0.1;
			}
		}

		return true;
	}
}

bool World::PopulationMap(DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	//人口マップがオフの時

	if (input.GetPressKey(KEY_INPUT_P))
	{
		world_map_lule.population_map = true;//人口マップ
		world_map_lule.territory_map = false;//領土マップ
		world_map_lule.network_map = false;//ネットワークマップ
		world_map_lule.economics_map = false;//経済力マップ
	}

	//人口マップがオンの時
	if (world_map_lule.population_map == true)
	{

		for (auto layer_count = layer.image_mid_vector.begin(); layer_count != layer.image_mid_vector.end(); ++layer_count)
		{
			//人口が0でないとき、緑に表示する
			if ((layer_count->number == REGION_01) && (region_01.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_01.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_02) && (region_02.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_02.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_03) && (region_03.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_03.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_04) && (region_04.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_04.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_05) && (region_05.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_05.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_06) && (region_06.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_06.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_07) && (region_07.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_07.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_08) && (region_08.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_08.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_09) && (region_09.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_09.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_10) && (region_10.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_10.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_11) && (region_11.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_11.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_12) && (region_12.region_lule.population != 0))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= region_12.region_lule.population * 0.0001;
				layer_count->blue_bright *= 0;
			}
		}

		return true;
	}
}

bool World::TerritoryMap(DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	if (input.GetPressKey(KEY_INPUT_T))
	{	
		world_map_lule.territory_map = true;//領土マップ
		world_map_lule.population_map = false;//人口マップ
		world_map_lule.network_map = false;//ネットワークマップ
		world_map_lule.economics_map = false;//経済力マップ
	}

	//領土マップがオンの時
	if (world_map_lule.territory_map == 1)
	{
		for (auto layer_count = layer.image_mid_vector.begin(); layer_count != layer.image_mid_vector.end(); ++layer_count)
		{

			//領土がプレーヤーの場合、青く表示する
			if ((layer_count->number == REGION_01) && (region_01.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_02) && (region_02.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_03) && (region_03.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_04) && (region_04.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_05) && (region_05.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_06) && (region_06.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_07) && (region_07.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_08) && (region_08.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_09) && (region_09.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_10) && (region_10.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_11) && (region_11.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			if ((layer_count->number == REGION_12) && (region_12.region_lule.player_or_enemy == PLAYER))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 1;
			}

			//領土が中立の場合、緑で表示する
			if ((layer_count->number == REGION_01) && (region_01.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_02) && (region_02.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_03) && (region_03.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_04) && (region_04.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_05) && (region_05.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_06) && (region_06.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_07) && (region_07.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_08) && (region_08.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_09) && (region_09.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_10) && (region_10.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_11) && (region_11.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_12) && (region_12.region_lule.player_or_enemy == NEUTRAL))
			{
				layer_count->red_bright *= 0;
				layer_count->green_bright *= 1;
				layer_count->blue_bright *= 0;
			}

			//領土が敵の場合、赤で表示する
			if ((layer_count->number == REGION_01) && (region_01.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_02) && (region_02.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_03) && (region_03.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_04) && (region_04.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_05) && (region_05.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_06) && (region_06.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_07) && (region_07.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_08) && (region_08.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_09) && (region_09.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_10) && (region_10.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_11) && (region_11.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

			if ((layer_count->number == REGION_12) && (region_12.region_lule.player_or_enemy == ENEMY))
			{
				layer_count->red_bright *= 1;
				layer_count->green_bright *= 0;
				layer_count->blue_bright *= 0;
			}

		}

		return true;
	}

	return false;
}

bool World::NormalMap(DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	if (input.GetPressKey(KEY_INPUT_N))
	{
		world_map_lule.territory_map = false;//領土マップ
		world_map_lule.population_map = false;//人口マップ
		world_map_lule.network_map = false;//ネットワークマップ
		world_map_lule.productivity_map = false;//生産力マップ
		world_map_lule.economics_map = false;//経済力マップ

	}

	if (world_map_lule.GetAllStateFalse() == true)
	{
		return true;
	}

	return false;
}

void World::Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	region_01.Updata(impact, layer, input);
	region_02.Updata(impact, layer, input);
	region_03.Updata(impact, layer, input);
	region_04.Updata(impact, layer, input);
	region_05.Updata(impact, layer, input);
	region_06.Updata(impact, layer, input);
	region_07.Updata(impact, layer, input);
	region_08.Updata(impact, layer, input);
	region_09.Updata(impact, layer, input);
	region_10.Updata(impact, layer, input);
	region_11.Updata(impact, layer, input);
	region_12.Updata(impact, layer, input);

	InputUpadata(impact, layer, input);
}

void World::Draw()
{
	back_map.image.Draw();
}