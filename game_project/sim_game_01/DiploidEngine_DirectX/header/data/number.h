#pragma once
#include "diploidObject/DiploidEngineObject.h"

//”š•\¦ˆ—
class Number//ˆêŒ…—p
{
private:
	
	DiploidObject number_1;
	DiploidObject number_2;
	DiploidObject number_3;
	DiploidObject number_4;
	DiploidObject number_5;
	DiploidObject number_6;
	DiploidObject number_7;
	DiploidObject number_8;
	DiploidObject number_9;
	DiploidObject number_0;


public:

	Number();
	~Number() {};

	void Load();
	void Init(VECTOR pos = { 0.0f,0.0f,0.0f }, float scale = 1.0f);
	void Update();
	void Draw(int number = 0, bool draw = true);
};

class Number1000//4Œ…—p
{
private:
	Number number_1;
	Number number_2;
	Number number_3;
	Number number_4;

public:
	Number1000();
	~Number1000() {};

	void Load();
	void Init(VECTOR pos = { 0.0f,0.0f,0.0f }, float scale = 1.0f);
	void Update();
	void Draw(int number = 0, bool draw = true);

};