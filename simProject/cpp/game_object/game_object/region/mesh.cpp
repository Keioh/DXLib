#include "mesh.h"

void MeshRegion::Init()
{
	building.Init();
}

void MeshRegion::Load()
{
	building.Load();
}

void MeshRegion::Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos)
{
	building.Transform(scale, rote_x, rote_y, rote_z, pos);
}

void MeshRegion::Draw(MODE mode, bool wire)
{	
	building.Mode(mode);

	building.Draw(wire);
}

void MeshRegion::DrawUI(int pos_x, int pos_y, bool wire)
{
	building.DrawUI(pos_x, pos_y, wire);
}