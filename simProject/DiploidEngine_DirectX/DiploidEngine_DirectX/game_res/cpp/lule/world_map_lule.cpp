#include "lule\world_map_lule.h"

bool WorldMapLule::GetAllStateFalse()
{
	if ((territory_map && population_map) == false)
	{
		return true;
	}

	return false;
}