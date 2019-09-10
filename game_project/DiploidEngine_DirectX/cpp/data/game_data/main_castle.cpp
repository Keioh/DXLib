#include "data/game_data/main_castle.h"

MyCastle::MyCastle()
{

}

void MyCastle::Load()
{
	//JSONファイル読み込み
	json.file.LoadJSON("json/base_data/castle/my_castle.json");
	
	//JSON値の代入
	population = json.file.GetJSON()["population"];
	defense = json.file.GetJSON()["defense"];
	money = json.file.GetJSON()["money"];
	size = json.file.GetJSON()["size"];
}

void MyCastle::Inti(VECTOR position, float radius)
{
	//拠点選択の円
	ui.OneClickButtonCIRCLE_Init(position, radius + size, "my_castle");
	
	//拠点の背景色
	back_color_circle_object.circle.Init(position, radius + size);
	back_color_circle_object.circle.name_tag = "my_castle_back_color";
	back_color_circle_object.circle.fill = TRUE;
	back_color_circle_object.circle.color = GetColor(200, 200, 200);

	//拠点の防壁
	defense_circle_object.circle.Init(position, radius + size);
	defense_circle_object.circle.color = GetColor(0, 0, 0);
	defense_circle_object.circle.name_tag = "my_castle_defense_wall";
	defense_circle_object.circle.thickness = defense;//JSON値を代入。
	defense_circle_object.circle.center_position_draw_flag = false;
}

void MyCastle::Push(DiploidEngineImpact& impact)
{
	ui.OneClickButtonCIRCLE_Push(impact);//uiオブジェクトのプッシュ
}

void MyCastle::Updata(DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	if (ui.OneClickButtonCIRCLE_Update(MOUSE_INPUT_RIGHT,impact, input) == true)//拠点を右クリックしたら
	{
		//何かがおこる
	}

	back_color_circle_object.circle.Update();//拠点背景色のアップデート
	defense_circle_object.circle.Update();//拠点防壁のアップデート
}

void MyCastle::Draw(bool wire, bool debug)
{
	back_color_circle_object.circle.Draw();//拠点背景色を描写
	defense_circle_object.circle.Draw();//拠点防壁を描写

	//デバッグ時情報
	if (debug == true)
	{	
		DrawFormatString(0, 0, GetColor(0, 0, 0), "population = %d", population);
		DrawFormatString(0, 20, GetColor(0, 0, 0), "defense = %d", defense);
		DrawFormatString(0, 40, GetColor(0, 0, 0), "money = %d", money);
		DrawFormatString(0, 60, GetColor(0, 0, 0), "size = %d", size);
		
		ui.OneClickButtonCIRCLE_Draw();
	}
}