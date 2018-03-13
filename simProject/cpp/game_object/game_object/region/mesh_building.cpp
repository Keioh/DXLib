#include "mesh_building.h"

void MeshBuilding::Init()
{
	building0.Init();
	building1.Init();
	building2.Init();
	building_type = 2;
}

void MeshBuilding::Load()
{
	building0.Load("pack/GameObject/models/empty_lot.png");
	building1.Load("pack/GameObject/models/market_place.png");
	building2.Load("pack/GameObject/models/laboratory.png");
}

void MeshBuilding::Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos)
{
	building0.Transform(scale, rote_x, rote_y, rote_z, pos);
	building1.Transform(scale, rote_x, rote_y, rote_z, pos);
	building2.Transform(scale, rote_x, rote_y, rote_z, pos);
}

void MeshBuilding::Updata()
{

}

void MeshBuilding::Draw(MODE mode, bool wire)
{		
	if (building_type == 0)//�����^�C�v���X�n(0)�Ȃ�
	{
		building0.Mode(mode);
		building0.Draw(wire);
	}
	else if (building_type == 1)//�����^�C�v�����Տ�(1)�Ȃ�
	{
		building1.Mode(mode);
		building1.Draw(wire);
	}
	else if (building_type == 2)//�����^�C�v��������(2)�Ȃ�
	{
		building2.Mode(mode);
		building2.Draw(wire);
	}
}

void MeshBuilding::DrawUI(int pos_x, int pos_y, MODE mode, bool wire)
{	
	if (building_type == 0)//�����^�C�v���X�n(0)�Ȃ�
	{
		building0.DrawUI(pos_x, pos_y, wire);
	}
	else if (building_type == 1)//�����^�C�v�����Տ�(1)�Ȃ�
	{
		building1.DrawUI(pos_x, pos_y, wire);
	}
	else if (building_type == 2)//�����^�C�v��������(2)�Ȃ�
	{
		building2.DrawUI(pos_x, pos_y, wire);
	}

	//�ڑ����[�h���I���̎���UI�\��
	if (mode.connection_mode == 1)
	{

	}
}