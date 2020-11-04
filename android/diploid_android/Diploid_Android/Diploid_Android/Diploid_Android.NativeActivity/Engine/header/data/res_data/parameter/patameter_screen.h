#pragma once
#include "data/res_data/game_define.h"
#include "DxLib.h"
#include "data/res_data/parameter/base_parameter_ui.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidScreen/DiploidEngineAndroidScreen.h"

#include  "data/res_data/parameter/character_data.h"

class ParameterScreen
{
private:
	//������w�i(��)
	DiploidEngineAndroidScreen android_screen;
	DiploidBoxV2 ui_box;

	//�L�����N�^�[�̏���ۑ�����p
	CharacterData character_data;

	//�v���C���[���֘A
	BaseParameterUI profession_button;//�E��
	BaseParameterUI birth_button;//���܂�
	BaseParameterUI sex_button;//����
	BaseParameterUI age_button;//�N��

	//�p�����[�^�l�֘A
	BaseParameterUI str_button;
	BaseParameterUI dex_button;
	BaseParameterUI con_button;
	BaseParameterUI int_button;
	BaseParameterUI luk_button;
	BaseParameterUI agi_button;
	BaseParameterUI res_button;
	BaseParameterUI atk_button;
	BaseParameterUI cri_button;
	BaseParameterUI def_button;
	BaseParameterUI san_button;
	BaseParameterUI will_button;

	VECTOR parameter_pos = { 0, (128 + 64 + 20) * 2, 0 };
	VECTOR player_info_pos = { 0, 0, 0 };

	int profession = PROFESSUON_NONE;
	int birth = BIRTH_NONE;
	int sex = SEX_NONE;

	//職業、生まれ、性別、年齢から基礎ステータスと使用可能ポイントを決める。
	void parameter_update();

	//�{�^���I�t�����֐�
	void age_button_update();
	void sex_button_update();
	void birth_button_update();
	void profession_button_update();
	void str_button_update();//�������牺�̓p�����[�^�֘A
	void dex_button_update();
	void con_button_update();
	void int_button_update();
	void luk_button_update();
	void agi_button_update();
	void res_button_update();
	void atk_button_update();
	void cri_button_update();
	void def_button_update();
	void san_button_update();
	void will_button_update();

	void profession_update();//�E�Ɛ��l�̃A�b�v�f�[�g
	void profession_button_draw(bool draw, bool debug);//�E�Ƃ̕\��

	void birth_update();//���܂ꐔ�l�̃A�b�v�f�[�g
	void birth_button_draw(bool draw, bool debug);//���܂�̕\��

	void sex_update();//���ʐ��l�̃A�b�v�f�[�g
	void sex_button_draw(bool draw, bool debug);//���ʂ̕\��

	void ui_draw(bool draw);//使用可能なポイントなどのUI描画
	void info_ui_draw(bool draw);//パラメータの説明UIの描画


public:
	void Load();
	void Init();
	void Update(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	int GetProfessionValue();//�I�𒆂̐E�Ƃ̒l��Ԃ��B
	int GetBirthValue();//�I�𒆂̐��܂�̒l��Ԃ��B

	CharacterData GetCharacterData();//�L�����N�^�[�̃p�����[�^�l�Ȃǂ̏���Ԃ��B
	CharacterData* GetCharacterDataPtr();//�L�����N�^�[�f�[�^�ւ̃|�C���^��Ԃ��B(�g�p�񐄏�)
};