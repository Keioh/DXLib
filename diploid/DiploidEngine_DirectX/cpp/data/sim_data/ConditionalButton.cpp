#include "data/sim_data/ConditionalButton.h"

void ConditionalButton::LoadGraphics()
{
	image.Load("texter/sim_texter/lock.png");
}

void ConditionalButton::LoadHandl()
{

}

void ConditionalButton::Init(VECTOR pos, float scale)
{

}

void ConditionalButton::Updata(DiploidEngineInput* input)
{	
	button.Updata(input);

	if (conditional > 0)
	{

	}
	else
	{
		
	}
}

void ConditionalButton::Draw(bool draw, bool debug)
{
	button.Draw(draw, debug);

	if (conditional == 0)
	{

	}
	else
	{
		image.Draw(draw);
	}
}


DiploidSelectedUIV2* ConditionalButton::GetButtonInfo()
{
	return &button;
}

DiploidImageV2* ConditionalButton::GetImageInfo()
{
	return &image;
}