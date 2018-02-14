#include "button_ui3D.h"

ButtonUI3D::ButtonUI3D()
{
	ButtonUI3D::Init();
}

void ButtonUI3D::Init()
{
}

void ButtonUI3D::Load(char* path)
{
	box.Load(path);
}

void ButtonUI3D::Transform(VECTOR scale, float rotate_x, float rotate_y, float rotate_z, VECTOR trans)
{
	box.Transform(scale, rotate_x, rotate_y, rotate_z, trans);
}


bool ButtonUI3D::DrawButtonBox3D(bool wire)
{
	box.Draw();

	if (triangle3D_collision_1.TriangleColliderMouse3D(box.vertex[0], box.vertex[1], box.vertex[2], wire) == 1)
	{
		if (mouse.MouseCilck(MOUSE_INPUT_LEFT) == true)
		{
			return click = true;
		}
	}

	if (triangle3D_collision_1.TriangleColliderMouse3D(box.vertex[3], box.vertex[4], box.vertex[5], wire) == 1)
	{
		if (mouse.MouseCilck(MOUSE_INPUT_LEFT) == true)
		{
			return click = true;
		}
	}

	if ((triangle3D_collision_1.TriangleColliderMouse3D(box.vertex[0], box.vertex[1], box.vertex[2], wire) == 1) && (triangle3D_collision_1.TriangleColliderMouse3D(box.vertex[3], box.vertex[4], box.vertex[5], wire) == 1))
	{
		return click = false;
	}

}