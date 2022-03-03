#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
//#include "ver2.0/Objects/DiploidAnimation.h"
#include "ver2.0/Objects/DiploidSlider.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "ver2.0/Graphics/DiploidStringV2.h"

class TextSpeedAutoSettingUI
{
private:
	DiploidSlider string_speed_slider;//�������x�ύX�X���C�_�[
	DiploidSlider auto_speed_slider;//�I�[�g���x�ύX�X���C�_�[
	DiploidStringV2 test_string;//�ύX�m�F�p����
	DiploidBoxV2 test_string_box;//�I�[�g���x�m�F�pBOX
	float auto_speed;//���Ԃɉ��Z�����
	float time;//���݂̉��Z���ꂽ���Ԃ̕ۑ��p
	float target_time = 64;//���̎��ԂɂȂ�����next_flag�𗧂Ă�
	bool next_flag = false;//���ɍs���Ă������flag
	DiploidImageV2 draw_speed_image;//�������x�ύX�X���C�_�[�̉摜
	DiploidImageV2 auto_speed_image;//�I�[�g���x�ύX�X���C�_�[�̉摜
	DiploidBoxV2 string_background_box;//�����̔w�i


	DiploidSlider string_background_alpha_slider;//�����w�i���ߓx�ύX�X���C�_�[
	DiploidImageV2 string_background_alpha_image;//�����w�i���ߓx�ύX�摜
	int background_alpha;

public:
	void Load();
	void Init(VECTOR pos);
	void Update(DiploidEngineScreen& screen);
	void Draw(float frame_time = 1.0f, bool draw = true, bool debug = false);

	bool GetHit();//�J�[�\�����������Ă��邩
	bool GetClick();//�N���b�N���ꂽ��
	int GetSelected();//�I����Ԃ�

	void SetParameterAutoSpeed(float new_parameter);
	void SetParameterDrawSpeed(float new_parameter);
	void SetParameterBackGroundAlpha(float new_parameter);

	float GetParameterAutoSpeed();//�ύX���ꂽ���Βl�𓾂�B(�I�[�g�X�s�[�h)
	float GetParameterDrawSpeed();//�ύX���ꂽ���Βl�𓾂�B(�`��X�s�[�h)
	float GetParameterBackGroundAlpha();//�ύX���ꂽ���Βl�𓾂�B(�����w�i�̓��ߒl)


	float GetParameterAbsoluteAutoSpeed();//�X�N���[�����W����̐�Βl�𓾂�B(�I�[�g�X�s�[�h)
	float GetParameterAbsoluteDrawSpeed();//�X�N���[�����W����̐�Βl�𓾂�B(�`��X�s�[�h)
	float GetParameterAbsoluteBackGroundAlpha();//�X�N���[�����W����̐�Βl�𓾂�B(�����w�i�̓��ߒl)


	float GetParameterScaleAutoSpeed();//�P�t���[�����Z���ɓ�����l���擾����B(�I�[�g�X�s�[�h)
	float GetParameterScaleDrawSpeed();//�P�t���[�����Z���ɓ�����l���擾����B(�`��X�s�[�h)

};