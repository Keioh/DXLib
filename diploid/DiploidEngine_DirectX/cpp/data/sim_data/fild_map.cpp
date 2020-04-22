#include "data/sim_data/fild_map.h"


void FildMap::LoadGraphics()
{
	grass_terrain.Load("texter/sim_texter/grass_terrain.png");//�����摜�̃��[�h
	rock_terrain.Load("texter/sim_texter/rock_terrain.png");//�r�n�摜�̃��[�h
	mountain_terrain.Load("texter/sim_texter/mountain_terrain.png");//�R�x�n�щ摜�̃��[�h

	my_building.Load("texter/sim_texter/my_building.png");//�����_�摜�̃��[�h
}

void FildMap::LoadHandl()
{
	for (int x = 0; x != MAP_SIZE_X; ++x)
	{
		for (int y = 0; y != MAP_SIZE_Y; ++y)
		{
			//MAP�`�b�v�̉摜�̓ǂݍ���
			fild[y][x].LoadGrassTerrain(grass_terrain.GetGraphicsHandl());//�����摜�̃��[�h
			fild[y][x].LoadRockTerrain(rock_terrain.GetGraphicsHandl());//�r�n�摜�̃��[�h
			fild[y][x].LoadMountainTerrain(mountain_terrain.GetGraphicsHandl());//�R�x�n�щ摜�̃��[�h

			fild[y][x].LoadMyBuilding(my_building.GetGraphicsHandl());//�����_�摜�̃��[�h
		}
	}
}

void FildMap::Load()
{
	LoadGraphics();
	LoadHandl();
}


void FildMap::Init(VECTOR position, float map_size_scale)
{
	map_shift = position;
	scale = map_size_scale;

	for (int x = 0; x != MAP_SIZE_X - 1; ++x)
	{
		for (int y = 0; y != MAP_SIZE_Y - 1; ++y)
		{
			fild[y][x].Init(VGet((x * (1024 * scale)) + position.x, (y * (1024 * scale)) + position.y, 0), scale);//�n�`�̏�����
			fild[y][x].SetTerrainType(GetRand(2));//�n�`�������_���ɐݒ�
			fild[y][x].SetBuildingType(GetRand(200));//�����������_���ɐݒ�(�폜�\��)
		}
	}

	//fild[8][10].SetBuildingType(BUILDING_TYPE_MY_BASE);//�����_�̌���
}

void FildMap::Updata(DiploidEngineInput* input)
{
	GetMousePoint(&mouse_x, &mouse_y);	

	mouse_scrole += input->GetWhellVolume() * 0.001f;//�}�E�X�X�N���[���Ń}�b�v�̊g��k��
	
	//�J�����̈ړ�
	CameraInput(input);

	for (int x = 0; x != MAP_SIZE_X - 1; ++x)
	{
		for (int y = 0; y != MAP_SIZE_Y - 1; ++y)
		{
			fild[y][x].Init(VGet((x * (1024 * (scale + mouse_scrole))) + camera_x + map_shift.x, (y * (1024 * (scale + mouse_scrole))) + camera_y + map_shift.y, 0.0f), scale + mouse_scrole);//�n�`�̑傫���ƈړ�

			fild[y][x].Updata(input);//�n�`�̍X�V

			//�N���b�N���ꂽ�ꏊ�ȊO�̃N���b�N�t���O��false��
			if (fild[y][x].GetClick() == 1)
			{
				for (int X = 0; X != MAP_SIZE_X - 1; ++X)
				{
					for (int Y = 0; Y != MAP_SIZE_Y - 1; ++Y)
					{						
						if ((X != x) || (Y != y))
						{
							fild[Y][X].SetClick(-1);
						}
					}
				}
			}	

			//�����̗̈���X�V
			if (fild[y][x].GetBuildingType() == BUILDING_TYPE_MY_BASE)//�����_�������Ă�������͈�}�X�������̗̈�ɂ���B
			{
				//��̒i
				if ((0 <= (y - 1)) && (0 <= (x - 1))) { fild[y - 1][x - 1].SetFildType(MY_FILD); }
				if (0 <= (y - 1)) { fild[y - 1][x].SetFildType(MY_FILD); }
				if ((0 <= (y - 1)) && (MAP_SIZE_X >= (x + 1))) { fild[y - 1][x + 1].SetFildType(MY_FILD); }

				//���̒i
				if (0 <= (x - 1)) { fild[y][x - 1].SetFildType(MY_FILD); }
				fild[y][x].SetFildType(MY_FILD);
				if (MAP_SIZE_X >= (x + 1)) { fild[y][x + 1].SetFildType(MY_FILD); }

				//���̒i
				if ((MAP_SIZE_Y >= (y + 1)) && (0 <= (x - 1))) { fild[y + 1][x - 1].SetFildType(MY_FILD); }
				if (MAP_SIZE_Y >= (y + 1)) { fild[y + 1][x].SetFildType(MY_FILD); }
				if ((MAP_SIZE_Y >= (y + 1)) && (MAP_SIZE_X >= (x + 1))) { fild[y + 1][x + 1].SetFildType(MY_FILD); }
			}
		}
	}
}

void FildMap::Draw(bool draw, bool debug)
{
	for (int x = 0; x != MAP_SIZE_X - 1; ++x)
	{
		for (int y = 0; y != MAP_SIZE_Y - 1; ++y)
		{
			fild[y][x].Draw(draw, debug);//�n�`�̕`��
		}
	}

	SetDrawBright(255, 255, 255);

}



int FildMap::GetClick()
{
	return click_flag;
}

Fild FildMap::GetClickedFildInfomation()
{
	Fild buffer;

	for (int x = 0; x != MAP_SIZE_X - 1; ++x)
	{
		for (int y = 0; y != MAP_SIZE_Y - 1; ++y)
		{
			if (fild[y][x].GetClick() == 1)
			{
				buffer = fild[y][x];
			}
		}
	}

	return buffer;
}

Fild FildMap::GetHitFildInfomation()
{
	Fild buffer;

	for (int x = 0; x != MAP_SIZE_X - 1; ++x)
	{
		for (int y = 0; y != MAP_SIZE_Y - 1; ++y)
		{
			if (fild[y][x].GetHit() == true)
			{
				buffer = fild[y][x];
			}
		}
	}

	return buffer;
}


void FildMap::SetCollisionActiveFlag(bool flag)
{
	for (int x = 0; x != MAP_SIZE_X - 1; ++x)
	{
		for (int y = 0; y != MAP_SIZE_Y - 1; ++y)
		{
			fild[y][x].SetCollisionActiveFlag(flag);
		}
	}
}


void FildMap::CameraInput(DiploidEngineInput* input)
{
	//�J�����̈ړ�
	if (input->GetKey(KEY_INPUT_LEFT) == true) { camera_x += camera_speed; }
	if (input->GetKey(KEY_INPUT_RIGHT) == true) { camera_x -= camera_speed; }
	if (input->GetKey(KEY_INPUT_UP) == true) { camera_y += camera_speed; }
	if (input->GetKey(KEY_INPUT_DOWN) == true) { camera_y -= camera_speed; }
}