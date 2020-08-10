#pragma once
#include <list>
#include "DxLib.h"

class MoveData
{
public:
	float speed;
	float move_time;
	float wait_time;
};

class MovePattern
{
private:
	std::list<MoveData> data;
	std::list<MoveData>* data_ptr = &data;
	std::list<MoveData>::iterator itr = data_ptr->begin();

	MoveData buffer_data;
	float buffer;

public:
	void PushBack(MoveData move_data);
	void Reset();//Å‰‚©‚çÄ¶‚·‚éB
	float Move();
	void Destory();
};