#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"


class DiploidBox : public DiploidEngineObjectInformation
{
private:
	VECTOR center_position;//�l�p�̒��S�_�̍��W
	VECTOR anime_position, anime_size;//�A�j���[�V�����p�o�b�t�@
	VECTOR origin_position, origin_size;//�I���W�i���̑傫��
	//int mouse_x, mouse_y;

public:

	DiploidBox();
	~DiploidBox();


	void Init(VECTOR position = { 0,0,0 }, VECTOR size = { 0,0,0 });//�}�E�X�ɒǏ]������ꍇ��{0,0,0}����
	void Update();//�|�W�V�����Ȃǂ̐��l��ύX������K���Ă΂Ȃ��ƌ��ʂ����f����Ȃ��B
	void Draw(bool wire = true);

	VECTOR SetCenterPosition(VECTOR new_center_position);//�����|�W�V������C�ӂ̐��l�ɕύX����B(�߂�l��new_center_position��Ԃ�)

	VECTOR GetSize();//�c�Ɖ��̑傫����Ԃ��܂��B
	VECTOR GetPosition(VECTOR get_pos = { 0,0,0 });//�w�肵���ꏊ�̈ʒu��Ԃ��܂��B��)get_pos��{1,0,0}�������l�p�̉E��̃|�W�V�������w�聨�ʒu��VECTOR�^�ŕԂ��B
	VECTOR GetCenterPosition();//�����̈ʒu��Ԃ��܂��B

	void Destory() { impacted = destory = true; };//�폜���܂��B
};