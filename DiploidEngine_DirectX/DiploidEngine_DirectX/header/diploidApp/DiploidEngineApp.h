//�����ł��B

#pragma once
#include "DxLib.h"
#include "diploidApp\DiploidEngineMain.h"
#include "diploidObject\DiploidEngineObject.h"

#include "system\DiploidEngineMath.h"

#include "diploidGraphics\diploidLine.h"

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidObject object;

public:
	void Load();//�Q�[���N�����Ƀ��[�h����f�[�^
	void Init();//�ŏ��Ɉ�񂾂��������������������L�q�B
	void Updata();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��

	DiploidObject FindObject(int layer_number, int number);//�w��ԍ�����I�u�W�F�N�g���擾(�I�u�W�F�N�g������)
	DiploidEngineImpact FindImpactBOX(int layer_number, int number);//�w��ԍ�����I�u�W�F�N�g���擾(�Փ˂�����)
	DiploidEngineImpact FindImpactCIRCLE(int layer_number, int number);//�w��ԍ�����I�u�W�F�N�g���擾(�Փ˂�����)
	DiploidEngineImpact FindImpactPOINT(int layer_number, int number);//�w��ԍ�����I�u�W�F�N�g���擾(�Փ˂�����)
	DiploidEngineLayer FindImageTOP(int layer_number, int number);//�w��ԍ�����I�u�W�F�N�g���擾(�摜������)
	DiploidEngineLayer FindImageMID(int layer_number, int number);//�w��ԍ�����I�u�W�F�N�g���擾(�摜������)
	DiploidEngineLayer FindImageBOT(int layer_number, int number);//�w��ԍ�����I�u�W�F�N�g���擾(�摜������)

};