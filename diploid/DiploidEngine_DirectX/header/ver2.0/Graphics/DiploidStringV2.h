#pragma once
#include <string>
#include <vector>
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidScreen\DiploidEngineScreen.h"
#include "diploidInput\DiploidEnigneFile.h"


class DiploidStringV2
{
private:
	DiploidEngineFile file;//�t�@�C�����o��
	float x_buffer;//�\���ʒu�v�Z�p�o�b�t�@

	std::vector<std::wstring> wide_character;//��������ꕶ���Ƃ��ĕۑ�����p
	std::vector<std::vector<std::string>> character;//��������ꕶ���Ƃ��ĕۑ�����p
	std::string string_data;

	VECTOR master_position;//�����̊�{�ʒu


	int font_handle;

	char font_name;
	int size;
	int thick;

public:
	int CreateFontData(int Size, int Thick, int FontType, char* FontName = NULL);//DXLIB���Q��
	int GetHandle();
	//float GetDrawSpeed();

	void LoadFile(const char* str = "");//�e�L�X�g�f�[�^�̃t�@�C���p�X���w�肵���̃f�[�^����`��p�f�[�^���쐬�B(��d�z��Ƃ��ďo�́BDrawFile()�ŕ`��)
	void Create(std::string str);//�e�L�X�g����`��p�f�[�^�̍쐬�B
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);

	void ChangeFont(int handle);
	//void Reset();//�����z��̒����폜���A�Ăѕ�������`������܂��B
	//int GetEnd();//������̕`�悪�I��������̃X�e�[�^�X���擾���܂��B(1�ŕ`��I���A0�ŕ`�撆)
	//std::string GetSceneName();
	//void SetSceneName(std::string name);

	//void AllIn();//�S�Ă̕�����\�����܂��B(�ǂݍ��񂾕������S�ĕ\���p�z��ɃR�s�[���܂��B)
	//bool GetCompleteFlag();//���ǂ��ǂ����̃t���O�𓾂܂��B
	//void SetCompleteFlag(bool new_flag);

	//void SetLineSpaceing(int space);
	//void SetSpeed(float speed);//��������̑��x��ݒ肵�܂��B
	//void SetColor(unsigned int new_color);//�V���������̐F��ݒ肵�܂��B

	void DrawFile(int line = 0, float frame_time = 1.0f);//LoadFile�֐��œǂݍ��񂾕������\������B(line�ɂ̓t�@�C�����̕\���������s�����w��)
	void Draw(float frame_time = 1.0f);//Load�֐��œǂݍ��񂾕������\������B(1�s512����)

	//void Draw(int width, float frame_time = 1.0f);//Load�֐��œǂݍ��񂾕������\������B(1�s512����)(�\�����w���)

	void Clear();
};