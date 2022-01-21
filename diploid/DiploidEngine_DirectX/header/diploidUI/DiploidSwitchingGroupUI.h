#pragma once
#include "DxLib.h"
#include <list>
#include <map>
#include <vector>
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidSlider.h"


class DiploidSwitchingGroupUI
{
private:
	std::vector<DiploidSelectedUIV2> selectedUI_list;

public:

	void Update();
	void Draw(bool draw = true);

	void Push(DiploidSelectedUIV2 data);

	std::vector<DiploidSelectedUIV2>& VectorPointer();

};

class DiploidUIGroup
{
private:

public:

};