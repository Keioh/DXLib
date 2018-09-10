#include "region\world.h"

void World::Load()
{
	region_01.LoadTexter("game_res/texter/region/01.png");
	//Region::LoadSound("");
}

void World::Init(VECTOR position)
{
	region_01.SetLayerNumber(DIPLOID_ENGINE_GAMEOBJECT);
	region_01.SetObjectNumber(REGION_01);
	region_01.image.Init(position);
	region_01.box.Init(VGet(position.x, position.y - 32, 0), VGet(32,32,0));
}

void World::Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer)
{
	region_01.Updata(impact, layer);
}