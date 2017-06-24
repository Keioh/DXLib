#pragma once
#include "Object_Base.h"

class Collision : public ObjectBase
{

private:
	int red;
	int blue;
	int green;

public:
	Collision();
	~Collision(){};

	int size_x;
	int size_y;
	int size_r;

	bool BoxCollider(int position_x, int size_x, int position_y, int size_y, bool wire = false);		//box�����蔻��(�_�Ǝl�p)
	bool CircleCollider(int position_x, int position_y, int size_r , bool wire = false);		//circle�����蔻��(�_�Ɖ~)

};