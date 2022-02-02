#pragma once
#include "DxLib.h"

#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Main/Collision.h"
#include "diploidInput/DiploidEngineInput.h"
#include "data/sim_data/sim_define.h"

class Fild
{
private:

	int window_size_x = 1280, window_size_y = 720;
	int mouse_x, mouse_y;//マウス位置
	bool is_hit_mouse;//boxと当たっているかのフラグ
	int is_click_mouse = -1;//boxと当たっているときにクリックしているかのフラグ

	bool collision_active_flag = true;//当たり判定を行うかどうかのフラグ(treuで行う)

	float on_hit_color_scale = 0.8f;//boxとマウスが当たっていないときの色の暗さ(1.0fで100%)

	int box_size_x, box_size_y;//当たり判定用のBOXの大きさ(仮)
	int bright_red, bright_green, bright_blue;//画像の輝度の数値


	int isBuilding = 0;//拠点があるかないかのフラグ(0でなし、1で自拠点、2で敵拠点、3で友好拠点)
	int isTerrain = 0;//地形の種類(0で草原、1で荒地、2で山岳)
	int isFild = 0;//支配領域の種類(0で無所属、1で自領、2で敵領、3で友好領)

	DiploidBoxV2 box;
	DiploidImageV2 grass_terrain, rock_terrain, mountain_terrain;
	DiploidImageV2 my_building;
	DiploidCollision collision;

public:
	void LoadGrassTerrain(int grass_terrain_handl);//草原画像ハンドル読み込み
	void LoadRockTerrain(int rock_terrain_handl);//荒地画像ハンドル読み込み
	void LoadMountainTerrain(int mountain_terrain_handl);//山岳画像ハンドル読み込み
	void LoadMyBuilding(int my_building_handl);//自拠点画像ハンドル読み込み


	void Load(int grass_terrain_handl, int rock_terrain_handl, int mountain_terrain_handl, int my_building_handl);//一つの画像から読み込む
	void Load();//オブジェクト別に画像を読み込む
	void Init(VECTOR pos, float scale = 1.0f);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);


	void SetMainCameraFlag(bool flag);//メインカメラを設定します。
	void SetWindowSize(int x, int y);//描画する画面の大きさを設定します。(画面外のオブジェクトは描画されません)
	void SetClick(int flag);

	void SetBuildingType(int new_building_type);//新しい拠点のタイプを設定します。(0でなし、1で自拠点、2で敵拠点、3で友好拠点)
	void SetTerrainType(int new_terring_type);//新しい地形のタイプを設定します。(0で草原、1で荒地)
	void SetFildType(int new_fild_type);//新しい支配領域のタイプを設定します。(0で無所属、1で自領、2で敵領、3で友好領)

	void SetCollisionActiveFlag(bool new_flag);//マウスとの当たり判定をするかのフラグを変更します。(trueで当たり判定を行う)

	int GetBuildingType();//現在の拠点のタイプを取得します。
	int GetTerrainType();//現在の地形のタイプを取得します。
	int GetFildType();//現在の支配領域のタイプを取得します。

	VECTOR GetPosition();//当たり判定で使われているBOXの左上の座標を取得します。

	int GetClick();//その地形をクリックしたかどうかのフラグを取得します。(trueでクリックした)
	bool GetHit();
	bool GetCollisionActiveFlag();//現在の当たり判定が有効かどうかのフラグを取得します。(trueで当たり判定が有効)

	int GetSizeX();//当たり判定に使っているBOXのX方向の大きさを取得します。(バグ)
	int GetSizeY();//当たり判定に使っているBOXのY方向の大きさを取得します。(バグ)

	bool GetMainCameraFlag();
};