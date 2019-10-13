/*---------------------------------------------------------*/
/*--------------情報コマンドのすべてがここに-------------*/
/*---------------------------------------------------------*/
//基本はcommand_uiのほうで処理

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
	int vitality_max = 8;//生命力の最大値
	int vitality = 8;//現在の生命力
	int vitality_level = 0;//レベル
	int vitality_exp = 0;//現在の経験t
	int vitality_need_exp = 100;//必要経験値

	VECTOR stamina_position;//表示位置
	int stamina_max = 6;//持久力の最大値
	int stamina = 6;//現在の持久力
	int stamina_level = 0;
	int stamina_exp = 0;
	int stamina_need_exp = 100;//必要経験値

	VECTOR strength_position;//表示位置
	int strength_max = 4;//筋力の最大値
	int strength = 4;//現在の筋力
	int strength_level = 0;
	int strength_exp = 0;
	int strength_need_exp = 100;//必要経験値

	VECTOR agility_position;//表示位置
	int agility_max = 8;//敏捷力の最大値
	int agility = 8;//現在の敏捷力
	int agility_level = 0;
	int agility_exp = 0;
	int agility_need_exp = 100;//必要経験値

	VECTOR spirit_position;//表示位置
	int spirit_max = 5;//精神力の最大
	int spirit = 5;//現在の精神力
	int spirit_level = 0;
	int spirit_exp = 0;
	int spirit_need_exp = 100;//必要経験値

	VECTOR willpower_position;//表示位置
	int willpower_max = 2;//意志力の最大
	int willpower = 2;//現在の意志力
	int willpower_level = 0;
	int willpower_exp = 0;
	int willpower_need_exp = 100;//必要経験値

	VECTOR fortune_position;//表示位置
	int fortune_max = 5;//幸運力の最大
	int fortune = 5;//現在の幸運力
	int fortune_level = 0;
	int fortune_exp = 0;
	int fortune_need_exp = 100;//必要経験値

	VECTOR madness_position;//表示位置
	int madness_max = 10;//狂気力の最大
	int madness = 10;//現在の狂気力
	int madness_level = 0;
	int madness_exp = 0;
	int madness_need_exp = 100;//必要経験値


	int hp_max;//HPの最大値
	int hp = vitality + ((stamina + strength) / 2);//HPの現在値
	int mp_max;//MPの最大値
	int mp = spirit + ((stamina + willpower) / 2);//MPの現在値
	int sp_max;//SPの最大値
	int sp = stamina + ((vitality + agility) / 2);//SPの現在値

	float exp_scale = 0.6f;
	int character_level = 1;
	VECTOR character_level_positin;

