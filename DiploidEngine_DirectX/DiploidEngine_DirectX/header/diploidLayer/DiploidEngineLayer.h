//�I�u�W�F�N�g��`�ʂ��鏇�Ԃ����߂邽�߂̃��C���[�V�X�e��

#pragma once
#include <vector>
#include "DxLib.h"
#include "diploidGraphics\diploidImage.h"

class DiploidEngineLayer
{
private:
	std::vector<DiploidImage> image_top_vector;
	std::vector<DiploidImage> image_mid_vector;
	std::vector<DiploidImage> image_bot_vector;

public:

	void PushTopGraphics(DiploidImage image);
	void PushMidGraphics(DiploidImage image);
	void PushBotGraphics(DiploidImage image);

	void Updata();
	void Draw(bool draw = true);
};