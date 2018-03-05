#include "mesh.h"

void MeshRegion::Init()
{
	building.Init();
}

void MeshRegion::Load()
{
	building.Load();
}

void MeshRegion::Draw(VECTOR pos, bool wire)
{
	building.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, pos);
	building.Draw(wire);
}

void MeshRegion::DrawUI(int pos_x, int pos_y, bool wire)
{
	building.DrawUI(pos_x, pos_y, wire);
}