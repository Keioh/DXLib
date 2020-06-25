#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "ver2.0/Graphics/DiploidImageV2.h"

//”š•\¦ˆ—
class Number//ˆêŒ…—p
{
private:
	
	DiploidImageV2 number_1;
	DiploidImageV2 number_2;
	DiploidImageV2 number_3;
	DiploidImageV2 number_4;
	DiploidImageV2 number_5;
	DiploidImageV2 number_6;
	DiploidImageV2 number_7;
	DiploidImageV2 number_8;
	DiploidImageV2 number_9;
	DiploidImageV2 number_0;

	int case_number = 0;

public:

	Number();
	~Number() {};

	void Load();
	void Init(VECTOR pos = { 0.0f,0.0f,0.0f }, float scale = 1.0f);
	void Update(int number = 0);
	void Draw(bool draw = true);
};

class Number1000//4Œ…—p
{
private:
	Number number_1;
	Number number_2;
	Number number_3;
	Number number_4;

	int case_number = 0;

public:
	Number1000();
	~Number1000() {};

	void Load();
	void Init(VECTOR pos = { 0.0f,0.0f,0.0f }, float scale = 1.0f);
	void Update(int number = 0);
	void Draw(bool draw = true);

};