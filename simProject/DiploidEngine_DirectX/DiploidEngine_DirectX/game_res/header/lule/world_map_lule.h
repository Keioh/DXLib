#pragma once
#include "DxLib.h"

class WorldMapLule
{
private:

public:

	bool territory_map = false;//�̓y�}�b�v
	bool population_map = false;//�l���}�b�v
	bool network_map = false;//�l�b�g���[�N�}�b�v
	bool productivity_map = false;//���Y�̓}�b�v
	bool economics_map = false;//�o�ϗ̓}�b�v
	bool confusion_map = false;//�����x�}�b�v
	bool happiness_map = false;//�K���x�}�b�v

	bool GetAllStateFalse();//�S�Ẵt���O��false�Ȃ�false��ς����B
};