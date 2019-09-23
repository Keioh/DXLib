//�����ł��B
#pragma once
#include <vector>
#include "DxLib.h"//Dxlib�{��
#include "diploidApp\DiploidEngineMain.h"//�S������(�K���Ă�)
#include "diploidObject\DiploidEngineObject.h"//�~��l�p��摜�≹�ȂǁA�I�u�W�F�N�g�S��
#include "system\DiploidEngineMath.h"//���w���֘A(DxLib��������C++�W���������͂��̑��̐��w���C�u�����̎g�p�𐄏��B�Ƃ��������g�Ȃ�)

//�X�^���h�A���[���֘A
#include "diploidStandalone\standalone.h"//������

//�Q�[���f�[�^�֘A
#include "data/number.h"

//UI
#include "data/game_data/UI/command_ui.h"
#include "data/game_data/UI/season_panel.h"


class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidObject mouse_point;//�}�E�X�J�[�\���̔���p

	CommandUI command_ui;//�R�}���hUI
	SeasonPanel season_panel;//�G�߃p�l��

	DiploidObject status_bar;//�X�e�[�^�X�o�[

public:
	void FileCreate();//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
	void Load();//�Q�[���N�����Ƀ��[�h����f�[�^
	void Init();//�ŏ��Ɉ�񂾂��������������������L�q�B	
	void LoadUpdata();//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�������B��x�������[�h���������ꍇ��DiploidSystem���g���Ă��������B)
	void Updata();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��
	void End();//engine�I���O�����B
};