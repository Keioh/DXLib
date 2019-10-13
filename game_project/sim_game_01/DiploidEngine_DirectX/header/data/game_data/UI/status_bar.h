/*---------------------------------------------------------*/
/*--------------ステータスバーのすべてがここに-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"
#include "data/game_data/UI/information_command.h"

class StatusBar
{
private:

	DiploidObject status_bar;//ステータスバー

	VECTOR health_position;//HP文字の位置
	VECTOR mana_position;//MP文字の位置
	VECTOR stamina_position;//SP文字の位置

	int hp_buffer = 0;
	int mp_buffer = 0;
	int sp_buffer = 0;

public:
	StatusBar() {};
	~StatusBar() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);
	void StatusUpdate(InformationCommand& info_command);
	void StatusDraw(InformationCommand& info_command);

	int SubHP(int val, InformationCommand& info_command);//HPの現在値を減らす
	int AddHP(int val, InformationCommand& info_command);//HPの現在値を増やす
	//int GetHP();

	int SubMP(int val, InformationCommand& info_command);//MPの現在値を減らす
	int AddMP(int val, InformationCommand& info_command);//MPの現在値を増やす
	//int GetMP();

	int SubSP(int val, InformationCommand& info_command);//SPの現在値を減らす
	int AddSP(int val, InformationCommand& info_command);//SPの現在値を増やす
	//int GetSP();
};