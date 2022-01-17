#pragma once
#include "DxLib.h"
#include <list>
#include <vector>
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidSlider.h"

class DiploidGroupingUI
{
private:
	std::vector<DiploidSelectedUIV2> selectedUI_list;
	std::vector<int> select_count;

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