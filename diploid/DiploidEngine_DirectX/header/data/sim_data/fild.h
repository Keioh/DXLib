#pragma once
#include "DxLib.h"

#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Main/Collision.h"
#include "diploidInput/DiploidEngineInput.h"

class Fild
{
private:

	int mouse_x, mouse_y;//マウス位置
	bool is_hit_mouse;//boxと当たっているかのフラグ
	bool is_click_mouse;//boxと当たっているときにクリックしているかのフラグ

	float on_hit_color_scale = 0.9f;//boxとマウスが当たっていないときの色の暗さ(1.0fで100%)

	int isBuilding = 0;//拠点があるかないかのフラグ(0でなし、1で自拠点、2で敵拠点、3で友好拠点)
	int isTerrain = 0;//地形の種類(0で草原、1で荒地)
	int isFild = 0;//支配領域の種類(0で無所属、1で自領、2で敵領、3で友好領)

	DiploidBoxV2 box;
	DiploidImageV2 grass_terrain, rock_terrain;
	DiploidImageV2 my_building;
	DiploidCollision collision;

public:
	void Load();
	void Init(VECTOR pos, float scale = 1.0f);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true);

	void SetBuildingType(int new_building_type);//新しい拠点のタイプを設定します。(0でなし、1で自拠点、2で敵拠点、3で友好拠点)
	void SetTerrainType(int new_terring_type);//新しい地形のタイプを設定します。(0で草原、1で荒地)

	int GetBuildingType();//現在の拠点のタイプを取得します。
	int GetTerrainType();//現在の地形のタイプを取得します。

	int GetSizeX();
	int GetSizeY();

};