#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "system\DiploidEngineMath.h"
#include "ver2.0/Objects/DiploidSliderObject.h"
#include "ver2.0/Graphics/DiploidTriangle.h"


//�����x�������̃X���C�h�̂݃T�|�[�g
class DiploidSlider
{
private:
	DiploidImageV2 slider_image;
	DiploidSliderObject slider_button;

	DiploidTriangle triangle;
	TRIANGLE t_data;
	DiploidBoxV2 box;

	VECTOR position;//UI�̈ʒu(���オ�)
	VECTOR object_size;//�X���C�_�[�̓�������͈͂��w��B(x���݂̂̏ꍇ��VGet(�����ɐ��l,0,0));
	float object_scale = 1.0f;

	int slider_object_type = 1;//0�Ŏ��R�ړ��B1��x�������Œ�ړ��B2��y�������Œ�ړ��B

	DiploidEngineInput input;

public:
	void Load();
	void Init(VECTOR pos, VECTOR size, int slider_type = 1, float scale = 1.0f);//UI�����������܂��B
	void Updata();//UI���X�V���܂��B
	void Draw(bool draw = true, bool debug = false);//UI��`�悵�܂��B

	void SetPosition(int pos_x, int pos_y);//�V�����ʒu��ݒ肵�܂��B(����)
	void SetSelectedUI(int new_flag);
	void SetSliderType(int new_type);
	void SetParameter(VECTOR new_parameter);//�w�肷��l��size�Ŏw�肵���l���傫���Ă��������Ă��_���B

	bool GetHit();//���݁AUI�Ƀ}�E�X���q�b�g���Ă��邩�̃t���O���擾���܂��B(�q�b�g���Ă����true)
	bool GetClick();//UI���N���b�N���ꂽ���̃t���O���擾���܂��B(�N���b�N������true)
	int GetSelectedUI();//UI���I������Ă��邩�̃t���O���擾���܂��B(�I������Ă����true)
	int GetSliderType();
	VECTOR GetParameter();//���݂̃X���C�_�[�̒l���擾���܂��B
};