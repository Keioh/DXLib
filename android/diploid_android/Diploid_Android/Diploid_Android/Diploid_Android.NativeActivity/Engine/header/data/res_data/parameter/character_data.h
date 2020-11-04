#pragma  once
#include "DxLib.h"
#include <string>

//�L�����N�^�[�̃f�[�^(�p�����[�^�l�Ȃ�)
class CharacterData
{
private:

public:
	//キャラクターの名前
	std::string character_name;
	
	int parameter_points;//ステータスに割り振る為のポイント
	int skill_points;//スキルへ割り振る為のポイント

	//ステータス
	int parameter_str;
	int parameter_dex;
	int parameter_con;
	int parameter_int;
	int parameter_luk;
	int parameter_agi;
	int parameter_res;
	int parameter_atk;
	int parameter_cri;
	int parameter_def;
	int parameter_san;
	int parameter_will;

	int parameter_profession;//職業
	int parameter_sex;//性別
	int parameter_age;//年齢
	int parameter_birth;//生まれ

	//クラス(0から始まる)
	int parameter_class_0;
	int parameter_class_1;
	int parameter_class_2;
	int parameter_class_3;
	int parameter_class_4;
	int parameter_class_5;
	int parameter_class_6;
	int parameter_class_7;
	int parameter_class_8;
	int parameter_class_9;
	int parameter_class_10;
	int parameter_class_11;


	int GetParameterAllPoints();

};