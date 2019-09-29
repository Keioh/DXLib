/*---------------------------------------------------------*/
/*--------------情報コマンドのすべてがここに-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"


//レイヤー番号はDIPLOID_LAYER_00
class InformationCommand
{
private:
	DiploidObject back_image;//背景画像
	int image_size_x = 440, image_size_y = 580;

	//各ステータス
	VECTOR vitality_position;//表示位置
	int vitality_max = 18;//生命力の最大値
	int vitality = 18;//現在の生命力

	VECTOR stamina_position;//表示位置
	int stamina_max = 10;//持久力の最大値
	int stamina = 10;//現在の持久力

	VECTOR strength_position;//表示位置
	int strength_max = 4;//筋力の最大値
	int strength = 4;//現在の筋力

	VECTOR agility_position;//表示位置
	int agility_max = 8;//敏捷力の最大値
	int agility = 8;//現在の敏捷力

	VECTOR spirit_position;//表示位置
	int spirit_max = 5;//精神力の最大
	int spirit = 5;//現在の精神力

	VECTOR willpower_position;//表示位置
	int willpower_max = 2;//意志力の最大
	int willpower = 2;//現在の意志力

	VECTOR fortune_position;//表示位置
	int fortune_max = 5;//幸運力の最大
	int fortune = 5;//現在の幸運力

	VECTOR madness_position;//表示位置
	int madness_max = 10;//狂気力の最大
	int madness = 10;//現在の狂気力


	int health_max;//HP(体力)の最大値
	int health = vitality_max + ((stamina_max + strength_max) / 2);//HP(体力)の現在値

public:
	void Load();
	void Init(VECTOR position);
	void Update(bool ui_flag, int command_type, DiploidEngineImpact& impact);
	void StatusUpdate();//ステータスの数値計算(コマンド非表示時にも処理を行えるように宣言すること)
	void Draw(bool ui_flag, int command_type, bool draw = true);


	int GetMaxHealthPoint();//HP(体力)の最大値を得ます。
	int GetHealthPoint();//現在のHP(体力)を得ます。
	int HealthPointCalculation();//生命力、持久力、筋力から最大HP(体力)を算出します。
	void SetHealthPoint(int val);//現在のHP(体力)をセットします。

	int GetMaxVitality();//生命力の最大値を得る
	int GetVitality();//現在の生命力を得る
	void SetMaxVitality(int val);//生命力の最大値をセットする
	void SetVitality(int val);//現在の生命力をセットする

	int GetMaxStamina();//持久力の最大値を得る
	int GetStamina();//現在の持久力を得る
	void SetMaxStamina(int val);//持久力の最大値をセットする
	void SetStamina(int val);//現在の持久力をセットする

	int GetMaxStrength();//筋力の最大値を得る
	int GetStrength();//現在の筋力を得る
	void SetMaxStrength(int val);//筋力の最大値をセットする
	void SetStrength(int val);//現在の筋力をセットする

	int GetMaxAgility();//敏捷力の最大値を得る
	int GetAgility();//現在の敏捷力を得る
	void SetMaxAgility(int val);//敏捷力の最大値をセットする
	void SetAgility(int val);//現在の敏捷力をセットする

	int GetMaxSpirit();//精神力の最大値を得る
	int GetSpirit();//現在の精神力を得る
	void SetMaxSpirit(int val);//精神力の最大値をセットする
	void SetSpirit(int val);//現在の精神力をセットする

	int GetMaxWillpower();//意志力の最大値を得る
	int GetWillpower();//現在の意志力を得る
	void SetMaxWillpower(int val);//意志力の最大値をセットする
	void SetWillpower(int val);//現在の意志力をセットする

	int GetMaxFortune();//幸運力の最大値を得る
	int GetFortune();//現在の幸運力を得る
	void SetMaxFortune(int val);//幸運力の最大値をセットする
	void SetFortune(int val);//現在の幸運力をセットする

	int GetMaxMadness();//狂気力の最大値を得る
	int GetMadness();//現在の狂気力を得る
	void SetMaxMadness(int val);//狂気力の最大値をセットする
	void SetMadness(int val);//現在の狂気力をセットする

};