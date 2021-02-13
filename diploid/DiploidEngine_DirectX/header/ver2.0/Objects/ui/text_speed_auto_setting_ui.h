#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
//#include "ver2.0/Objects/DiploidAnimation.h"
#include "ver2.0/Objects/DiploidSlider.h"
#include "ver2.0/Graphics/DiploidStrings.h"

class TextSpeedAutoSettingUI
{
private:
	DiploidSlider string_speed_slider;//�������x�ύX�X���C�_�[
	DiploidSlider auto_speed_slider;//�I�[�g���x�ύX�X���C�_�[
	DiploidStrings test_string;//�ύX�m�F�p����
	DiploidBoxV2 test_string_box;//�I�[�g���x�m�F�pBOX
	float auto_speed;//���Ԃɉ��Z�����
	float time;//���݂̉��Z���ꂽ���Ԃ̕ۑ��p
	float target_time = 64;//���̎��ԂɂȂ�����next_flag�𗧂Ă�
	bool next_flag = false;//���ɍs���Ă������flag
	DiploidImageV2 draw_speed_image;//�������x�ύX�X���C�_�[�̉摜
	DiploidImageV2 auto_speed_image;//�I�[�g���x�ύX�X���C�_�[�̉摜

public:
	void Load();
	void Init(VECTOR pos);
	void Update();
	void Draw(bool draw = true, bool debug = false);

	bool GetHit();//�J�[�\�����������Ă��邩
	bool GetClick();//�N���b�N���ꂽ��
	int GetSelected();//�I����Ԃ�

	void SetParameterAutoSpeed(float new_parameter);
	void SetParameterDrawSpeed(float new_parameter);

	float GetParameterAutoSpeed();//�ύX���ꂽ���Βl�𓾂�B(�I�[�g�X�s�[�h)
	float GetParameterDrawSpeed();//�ύX���ꂽ���Βl�𓾂�B(�`��X�s�[�h)

	float GetParameterAbsoluteAutoSpeed();//�X�N���[�����W����̐�Βl�𓾂�B(�I�[�g�X�s�[�h)
	float GetParameterAbsoluteDrawSpeed();//�X�N���[�����W����̐�Βl�𓾂�B(�`��X�s�[�h)

};