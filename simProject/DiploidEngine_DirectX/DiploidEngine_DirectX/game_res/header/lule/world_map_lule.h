#pragma once
#include "DxLib.h"

class WorldMapLule
{
private:

public:

	bool territory_map = false;//領土マップ
	bool population_map = false;//人口マップ
	bool network_map = false;//ネットワークマップ
	bool productivity_map = false;//生産力マップ
	bool economics_map = false;//経済力マップ

	bool GetAllStateFalse();//全てのフラグがfalseならfalseを変えす。
};