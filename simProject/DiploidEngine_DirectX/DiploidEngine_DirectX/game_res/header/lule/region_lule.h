#pragma once
#include "DxLib.h"

class RegionLule
{
private:

public:

	int player_or_enemy = 0;//土地の所有者(0でプレーヤー、１で中立、２で敵、３で更地)
	int highway_level = 0;//0で道路なし
	int network_level = 0;//0でネットワークなし
	int development_level = 0;//０で未開地や廃墟、１以上で開拓された土地
	int confusion_level = 0;//0で混乱度0

	int productivity = 0;//0で生産力なし
	int economics = 0;//0で経済力なし

	int population = 0;//0で人口0人

};