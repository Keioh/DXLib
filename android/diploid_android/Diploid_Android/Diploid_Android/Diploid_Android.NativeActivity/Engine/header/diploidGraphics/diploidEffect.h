#pragma once
#include <vector>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"

using namespace std;

class DiploidEffect
{
private:
	vector<DiploidImageV2> image_vector;//�摜�z��
	vector<DiploidCircleV2> circle_vector;//�~�z��

public:
	void PushImage(DiploidImageV2 image);//�摜�̒ǉ��B
	void PushCirlce(DiploidCircleV2 circle);//�~�̒ǉ��B

	void UpdateImage();//�A�j���[�V�����Ȃǂ̃A�b�v�f�[�g
	void UpdateCircle();//�A�j���[�V�����Ȃǂ̃A�b�v�f�[�g


	void DrawImage(bool draw = true, bool debug = false);//�G�t�F�N�g��`��
	void DrawCircle(bool draw = true, bool debug = false);//�G�t�F�N�g��`��

};