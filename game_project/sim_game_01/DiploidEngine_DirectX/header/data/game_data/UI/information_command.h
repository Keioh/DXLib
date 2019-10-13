/*---------------------------------------------------------*/
/*--------------���R�}���h�̂��ׂĂ�������-------------*/
/*---------------------------------------------------------*/
//��{��command_ui�̂ق��ŏ���

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
	int vitality_max = 8;//�����͂̍ő�l
	int vitality = 8;//���݂̐�����
	int vitality_level = 0;//���x��
	int vitality_exp = 0;//���݂̌o��t
	int vitality_need_exp = 100;//�K�v�o���l

	VECTOR stamina_position;//�\���ʒu
	int stamina_max = 6;//���v�͂̍ő�l
	int stamina = 6;//���݂̎��v��
	int stamina_level = 0;
	int stamina_exp = 0;
	int stamina_need_exp = 100;//�K�v�o���l

	VECTOR strength_position;//�\���ʒu
	int strength_max = 4;//�ؗ͂̍ő�l
	int strength = 4;//���݂̋ؗ�
	int strength_level = 0;
	int strength_exp = 0;
	int strength_need_exp = 100;//�K�v�o���l

	VECTOR agility_position;//�\���ʒu
	int agility_max = 8;//�q���͂̍ő�l
	int agility = 8;//���݂̕q����
	int agility_level = 0;
	int agility_exp = 0;
	int agility_need_exp = 100;//�K�v�o���l

	VECTOR spirit_position;//�\���ʒu
	int spirit_max = 5;//���_�͂̍ő�
	int spirit = 5;//���݂̐��_��
	int spirit_level = 0;
	int spirit_exp = 0;
	int spirit_need_exp = 100;//�K�v�o���l

	VECTOR willpower_position;//�\���ʒu
	int willpower_max = 2;//�ӎu�͂̍ő�
	int willpower = 2;//���݂̈ӎu��
	int willpower_level = 0;
	int willpower_exp = 0;
	int willpower_need_exp = 100;//�K�v�o���l

	VECTOR fortune_position;//�\���ʒu
	int fortune_max = 5;//�K�^�͂̍ő�
	int fortune = 5;//���݂̍K�^��
	int fortune_level = 0;
	int fortune_exp = 0;
	int fortune_need_exp = 100;//�K�v�o���l

	VECTOR madness_position;//�\���ʒu
	int madness_max = 10;//���C�͂̍ő�
	int madness = 10;//���݂̋��C��
	int madness_level = 0;
	int madness_exp = 0;
	int madness_need_exp = 100;//�K�v�o���l


	int hp_max;//HP�̍ő�l
	int hp = vitality + ((stamina + strength) / 2);//HP�̌��ݒl
	int mp_max;//MP�̍ő�l
	int mp = spirit + ((stamina + willpower) / 2);//MP�̌��ݒl
	int sp_max;//SP�̍ő�l
	int sp = stamina + ((vitality + agility) / 2);//SP�̌��ݒl

	float exp_scale = 0.6f;
	int character_level = 1;
	VECTOR character_level_positin;

