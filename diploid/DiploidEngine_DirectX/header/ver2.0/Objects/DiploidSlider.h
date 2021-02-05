#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Main/Collision.h"
#include "diploidInput/DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"

class DiploidSlider
{
private:

public:

	void Load(int graphics_handl);
	void Init(VECTOR pos, VECTOR size, float scale = 1.0f);//UI�����������܂��B
	void Updata(DiploidEngineInput* input);//UI���X�V���܂��B
	void Draw(bool draw = true, bool debug = false);//UI��`�悵�܂��B

	void SetPosition(int pos_x, int pos_y);//�V�����ʒu��ݒ肵�܂��B(����)
	void SetSize(int size_x, int size_y);//�V�����傫����ݒ肵�܂��B(�o�O)
	void SetScale(float new_scale);//�V�����X�P�[���l��ݒ肵�܂��B(�o�O)
	void SetSelectedUI(int new_flag);

	VECTOR GetPosition();//���݂�UI�̈ʒu(����)�̍��W���擾���܂��B
	VECTOR GetSize();//���݂�UI�̑傫�����擾���܂��B
	float GetScale();
	bool GetHit();//���݁AUI�Ƀ}�E�X���q�b�g���Ă��邩�̃t���O���擾���܂��B(�q�b�g���Ă����true)
	bool GetClick();//UI���N���b�N���ꂽ���̃t���O���擾���܂��B(�N���b�N������true)
	int GetSelectedUI();//UI���I������Ă��邩�̃t���O���擾���܂��B(�I������Ă����true)
};