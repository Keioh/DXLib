#include "data/sim_data/fild.h"

void Fild::Load()
{
	grass_terrain.Load("texter/sim_texter/grass_terrain.png");//草原画像のロード
	rock_terrain.Load("texter/sim_texter/rock_terrain.png");//荒地画像のロード

	my_building.Load("texter/sim_texter/my_building.png");//自拠点画像のロード
}

void Fild::Init(VECTOR pos, float scale)
{
	box.Init(pos, VGet(1024 * scale, 1024 * scale, 0), GetColor(200, 200, 200));

	//草原画像
	grass_terrain.Init(VGet(pos.x + 1024/2, pos.y + 1280/2 - 256 * scale, pos.z));
	grass_terrain.SetScale(scale, scale);

	//荒地画像
	rock_terrain.Init(VGet(pos.x + 1024 / 2, pos.y + 1280 / 2 - 256 * scale, pos.z));
	rock_terrain.SetScale(scale, scale);

	//自拠点画像
	my_building.Init(VGet(pos.x + 1024 / 2, pos.y + 1280 / 2 - 256 * scale, pos.z));
	my_building.SetScale(scale, scale);

}

void Fild::Updata(DiploidEngineInput* input)
{
	GetMousePoint(&mouse_x, &mouse_y);//マウス位置の取得

	if (collision.BoxAndMouseCollisionUpdate(&box, mouse_x, mouse_y) == true)//マウスと四角の当たり判定
	{
		box.SetColor(GetColor(255, 0, 0));

		is_hit_mouse = true;//マウスと当たっていたらtrue


		if (input->GetPressMouse(MOUSE_INPUT_LEFT) == true)//クリックしたら
		{
			box.SetColor(GetColor(0, 255, 0));

			is_click_mouse = true;//クリックしていたらtrue
		}
		else
		{
			is_click_mouse = false;//クリックしていたらfalse
		}
	}
	else
	{
		box.SetColor(GetColor(0, 0, 255));

		is_hit_mouse = false;//マウスと当たっていたらfalse
	}
}

void Fild::Draw(bool draw)
{
	//草原
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

	//荒地
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


	//自拠点
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