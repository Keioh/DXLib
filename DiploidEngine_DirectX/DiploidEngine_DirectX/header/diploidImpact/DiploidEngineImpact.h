#pragma once
#include <vector>
#include "diploidObject\DiploidEngineObject.h"

#include "diploidGraphics\diploidCircle.h"

class DiploidEngineImpact
{
private:
	std::vector<DiploidCircle> circle_vector;

public:
	void Updata();
	void Draw(bool wire = true);
};