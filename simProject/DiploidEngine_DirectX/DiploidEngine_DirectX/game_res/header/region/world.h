#pragma once
#include "diploidObject\DiploidEngineObject.h"
#include "diploidObject\DiploidEngineTag.h"

#include "region\region.h"
#include "lule\world_map_lule.h"


class World
{
private:

	WorldMapLule world_map_lule;

	DiploidObject back_map;

	Region region_01;
	Region region_02;
	Region region_03;
	Region region_04;
	Region region_05;
	Region region_06;
	Region region_07;
	Region region_08;
	Region region_09;
	Region region_10;
	Region region_11;
	Region region_12;

	void InputUpadata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);//�C���v�b�g�A�b�v�f�[�g�܂Ƃ�
	bool TerritoryMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//�̓y�}�b�v��\�����邽�߂̏���
	bool PopulationMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//�l���}�b�v��\�����邽�߂̏���
	bool NetworkMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//�l�b�g���[�N�}�b�v��\�����邽�߂̏���
	bool ProductivityMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//���Y�̓}�b�v��\�����邽�߂̏���
	bool EconomicsMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//�o�ϗ̓}�b�v��\�����邽�߂̏���

	bool NormalMap(DiploidEngineLayer& layer, DiploidEngineInput& input);//����}�b�v��\�����邽�߂̏���

	void SetTerritory();//�e�n��̗̓y��L��Ԃ��Z�b�g
	void SetPopulation();//�e�n��̐l�����Z�b�g
	void SetNetworkLevel();//�e�n��̃l�b�g���[�N���x�����Z�b�g
	void SetProductivity();//�e�n��̐��Y�͂��Z�b�g
	void SetEconomics();//�e�n��̌o�ϗ͂��Z�b�g


public:


	void Load();//���ׂĂ�ǂݍ���
	void Init(VECTOR position);//�K���ǂ݂���

	void Push(DiploidEngineImpact& impact, DiploidEngineLayer& layer);

	void Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);

	void Draw();

	//DiploidImage GetImage();//image����Ԃ��܂��B

};