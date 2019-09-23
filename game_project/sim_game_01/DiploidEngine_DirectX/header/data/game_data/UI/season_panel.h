/*---------------------------------------------------------*/
/*--------------�G�߃p�l���̂��ׂĂ�������-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"


//���C���[�ԍ���DIPLOID_LAYER_00
class SeasonPanel
{
private:
	DiploidObject season_panel;//�G�߃p�l��
	DiploidObject rainy_season;//�J�G����
	DiploidObject summer_season;//�ċG����
	DiploidObject spring_season;//�t�G����
	DiploidObject winter_season;//�~�G����

	//������(1~24���܂�)
	DiploidObject days1;
	DiploidObject days2;
	DiploidObject days3;
	DiploidObject days4;
	DiploidObject days5;
	DiploidObject days6;
	DiploidObject days7;
	DiploidObject days8;
	DiploidObject days9;
	DiploidObject days10;
	DiploidObject days11;
	DiploidObject days12;
	DiploidObject days13;
	DiploidObject days14;
	DiploidObject days15;
	DiploidObject days16;
	DiploidObject days17;
	DiploidObject days18;
	DiploidObject days19;
	DiploidObject days20;
	DiploidObject days21;
	DiploidObject days22;
	DiploidObject days23;
	DiploidObject days24;

	void _Days_Season_Count();//�G�߂Ɠ��ɂ��̃t���[�Ǘ�


	int days = 1;//���ɂ��̃J�E���g(�P����n�܂�)
	int season = SPRING_SEASON;//�G�߂̃J�E���g(�t�G�������l)

	int count;

public:
	SeasonPanel() {};
	~SeasonPanel() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

	int GetDays();//���݂̓��ɂ��𓾂�B
	int GetSeason();//���݂̋G�߂𓾂�B

	void NextDays();//���݂̓��ɂ�������i�߂�B
	void NextSeason();//���݂̋G�߂���G�ߐi�߂�B

	void SetDays(int set_day);//���ɂ���ݒ肷��B
	void SetSeason(int set_season);//�G�߂�ݒ肷��B

};