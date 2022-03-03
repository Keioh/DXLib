#include "data/sim_data/fild.h"


void Fild::LoadGrassTerrain(int grass_terrain_handl)
{
	grass_terrain.SetHandl(grass_terrain_handl);//草原画像のロード

	box_size_x = 1024;
	box_size_y = 1024;
}

void Fild::LoadRockTerrain(int rock_terrain_handl)
{
	rock_terrain.SetHandl(rock_terrain_handl);//荒地画像のロード

	box_size_x = 1024;
	box_size_y = 1024;
}

void Fild::LoadMountainTerrain(int mountain_terrain_handl)
{
	mountain_terrain.SetHandl(mountain_terrain_handl);//山岳地帯画像のロード

	box_size_x = 1024;
	box_size_y = 1024;
}

void Fild::LoadMyBuilding(int my_building_handl)
{
	my_building.SetHandl(my_building_handl);//自拠点画像のロード

	box_size_x = 1024;
	box_size_y = 1024;
}


void Fild::Load()
{
	grass_terrain.Load("texter/sim_texter/grass_terrain.png");//草原画像のロード
	rock_terrain.Load("texter/sim_texter/rock_terrain.png");//荒地画像のロード
	mountain_terrain.Load("texter/sim_texter/mountain_terrain.png");//山岳地帯画像のロード

	my_building.Load("texter/sim_texter/my_building.png");//自拠点画像のロード

	box_size_x = 1024;
	box_size_y = 1024;
}

void Fild::Load(int grass_terrain_handl, int rock_terrain_handl, int mountain_terrain_handl, int my_building_handl)
{
	grass_terrain.SetHandl(grass_terrain_handl);//草原画像のロード
	rock_terrain.SetHandl(rock_terrain_handl);//荒地画像のロード
	mountain_terrain.SetHandl(mountain_terrain_handl);//山岳地帯画像のロード

	my_building.SetHandl(my_building_handl);//自拠点画像のロード

	box_size_x = 1024;
	box_size_y = 1024;
}

void Fild::Init(VECTOR pos, float scale)
{	
	box.Init(pos, VGet(1024 * scale, 1024 * scale, 0), GetColor(200, 200, 200));


	//草原画像
	grass_terrain.Init(VGet(pos.x, pos.y - 256 * scale, pos.z),false);
	grass_terrain.SetScale(scale, scale);

	//荒地画像
	rock_terrain.Init(VGet(pos.x, pos.y - 256 * scale, pos.z), false);
	rock_terrain.SetScale(scale, scale);

	//山岳地帯画像
	mountain_terrain.Init(VGet(pos.x, pos.y - 256 * scale, pos.z),false);
	mountain_terrain.SetScale(scale, scale);


	//自拠点画像
	my_building.Init(VGet(pos.x, pos.y - 256 * scale, pos.z),false);
	my_building.SetScale(scale, scale);
}

void Fild::Updata(DiploidEngineInput* input)
{
	if (collision_active_flag == true)//当たり判定フラグがオンだったら
	{	
		GetMousePoint(&mouse_x, &mouse_y);//マウス位置の取得

		if (collision.BoxAndMouseCollisionUpdate(&box, mouse_x, mouse_y) == true)//マウスと四角の当たり判定
		{
			box.SetColor(GetColor(255, 0, 0));

			is_hit_mouse = true;//マウスと当たっていたらtrue


			if (input->GetPressMouse(MOUSE_INPUT_LEFT) == true)//クリックしたら
			{
				box.SetColor(GetColor(0, 255, 0));

				is_click_mouse *= -1;//クリックしていたらtrue

				is_click_mouse;
			}
		}
		else
		{
			box.SetColor(GetColor(0, 0, 255));

			is_hit_mouse = false;//マウスと当たっていたらfalse
		}
	}
}

