//�����ł��B

#pragma once
#include "DxLib.h"
#include "diploidApp\DiploidEngineMain.h"

class DiploidEngineApp : public DiploidEngineMain
{
private:
	float r;
	
public:
	void Init();//�ŏ��Ɉ�񂾂��������������������L�q�B
	void Update();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��.


	//�����������ǂ����邩�l����
	void Create();//�V�����I�u�W�F�N�g���쐬����Ƃ��Ɉ�񂾂��Ă΂��B
	void Destory();//�I�u�W�F�N�g���폜����Ƃ��Ɉ�񂾂��Ă΂��B
};