#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "diploidScreen\DiploidEngineScreen.h"
#include "system\DiploidEngineSetting.h"
#include "diploidInput/DiploidEnigneFile.h"

class DiploidNovelScene
{
private:
	DiploidEngineFile file;
	DiploidTranslate trans;
	std::vector<std::string> string_line_vector;
	std::vector<std::string> path_vector;
	std::vector<std::string> name_vector;

	std::unordered_map<std::string, DiploidImageV2> image_map;
	std::unordered_map<std::string, int> map_alpha;
	DiploidImageV2 image;

	std::string object_name;//���O�ۑ��p
	int alpha_speed = 500;

public:
	void SetAlphaSpeed(int new_speed);

	//Load()�֐����g�p����Ƃ��́AOnceFileLoad()��Create()�͎g�p���Ȃ�
	void OnceFileLoad(const char* path);//txt�t�@�C������摜�p�X��ǂݍ���
	void Create();//OnceFileLoad()�œǂݍ��񂾃p�X����摜�f�[�^�Q�Ɨp�̃f�[�^���쐬����B

	void Load(const char* path, std::string name);
	void Init(DiploidEngineSetting& setting, VECTOR pos);

	void SetDrawName(std::string name);//���O�ɂ��摜�̕ύX�B
	void Update(DiploidEngineScreen& screen);//��ʂ̐؂�ւ�����
	void Draw(bool draw = true);

	void AlphaMax();//�A���t�@�l���ő�ɂ��܂��B

	void NameDraw(std::string name, bool draw = true);//�I�u�W�F�N�g�̖��O���w�肵�ĕ`��(�񐄏�)

	void Reset();
};