public:
	void Load();
	void Init(VECTOR position);
	void Update(bool ui_flag, int command_type, DiploidEngineImpact& impact);
	void StatusUpdate();//�X�e�[�^�X�̐��l�v�Z(�R�}���h��\�����ɂ��������s����悤�ɐ錾���邱��)(status_bar���ŏ���)
	void Draw(bool ui_flag, int command_type, bool draw = true);

	void CharacterLevelCalculation();
	int GetCharacterLevel();//�L�����N�^�[LV�𓾂܂�

	int GetMaxHealthPoint();//HP�̍ő�l�𓾂܂��B
	int GetHealthPoint();//���݂�HP�𓾂܂��B
	int HealthPointCalculation();//�����́A���v�́A�ؗ͂���ő�HP���Z�o���܂��B
	void SetHealthPoint(int val);//���݂�HP���Z�b�g���܂��B

	int GetMaxMagicPoint();//MP�̍ő�l�𓾂܂��B
	int GetMagicPoint();//���݂�MP�𓾂܂��B
	int MagicPointCalculation();//���_�́A���v�́A�ӎu�͂���ő�MP���Z�o���܂��B
	void SetMagicPoint(int val);//���݂�MP���Z�b�g���܂��B

	int GetMaxStaminaPoint();//SP�̍ő�l�𓾂܂��B
	int GetStaminaPoint();//���݂�SP�𓾂܂��B
	int StaminaPointCalculation();//���_�́A���v�́A�ӎu�͂���ő�MP���Z�o���܂��B
	void SetStaminaPoint(int val);//���݂�SP���Z�b�g���܂��B



	int GetMaxVitality();//�����͂̍ő�l�𓾂�
	int GetVitality();//���݂̐����͂𓾂�
	int GetVitalityLv();//���݂̐�����LV�𓾂�
	int GetVitalityEXP();//���݂̓��Ă���o���l���擾����B
	int GetVitalityNeedEXP();//���݂�LV�̕K�v�Œ�o���l���擾����B
	int VitalityCalculation();
	void SetMaxVitality(int val);//�����͂̍ő�l���Z�b�g����
	void SetVitality(int val);//���݂̐����͂��Z�b�g����
	void SetVitalityEXP(int val);

	int GetMaxStamina();//���v�͂̍ő�l�𓾂�
	int GetStamina();//���݂̎��v�͂𓾂�
	int GetStaminaLv();//���݂̎��v��LV�𓾂�
	int GetStaminaEXP();//���݂̓��Ă���o���l���擾����B
	int GetStaminaNeedEXP();//���݂�LV�̕K�v�Œ�o���l���擾����B
	int StaminaCalculation();
	void SetMaxStamina(int val);//���v�͂̍ő�l���Z�b�g����
	void SetStamina(int val);//���݂̎��v�͂��Z�b�g����
	void SetStaminaEXP(int val);
	void AddStaminaEXP(int val);

	int GetMaxStrength();//�ؗ͂̍ő�l�𓾂�
	int GetStrength();//���݂̋ؗ͂𓾂�
	int GetStrengthLv();//���݂̋ؗ�LV�𓾂�
	int GetStrengthEXP();//���݂̓��Ă���o���l���擾����B
	int GetStrengthNeedEXP();//���݂�LV�̕K�v�Œ�o���l���擾����B
	int StrengthCalculation();
	void SetMaxStrength(int val);//�ؗ͂̍ő�l���Z�b�g����
	void SetStrength(int val);//���݂̋ؗ͂��Z�b�g����
	void SetStrengthEXP(int val);

	int GetMaxAgility();//�q���͂̍ő�l�𓾂�
	int GetAgility();//���݂̕q���͂𓾂�
	int GetAgilityLv();//���݂̋ؗ�LV�𓾂�
	int GetAgilityEXP();//���݂̓��Ă���o���l���擾����B
	int GetAgilityNeedEXP();//���݂�LV�̕K�v�Œ�o���l���擾����B
	int AgilityCalculation();
	void SetMaxAgility(int val);//�q���͂̍ő�l���Z�b�g����
	void SetAgility(int val);//���݂̕q���͂��Z�b�g����
	void SetAgilityEXP(int val);
	void AddAgilityEXP(int val);

	int GetMaxSpirit();//���_�͂̍ő�l�𓾂�
	int GetSpirit();//���݂̐��_�͂𓾂�
	int GetSpiritLv();//���݂̋ؗ�LV�𓾂�
	int GetSpiritEXP();//���݂̓��Ă���o���l���擾����B
	int GetSpiritNeedEXP();//���݂�LV�̕K�v�Œ�o���l���擾����B
	int SpiritCalculation();
	void SetMaxSpirit(int val);//���_�͂̍ő�l���Z�b�g����
	void SetSpirit(int val);//���݂̐��_�͂��Z�b�g����
	void SetSpiritEXP(int val);

	int GetMaxWillpower();//�ӎu�͂̍ő�l�𓾂�
	int GetWillpower();//���݂̈ӎu�͂𓾂�
	int GetWillpowerLv();//���݂̋ؗ�LV�𓾂�
	int GetWillpowerEXP();//���݂̓��Ă���o���l���擾����B
	int GetWillpowerNeedEXP();//���݂�LV�̕K�v�Œ�o���l���擾����B
	int WillpowerCalculation();
	void SetMaxWillpower(int val);//�ӎu�͂̍ő�l���Z�b�g����
	void SetWillpower(int val);//���݂̈ӎu�͂��Z�b�g����
	void SetWillpowerEXP(int val);

	int GetMaxFortune();//�K�^�͂̍ő�l�𓾂�
	int GetFortune();//���݂̍K�^�͂𓾂�
	int GetFortuneLv();//���݂̋ؗ�LV�𓾂�
	int GetFortuneEXP();//���݂̓��Ă���o���l���擾����B
	int GetFortuneNeedEXP();//���݂�LV�̕K�v�Œ�o���l���擾����B
	int FortuneCalculation();
	void SetMaxFortune(int val);//�K�^�͂̍ő�l���Z�b�g����
	void SetFortune(int val);//���݂̍K�^�͂��Z�b�g����
	void SetFortuneEXP(int val);

	int GetMaxMadness();//���C�͂̍ő�l�𓾂�
	int GetMadness();//���݂̋��C�͂𓾂�
	int GetMadnessLv();//���݂̋ؗ�LV�𓾂�
	int GetMadnessEXP();//���݂̓��Ă���o���l���擾����B
	int GetMadnessNeedEXP();//���݂�LV�̕K�v�Œ�o���l���擾����B
	int MadnessCalculation();
	void SetMaxMadness(int val);//���C�͂̍ő�l���Z�b�g����
	void SetMadness(int val);//���݂̋��C�͂��Z�b�g����
	void SetMadnessEXP(int val);

};