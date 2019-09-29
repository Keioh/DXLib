/*---------------------------------------------------------*/
/*--------------���R�}���h�̂��ׂĂ�������-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"


//���C���[�ԍ���DIPLOID_LAYER_00
class InformationCommand
{
private:
	DiploidObject back_image;//�w�i�摜
	int image_size_x = 440, image_size_y = 580;

	//�e�X�e�[�^�X
	VECTOR vitality_position;//�\���ʒu
	int vitality_max = 18;//�����͂̍ő�l
	int vitality = 18;//���݂̐�����

	VECTOR stamina_position;//�\���ʒu
	int stamina_max = 10;//���v�͂̍ő�l
	int stamina = 10;//���݂̎��v��

	VECTOR strength_position;//�\���ʒu
	int strength_max = 4;//�ؗ͂̍ő�l
	int strength = 4;//���݂̋ؗ�

	VECTOR agility_position;//�\���ʒu
	int agility_max = 8;//�q���͂̍ő�l
	int agility = 8;//���݂̕q����

	VECTOR spirit_position;//�\���ʒu
	int spirit_max = 5;//���_�͂̍ő�
	int spirit = 5;//���݂̐��_��

	VECTOR willpower_position;//�\���ʒu
	int willpower_max = 2;//�ӎu�͂̍ő�
	int willpower = 2;//���݂̈ӎu��

	VECTOR fortune_position;//�\���ʒu
	int fortune_max = 5;//�K�^�͂̍ő�
	int fortune = 5;//���݂̍K�^��

	VECTOR madness_position;//�\���ʒu
	int madness_max = 10;//���C�͂̍ő�
	int madness = 10;//���݂̋��C��


	int health_max;//HP(�̗�)�̍ő�l
	int health = vitality_max + ((stamina_max + strength_max) / 2);//HP(�̗�)�̌��ݒl

public:
	void Load();
	void Init(VECTOR position);
	void Update(bool ui_flag, int command_type, DiploidEngineImpact& impact);
	void StatusUpdate();//�X�e�[�^�X�̐��l�v�Z(�R�}���h��\�����ɂ��������s����悤�ɐ錾���邱��)
	void Draw(bool ui_flag, int command_type, bool draw = true);


	int GetMaxHealthPoint();//HP(�̗�)�̍ő�l�𓾂܂��B
	int GetHealthPoint();//���݂�HP(�̗�)�𓾂܂��B
	int HealthPointCalculation();//�����́A���v�́A�ؗ͂���ő�HP(�̗�)���Z�o���܂��B
	void SetHealthPoint(int val);//���݂�HP(�̗�)���Z�b�g���܂��B

	int GetMaxVitality();//�����͂̍ő�l�𓾂�
	int GetVitality();//���݂̐����͂𓾂�
	void SetMaxVitality(int val);//�����͂̍ő�l���Z�b�g����
	void SetVitality(int val);//���݂̐����͂��Z�b�g����

	int GetMaxStamina();//���v�͂̍ő�l�𓾂�
	int GetStamina();//���݂̎��v�͂𓾂�
	void SetMaxStamina(int val);//���v�͂̍ő�l���Z�b�g����
	void SetStamina(int val);//���݂̎��v�͂��Z�b�g����

	int GetMaxStrength();//�ؗ͂̍ő�l�𓾂�
	int GetStrength();//���݂̋ؗ͂𓾂�
	void SetMaxStrength(int val);//�ؗ͂̍ő�l���Z�b�g����
	void SetStrength(int val);//���݂̋ؗ͂��Z�b�g����

	int GetMaxAgility();//�q���͂̍ő�l�𓾂�
	int GetAgility();//���݂̕q���͂𓾂�
	void SetMaxAgility(int val);//�q���͂̍ő�l���Z�b�g����
	void SetAgility(int val);//���݂̕q���͂��Z�b�g����

	int GetMaxSpirit();//���_�͂̍ő�l�𓾂�
	int GetSpirit();//���݂̐��_�͂𓾂�
	void SetMaxSpirit(int val);//���_�͂̍ő�l���Z�b�g����
	void SetSpirit(int val);//���݂̐��_�͂��Z�b�g����

	int GetMaxWillpower();//�ӎu�͂̍ő�l�𓾂�
	int GetWillpower();//���݂̈ӎu�͂𓾂�
	void SetMaxWillpower(int val);//�ӎu�͂̍ő�l���Z�b�g����
	void SetWillpower(int val);//���݂̈ӎu�͂��Z�b�g����

	int GetMaxFortune();//�K�^�͂̍ő�l�𓾂�
	int GetFortune();//���݂̍K�^�͂𓾂�
	void SetMaxFortune(int val);//�K�^�͂̍ő�l���Z�b�g����
	void SetFortune(int val);//���݂̍K�^�͂��Z�b�g����

	int GetMaxMadness();//���C�͂̍ő�l�𓾂�
	int GetMadness();//���݂̋��C�͂𓾂�
	void SetMaxMadness(int val);//���C�͂̍ő�l���Z�b�g����
	void SetMadness(int val);//���݂̋��C�͂��Z�b�g����

};