//�I�u�W�F�N�g��`�ʂ��鏇�Ԃ����߂邽�߂̃��C���[�V�X�e��

#pragma once
#include <vector>
#include "DxLib.h"
#include "diploidGraphics\diploidImage.h"

class DiploidEngineLayer
{
private:

	float top_byte;
	float mid_byte;
	float bot_byte;
	int top_size;
	int mid_size;
	int bot_size;

public:
	std::vector<DiploidImage> image_top_vector;
	std::vector<DiploidImage> image_mid_vector;
	std::vector<DiploidImage> image_bot_vector;

	void GetSize();//�e�z��̑傫�����擾

	void PushTopGraphics(DiploidImage image);
	void PushMidGraphics(DiploidImage image);
	void PushBotGraphics(DiploidImage image);

	void Updata();
	void Draw(bool debug = false, bool draw = true);
	void Destory();//destory�ϐ���ture�̏ꍇ�A�v�f���폜

	void DestoryTop();//top�z�񂩂�v�f���폜
	void DestoryMid();//mid�z�񂩂�v�f���폜
	void DestoryBot();//bot�z�񂩂�v�f���폜

};