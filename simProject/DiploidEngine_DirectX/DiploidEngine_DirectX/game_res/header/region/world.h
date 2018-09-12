#pragma once
#include "diploidObject\DiploidEngineObject.h"
#include "diploidObject\DiploidEngineTag.h"

#include "region\region.h"
#include "lule\world_map_lule.h"


class World
{
private:

	WorldMapLule world_map_lule;

	DiploidObject back_map;

	Region region_01;
	Region region_02;
	Region region_03;
	Region region_04;
	Region region_05;
	Region region_06;
	Region region_07;
	Region region_08;
	Region region_09;
	Region region_10;
	Region region_11;
	Region region_12;

	void InputUpadata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);//インプットアップデートまとめ
	bool TerritoryMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//領土マップを表示するための処理
	bool PopulationMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//人口マップを表示するための処理
	bool NetworkMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//ネットワークマップを表示するための処理
	bool ProductivityMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//生産力マップを表示するための処理
	bool EconomicsMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//経済力マップを表示するための処理

	bool NormalMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//平常マップを表示するための処理

	void SetTerritory();//各地域の領土占有状態をセット
	void SetPopulation();//各地域の人口をセット
	void SetNetworkLevel();//各地域のネットワークレベルをセット
	void SetProductivity();//各地域の生産力をセット
	void SetEconomics();//各地域の経済力をセット


public:


	void Load();//すべてを読み込む
	void Init(VECTOR position);//必ず読みだす

	void Push(DiploidEngineImpact& impact, DiploidEngineLayer& layer);

	void Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);

	void Draw();

	//DiploidImage GetImage();//image情報を返します。

};