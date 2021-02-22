#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "diploidScreen\DiploidEngineScreen.h"


class DiploidNovelScene
{
private:
	std::unordered_map<std::string, DiploidImageV2> image_map;
	std::unordered_map<std::string, int> map_alpha;
	DiploidImageV2 image;

	std::string object_name;//���O�ۑ��p
	int alpha_speed = 500;

public:
	void SetAlphaSpeed(int new_speed);

	void Load(const char* path, std::string name);
	void Init(VECTOR pos);

	void SetDrawName(std::string name);//���O�ɂ��摜�̕ύX�B
	void Update(DiploidEngineScreen& screen);//��ʂ̐؂�ւ�����
	void Draw(bool draw = true);

	void AlphaMax();//�A���t�@�l���ő�ɂ��܂��B

	void NameDraw(std::string name, bool draw = true);//�I�u�W�F�N�g�̖��O���w�肵�ĕ`��(�񐄏�)
};