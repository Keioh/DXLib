//�����ł��B
#pragma once
#include <string>
#include <list>
#include <memory>
#include <unordered_map>
#include "DxLib.h"//Dxlib�{��
#include "diploidApp\DiploidEngineMain.h"//�S������(�K���Ă�)
#include "diploidObject\DiploidEngineObject.h"//�~��l�p��摜�≹�ȂǁA�I�u�W�F�N�g�S��
#include "system\DiploidEngineMath.h"//���w���֘A(DxLib�������C++�W��������͂��̑��̐��w���C�u�����̎g�p�𐄏�)
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"//��񂾂��f�[�^��ǂݍ��ނ��߂̏����Q

#include "ver2.0/Graphics/DiploidCircleV2.h"//Ver2.0�̉~�N���X
#include "ver2.0/Main/Collision.h"//Ver2.0�̓����蔻�菈��
#include "ver2.0/Main/Camera.h"//Ver2.0��2D�ɂ�����J��������
#include "ver2.0/Graphics/DiploidImageV2.h"//Ver2.0�ɂ�����摜�N���X
#include "ver2.0/Graphics/DiploidBoxV2.h"//Ver2.0�ɂ�����l�p�N���X

#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidTouchUI.h"

#include "diploidScreen/DiploidEngineAndroidScreen.h"//Android�f�o�C�X�̉�ʏ��擾�N���X
#include "diploidObject/DiploidCreator.h"

//�X�^���h�A���[���֘A
#include "diploidStandalone\standalone.h"//������

//�Q�[���f�[�^�֘A
//#include "diploidGraphics/diploidEffect.h"
//#include "data/res_data/parameter/base_parameter_ui.h"
#include "data/res_data/parameter/patameter_screen.h"

using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:	
	DiploidEngineAndroidScreen android_screen;//Android�f�o�C�X�̉�ʏ��
	DiploidEngineInput input;

	ParameterScreen parameter_screen;

	//DiploidCreator<ParameterScreen> parameter_screen;


public:
	void FileCreate();//�Q�[���N�����Ɉ�x�����t�@�C�����鏈���B
	void Load();//�Q�[���N�����Ƀ��[�h����f�[�^
	void Init();//�ŏ��Ɉ�񂾂�������������������L�q�B	
	void Updata();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��
	void Destory();//�폜���鏈���B
	void End();//engine�I���O�����B
};