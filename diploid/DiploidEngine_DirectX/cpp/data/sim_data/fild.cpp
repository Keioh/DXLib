#include "data/sim_data/fild.h"

void Fild::Load()
{
	grass_terrain.Load("texter/sim_texter/grass_terrain.png");//�����摜�̃��[�h
	rock_terrain.Load("texter/sim_texter/rock_terrain.png");//�r�n�摜�̃��[�h

	my_building.Load("texter/sim_texter/my_building.png");//�����_�摜�̃��[�h
}

void Fild::Init(VECTOR pos, float scale)
{
	box.Init(pos, VGet(1024 * scale, 1024 * scale, 0), GetColor(200, 200, 200));

	//�����摜
	grass_terrain.Init(VGet(pos.x + 1024/2, pos.y + 1280/2 - 256 * scale, pos.z));
	grass_terrain.SetScale(scale, scale);

	//�r�n�摜
	rock_terrain.Init(VGet(pos.x + 1024 / 2, pos.y + 1280 / 2 - 256 * scale, pos.z));
	rock_terrain.SetScale(scale, scale);

	//�����_�摜
	my_building.Init(VGet(pos.x + 1024 / 2, pos.y + 1280 / 2 - 256 * scale, pos.z));
	my_building.SetScale(scale, scale);

}

void Fild::Updata(DiploidEngineInput* input)
{
	GetMousePoint(&mouse_x, &mouse_y);//�}�E�X�ʒu�̎擾

	if (collision.BoxAndMouseCollisionUpdate(&box, mouse_x, mouse_y) == true)//�}�E�X�Ǝl�p�̓����蔻��
	{
		box.SetColor(GetColor(255, 0, 0));

		is_hit_mouse = true;//�}�E�X�Ɠ������Ă�����true


		if (input->GetPressMouse(MOUSE_INPUT_LEFT) == true)//�N���b�N������
		{
			box.SetColor(GetColor(0, 255, 0));

			is_click_mouse = true;//�N���b�N���Ă�����true
		}
		else
		{
			is_click_mouse = false;//�N���b�N���Ă�����false
		}
	}
	else
	{
		box.SetColor(GetColor(0, 0, 255));

		is_hit_mouse = false;//�}�E�X�Ɠ������Ă�����false
	}
}

void Fild::Draw(bool draw)
{
	//����
	if (isTerrain == 0)
	{
		if (is_hit_mouse == false)
		{
			grass_terrain.SetBright(on_hit_color_scale);
			grass_terrain.Draw(draw);
		}
		else
		{
			grass_terrain.SetBright();
			grass_terrain.Draw(draw);
		}
	}

	//�r�n
	if (isTerrain == 1)
	{
		if (is_hit_mouse == false)
		{
			rock_terrain.SetBright(on_hit_color_scale);
			rock_terrain.Draw(draw);
		}
		else
		{
			rock_terrain.SetBright();
			rock_terrain.Draw(draw);
		}
	}


	//�����_
	if (isBuilding == 1)
	{
		if (is_hit_mouse == false)
		{
			my_building.SetBright(on_hit_color_scale);
			my_building.Draw(draw);
		}
		else
		{
			my_building.SetBright();
			my_building.Draw(draw);
		}
	}
	
	box.Draw(draw);
}


void Fild::SetBuildingType(int new_building_type)
{
	isBuilding = new_building_type;
}

void Fild::SetTerrainType(int new_terring_type)
{
	isTerrain = new_terring_type;
}


int Fild::GetBuildingType()
{
	return isBuilding;
}

int Fild::GetTerrainType()
{
	return isTerrain;
}


int Fild::GetSizeX()
{
	return box.GetSize().x;
}

int Fild::GetSizeY()
{

	return box.GetSize().y;
}