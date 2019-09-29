//�����ł��B
#pragma once
#include <vector>
#include "DxLib.h"//Dxlib�{��
#include "diploidApp\DiploidEngineMain.h"//�S������(�K���Ă�)
#include "diploidObject\DiploidEngineObject.h"//�~��l�p��摜�≹�ȂǁA�I�u�W�F�N�g�S��
#include "system\DiploidEngineMath.h"//���w���֘A(DxLib��������C++�W���������͂��̑��̐��w���C�u�����̎g�p�𐄏��B�Ƃ��������g�Ȃ�)

#include "diploid3D/diploidPanel.h"

//�X�^���h�A���[���֘A
#include "diploidStandalone\standalone.h"//������

//�Q�[���f�[�^�֘A
#include "data/number.h"

//UI
#include "data/game_data/UI/command_ui.h"
#include "data/game_data/UI/season_panel.h"
#include "data/game_data/UI/status_bar.h"

#include "data/game_data/EXPLORE/explore_test_map.h"

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidObject mouse_point;//�}�E�X�J�[�\���̔���p

	CommandUI command_ui;//�R�}���hUI
	SeasonPanel season_panel;//�G�߃p�l��
	StatusBar status_bar;//�X�e�[�^�X�o�[

	Explore_TestMap test_map;

	//���v
	DiploidObject test_clock_back;
	DiploidObject test_clock_hour_hand;
	DiploidObject test_clock_minute_hand;
	DiploidObject test_clock_second_hand;
	int timer = 0;
	int hour = 0;
	int minute = 0;
	int second = 0;


public:
	void FileCreate();//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
	void Load();//�Q�[���N�����Ƀ��[�h����f�[�^
	void Init();//�ŏ��Ɉ�񂾂��������������������L�q�B	
	void LoadUpdata();//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�������B��x�������[�h���������ꍇ��DiploidSystem���g���Ă��������B)
	void Updata();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��
	void End();//engine�I���O�����B
};