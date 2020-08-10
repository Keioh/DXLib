#include "data/res_data/field/ground_line.h"


void GroundLine::LoadGraphics()
{
	image.Load("res/stage/ground.png");
}


void GroundLine::Init(float line_pos)
{
	ground_line_pos = VGet(0.0f, line_pos, 0.0f);
	image.Init(VGet(0, line_pos, 0), false);
	image.SetScale(1.5f, 1.5f);
}

void GroundLine::Updata()
{

}

void GroundLine::Draw(bool draw)
{
	//DrawLineAA(ground_line_pos.x, ground_line_pos.y, 1280, ground_line_pos.y, GetColor(255, 255, 255));
	image.Draw(draw);
}


void GroundLine::SetGroundLine(float new_line)
{
	ground_line_pos.y = new_line;
}

float GroundLine::GetGroundLine()
{
	return ground_line_pos.y;
}