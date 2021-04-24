#pragma once
#include "DxLib.h"
//#include "diploidApp\DiploidEngineApp.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "system/define.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "ver2.0/Objects/DiploidNovelScene.h"
#include "diploidScreen\DiploidEngineScreen.h"


#include "ver2.0/Objects/button/AutoNovel.h"
#include "ver2.0/Objects/button/SkipNovel.h"
#include "ver2.0/Objects/button/OptionNovel.h"
#include "ver2.0/Objects/button/SaveNovel.h"
#include "ver2.0/Objects/button/LoadNovel.h"
#include "ver2.0/Objects/button/QuickLoadNovel.h"
#include "ver2.0/Objects/button/QuickSaveNovel.h"

#include "data/text_data/ja.h"

class GameScene
{
private:
	DiploidScreenGraphics screen_graphics;//���U�C�N�����Ƃ�

	AutoNovel auto_button;//�I�[�g�{�^��
	SkipNovel skip_button;//�X�L�b�v�{�^��
	OptionNovel option_button;//�I�v�V�����{�^��
	SaveNovel save_button;//�Z�[�u�{�^��
	LoadNovel load_button;//���[�h�{�^��
	QuickLoadNovel quick_load_button;//�N�C�b�N���[�h�{�^��
	QuickSaveNovel quick_save_button;//�N�C�b�N�Z�[�u�{�^��


	ja_text jp;//�e�L�X�g�f�[�^

	DiploidBoxV2 box;//�t�F�[�h�pBOX

	DiploidAnimation end_anime;//anime

	DiploidNovelScene novel_scene;

	DiploidImageV2 string_back_wall;//������̌��̍������

	DiploidImageV2 data_back_wall;//���t�̌��̐Ԃ����
	DiploidImageV2 data_test;//test���t
	DiploidImageV2 place_test;//test�ꏊ

	DiploidImageV2 image_00;//�w�i�摜(��)

	SystemData system_data;

	int click = 0;//���݂̃e�L�X�g�ʒu

	bool in_game = false;//�Q�[�����Ȃ̂���flag(true��game��)

	int is_save_or_load = GAME_LOAD;

	//���ߏ����̕ϐ�
	int alpha = 255;
	int alpha_speed = 500;//���ߑ��x

	int box_draw_flag = 0;//0�Ńt�F�[�h�A�E�g�A1�Ńt�F�[�h�A�E�g�����A2�Ńt�F�[�h�C���A3�Ńt�F�[�h�C������

public:
	void Load();

	void Init(DiploidEngineSetting& setting);

	void Updata(DiploidEngineInput& input, DiploidEngineScreen& screen);

	void Draw(DiploidEngineScreen& screen);

	void Reset();//������f�[�^���ŏ�����`�悷��悤�ɐݒ肵�܂��B

	void SetInGameFlag(bool new_flag);//�Q�[�������̃t���O��ύX���܂��B
	bool GetInGameFlag();//�Q�[�������̃t���O���擾���܂�

	void SetOptionButtonFlag(int new_flag);//�I�v�V�����{�^����flag��ύX���܂�
	bool GetOptionButtonFlag();//�I�v�V�����{�^���̏�Ԃ��擾���܂��B

	void SetLoadButtonFlag(int new_flag);//���[�h�{�^����flag��ύX���܂�
	bool GetLoadButtonFlag();//���[�h�{�^���̏�Ԃ��擾���܂��B

	void SetSaveButtonFlag(int new_flag);//�Z�[�u�{�^����flag��ύX���܂�
	bool GetSaveButtonFlag();//�Z�[�u�{�^���̏�Ԃ��擾���܂��B

	void SetSystemData(SystemData data);

	int GetSelectedScene();
};