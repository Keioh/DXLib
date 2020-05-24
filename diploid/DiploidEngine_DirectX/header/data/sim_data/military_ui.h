#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "diploidInput/DiploidEngineInput.h"
#include "ver2.0/Main/Collision.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"

//�R���R�}���h�֘A�̏���
class MilitaryUI
{
private:
	//���C��UI�֘A
	DiploidImageV2 image;
	DiploidBoxV2 box;
	DiploidCollision collision;

	bool hit = false;
	

	//�݈ʑI���֘A
	DiploidImageV2 king_image;
	DiploidSelectedUIV2 king;//��

	DiploidImageV2 duke_image;
	DiploidSelectedUIV2 duke[2];//����

	DiploidImageV2 marquess_one_image;
	DiploidSelectedUIV2 marquess_one;//��݂��̂P
	DiploidSelectedUIV2 marquess_two;//��݂���2

	DiploidImageV2 viscount_one_image;
	DiploidSelectedUIV2 viscount_one;//�q�݂��̂P
	DiploidSelectedUIV2 viscount_two;//�q�݂���2

	DiploidImageV2 baron_one_image;
	DiploidSelectedUIV2 baron_one;//�j�݂��̂P
	DiploidSelectedUIV2 baron_two;//�j�݂���2

public:
	void Load();
	void Init(VECTOR pos, float scale = 1.0f);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	bool GetHit();
};