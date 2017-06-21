#include "Objet_Base.h"

class Status : public ObjectBase
{
private:

public:

	//基本ステータス
	int strength;			//筋力			1
	int	agility;			//素早さ		2
	int dexterity;			//器用さ		3
	int constitution;		//体質			4
	int power;				//精神力		5
	int intelligence;		//知性			6
	int size;				//体格			7
	int appearance;			//外見(清潔さ)	8
	int looks;				//見かけ		9
	int education;			//教育			10
	int fear;				//恐怖心		11
	int luck;				//運			12
	int idea;				//アイディア	13
	int knowledge;			//知識			14
	int vitality;			//疲労度		15
	int hitpoint;			//体力			16
	int age;				//年齢			17
	int sex;				//性別			18
	int sanity;				//正気度		19
	int faction;			//善悪度		20
	int magicpoint;			//MP			21
	int height;				//身長			22

	//拡張ステータス
	int satiety;			//満腹度		23
	int leg_vitality;		//脚疲労度		24
	int arm_vitality;		//腕疲労度		25
	int body_vitality;		//胴疲労度		26
	int head_vitality;		//頭疲労度		27
	int right_eye_state;	//右目の状態	28
	int left_eye_state;		//左目の状態	29
	int righ_hand_state;	//右手の状態	30
	int left_hand_state;	//左手の状態	31
	int right_leg_state;	//右脚の状態	32
	int left_leg_state;		//左脚の状態	33
	int poison_state;		//毒の状態		34
	int paralysis_state;	//麻痺の状態	35
	int confusion_state;	//混乱の状態	36
	int silence_state;		//沈黙の状態	37
	int flames_state;		//炎上の状態	38
	int wet_state;			//濡れの状態	39
	int drying_state;		//乾燥の状態	40
	int kindness;			//やさしさ		41
	int emotion;			//感情の豊かさ	42
	int sharpness;			//鋭さ			43
	int courage;			//器量			44
	int hotness;			//感情的暑さ	45
	int body_temperature;	//体温			46

};