void Fild::Draw(bool draw, bool debug)
{
	//画面外にあるものを表示しない
	if ((window_size_x + box.GetSize().x > box.GetPosition().x) && (-box.GetSize().x < box.GetPosition().x)
		&& (window_size_y + box.GetSize().y > box.GetPosition().y) && (-box.GetSize().y < box.GetPosition().y))
	{
		if (draw == true)
		{
			//支配領域(誰の物でもない)
			if (isFild == NOT_ANYONE_FILD)
			{
				bright_red = 255;
				bright_green = 255;
				bright_blue = 255;
			}

			//支配領域(自分)
			if (isFild == MY_FILD)//青色を主体に
			{
				bright_red = 150;
				bright_green = 150;
				bright_blue = 255;
			}

			//支配領域(敵)
			if (isFild == ENEMY_FILD)//赤色を主体に
			{
				bright_red = 255;
				bright_green = 150;
				bright_blue = 150;
			}

			//支配領域(友好)
			if (isFild == FRENDLY_FILD)//緑色を主体に
			{
				bright_red = 150;
				bright_green = 255;
				bright_blue = 150;
			}


			//草原
			if (isTerrain == TERRAIN_TYPE_GRASS)
			{
				if (is_hit_mouse == false)
				{
					grass_terrain.SetBright(bright_red * on_hit_color_scale, bright_green * on_hit_color_scale, bright_blue * on_hit_color_scale);
					grass_terrain.Draw(draw);
				}
				else
				{
					grass_terrain.SetBright(bright_red, bright_green, bright_blue);
					grass_terrain.Draw(draw);
				}

				if (is_click_mouse == 1)
				{
					grass_terrain.SetBright(bright_red, bright_green, bright_blue);
					grass_terrain.Draw(draw);
				}
			}

			//荒地
			if (isTerrain == TERRAIN_TYPE_ROCKS)
			{
				if (is_hit_mouse == false)
				{
					rock_terrain.SetBright(bright_red * on_hit_color_scale, bright_green * on_hit_color_scale, bright_blue * on_hit_color_scale);
					rock_terrain.Draw(draw);
				}
				else
				{
					rock_terrain.SetBright(bright_red, bright_green, bright_blue);
					rock_terrain.Draw(draw);
				}

				if (is_click_mouse == 1)
				{
					rock_terrain.SetBright(bright_red, bright_green, bright_blue);
					rock_terrain.Draw(draw);
				}
			}

			//山岳
			if (isTerrain == TERRAIN_TYPE_MOUNTAIN)
			{
				if (is_hit_mouse == false)
				{
					mountain_terrain.SetBright(bright_red * on_hit_color_scale, bright_green * on_hit_color_scale, bright_blue * on_hit_color_scale);
					mountain_terrain.Draw(draw);
				}
				else
				{
					mountain_terrain.SetBright(bright_red, bright_green, bright_blue);
					mountain_terrain.Draw(draw);
				}

				if (is_click_mouse == 1)
				{
					mountain_terrain.SetBright(bright_red, bright_green, bright_blue);
					mountain_terrain.Draw(draw);
				}
			}


			//自拠点
			if (isBuilding == BUILDING_TYPE_MY_BASE)
			{
				if (is_hit_mouse == false)
				{
					my_building.SetBright(bright_red * on_hit_color_scale, bright_green * on_hit_color_scale, bright_blue * on_hit_color_scale);
					my_building.Draw(draw);
				}
				else
				{
					my_building.SetBright(bright_red, bright_green, bright_blue);
					my_building.Draw(draw);
				}

				if (is_click_mouse == 1)
				{
					my_building.SetBright(bright_red, bright_green, bright_blue);
					my_building.Draw(draw);
				}
			}
		}

		box.Draw(debug);
	}

	SetDrawBright(255, 255, 255);

}


void Fild::SetClick(int flag)
{
	is_click_mouse = flag;
}

void Fild::SetBuildingType(int new_building_type)
{
	isBuilding = new_building_type;
}

void Fild::SetTerrainType(int new_terring_type)
{
	isTerrain = new_terring_type;
}

void Fild::SetFildType(int new_fild_type)
{
	isFild = new_fild_type;
}


void Fild::SetCollisionActiveFlag(bool new_flag)
{
	collision_active_flag = new_flag;
}

void Fild::SetMainCameraFlag(bool flag)
{
	box.SetMainCameraFlag(flag);
}

void Fild::SetWindowSize(int x, int y)
{
	window_size_x = x;
	window_size_y = y;
}


int Fild::GetBuildingType()
{
	return isBuilding;
}

int Fild::GetTerrainType()
{
	return isTerrain;
}

int Fild::GetFildType()
{
	return isFild;
}


VECTOR Fild::GetPosition()
{
	return box.GetPosition();
}

int Fild::GetClick()
{
	return is_click_mouse;
}

bool Fild::GetHit()
{
	return is_hit_mouse;
}

bool Fild::GetCollisionActiveFlag()
{
	return collision_active_flag;
}


int Fild::GetSizeX()
{
	return box_size_x;
}

int Fild::GetSizeY()
{
	return box_size_x;
}

bool Fild::GetMainCameraFlag()
{
	return box.GetMainCameraFlag();
}