public:
	void Load();
	void Init(VECTOR position);
	void Update(bool ui_flag, int command_type, DiploidEngineImpact& impact);
	void StatusUpdate();//ステータスの数値計算(コマンド非表示時にも処理を行えるように宣言すること)(status_bar中で処理)
	void Draw(bool ui_flag, int command_type, bool draw = true);

	void CharacterLevelCalculation();
	int GetCharacterLevel();//キャラクターLVを得ます

	int GetMaxHealthPoint();//HPの最大値を得ます。
	int GetHealthPoint();//現在のHPを得ます。
	int HealthPointCalculation();//生命力、持久力、筋力から最大HPを算出します。
	void SetHealthPoint(int val);//現在のHPをセットします。

	int GetMaxMagicPoint();//MPの最大値を得ます。
	int GetMagicPoint();//現在のMPを得ます。
	int MagicPointCalculation();//精神力、持久力、意志力から最大MPを算出します。
	void SetMagicPoint(int val);//現在のMPをセットします。

	int GetMaxStaminaPoint();//SPの最大値を得ます。
	int GetStaminaPoint();//現在のSPを得ます。
	int StaminaPointCalculation();//精神力、持久力、意志力から最大MPを算出します。
	void SetStaminaPoint(int val);//現在のSPをセットします。



	int GetMaxVitality();//生命力の最大値を得る
	int GetVitality();//現在の生命力を得る
	int GetVitalityLv();//現在の生命力LVを得る
	int GetVitalityEXP();//現在の得ている経験値を取得する。
	int GetVitalityNeedEXP();//現在のLVの必要最低経験値を取得する。
	int VitalityCalculation();
	void SetMaxVitality(int val);//生命力の最大値をセットする
	void SetVitality(int val);//現在の生命力をセットする
	void SetVitalityEXP(int val);

	int GetMaxStamina();//持久力の最大値を得る
	int GetStamina();//現在の持久力を得る
	int GetStaminaLv();//現在の持久力LVを得る
	int GetStaminaEXP();//現在の得ている経験値を取得する。
	int GetStaminaNeedEXP();//現在のLVの必要最低経験値を取得する。
	int StaminaCalculation();
	void SetMaxStamina(int val);//持久力の最大値をセットする
	void SetStamina(int val);//現在の持久力をセットする
	void SetStaminaEXP(int val);
	void AddStaminaEXP(int val);

	int GetMaxStrength();//筋力の最大値を得る
	int GetStrength();//現在の筋力を得る
	int GetStrengthLv();//現在の筋力LVを得る
	int GetStrengthEXP();//現在の得ている経験値を取得する。
	int GetStrengthNeedEXP();//現在のLVの必要最低経験値を取得する。
	int StrengthCalculation();
	void SetMaxStrength(int val);//筋力の最大値をセットする
	void SetStrength(int val);//現在の筋力をセットする
	void SetStrengthEXP(int val);

	int GetMaxAgility();//敏捷力の最大値を得る
	int GetAgility();//現在の敏捷力を得る
	int GetAgilityLv();//現在の筋力LVを得る
	int GetAgilityEXP();//現在の得ている経験値を取得する。
	int GetAgilityNeedEXP();//現在のLVの必要最低経験値を取得する。
	int AgilityCalculation();
	void SetMaxAgility(int val);//敏捷力の最大値をセットする
	void SetAgility(int val);//現在の敏捷力をセットする
	void SetAgilityEXP(int val);
	void AddAgilityEXP(int val);

	int GetMaxSpirit();//精神力の最大値を得る
	int GetSpirit();//現在の精神力を得る
	int GetSpiritLv();//現在の筋力LVを得る
	int GetSpiritEXP();//現在の得ている経験値を取得する。
	int GetSpiritNeedEXP();//現在のLVの必要最低経験値を取得する。
	int SpiritCalculation();
	void SetMaxSpirit(int val);//精神力の最大値をセットする
	void SetSpirit(int val);//現在の精神力をセットする
	void SetSpiritEXP(int val);

	int GetMaxWillpower();//意志力の最大値を得る
	int GetWillpower();//現在の意志力を得る
	int GetWillpowerLv();//現在の筋力LVを得る
	int GetWillpowerEXP();//現在の得ている経験値を取得する。
	int GetWillpowerNeedEXP();//現在のLVの必要最低経験値を取得する。
	int WillpowerCalculation();
	void SetMaxWillpower(int val);//意志力の最大値をセットする
	void SetWillpower(int val);//現在の意志力をセットする
	void SetWillpowerEXP(int val);

	int GetMaxFortune();//幸運力の最大値を得る
	int GetFortune();//現在の幸運力を得る
	int GetFortuneLv();//現在の筋力LVを得る
	int GetFortuneEXP();//現在の得ている経験値を取得する。
	int GetFortuneNeedEXP();//現在のLVの必要最低経験値を取得する。
	int FortuneCalculation();
	void SetMaxFortune(int val);//幸運力の最大値をセットする
	void SetFortune(int val);//現在の幸運力をセットする
	void SetFortuneEXP(int val);

	int GetMaxMadness();//狂気力の最大値を得る
	int GetMadness();//現在の狂気力を得る
	int GetMadnessLv();//現在の筋力LVを得る
	int GetMadnessEXP();//現在の得ている経験値を取得する。
	int GetMadnessNeedEXP();//現在のLVの必要最低経験値を取得する。
	int MadnessCalculation();
	void SetMaxMadness(int val);//狂気力の最大値をセットする
	void SetMadness(int val);//現在の狂気力をセットする
	void SetMadnessEXP(int val);

};