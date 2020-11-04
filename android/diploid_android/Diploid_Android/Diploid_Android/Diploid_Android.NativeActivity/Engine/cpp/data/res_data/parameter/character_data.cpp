#include "data/res_data/parameter/character_data.h"

int CharacterData::GetParameterAllPoints()
{
	return parameter_str + parameter_dex + parameter_con + parameter_int + parameter_luk + parameter_agi + parameter_res + parameter_atk + parameter_cri + parameter_def + parameter_san + parameter_will;
}