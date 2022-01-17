#pragma once
#include <string>
#include <vector>
//#include <climits>
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidScreen\DiploidEngineScreen.h"
#include "diploidInput\DiploidEnigneFile.h"


struct FONT_INFO
{
	int font_handle;
	char font_name[32];
	int size;
	int thick;

};

class DiploidStringV2
{
private:
	DiploidEngineFile file;//�t�@�C�����o��
	float x_buffer;//�\���ʒu�v�Z�p�o�b�t�@

	std::vector<std::wstring> wide_character;//��������ꕶ���Ƃ��ĕۑ�����p
	std::vector<std::vector<std::string>> character;//��������ꕶ���Ƃ��ĕۑ�����p
	std::string string_data;

	std::vector<int>alpha;
	std::vector<int>char_byte;

	VECTOR master_position;//�����̊�{�ʒu


	float next_speed = 40;//��������̑��x
	int end_flag = 0;//�`�悪�I������̂��̃t���O
	bool complete = false;//���Ǎς݂��ǂ���(true�Ŋ���)


	int font_handle;

	unsigned int color = GetColor(255, 255, 255);//�����̐F
	char font_name[32];
	int size;
	int thick;

	//int string_width;//������̒���(��)
	//int string_height;//������̍���(��)

	int _width;//�W�����̒l�̕ۑ��p

	std::string scene_number;

public:
	int CreateFontData(int Size, int Thick, int FontType, const char* FontName = NULL);//DXLIB���Q��
	int GetHandle();
	float GetDrawSpeed();

	void LoadFile(const char* str = "");//�e�L�X�g�f�[�^�̃t�@�C���p�X���w�肵���̃f�[�^����`��p�f�[�^���쐬�B(��d�z��Ƃ��ďo�́BDrawFile()�ŕ`��)
	void Create(std::string str);//�e�L�X�g����`��p�f�[�^�̍쐬�B
	void CreateDXLIB(std::string str, int char_code);//�e�L�X�g����`��p�f�[�^�̍쐬�B(DXLIB�g�p�ŁBchar_code�ɂ�DXLIB�̕����R�[�h�̃}�N�����g�p���邱�ƁB)
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);
	void Init(float x, float y, FONT_INFO font_info);//�t�H���g�n���h�������Ԃ��擾�ł��Ȃ��̂ł��̉��p

	FONT_INFO GetFontInfo();

	void SetWidth(int width);//�`�悷��ő�̕�����̉������w��
	void ChangeFont(int handle);
	void Reset();//�����z��̒����폜���A�Ăѕ�������`������܂��B
	int GetEnd();//������̕`�悪�I��������̃X�e�[�^�X���擾���܂��B(1�ŕ`��I���A0�ŕ`�撆)
	std::string GetSceneName();
	void SetSceneName(std::string name);

	void AllIn();//�S�Ă̕�����\�����܂��B(�ǂݍ��񂾕������S�ĕ\���p�z��ɃR�s�[���܂��B)
	bool GetCompleteFlag();//���ǂ��ǂ����̃t���O�𓾂܂��B
	void SetCompleteFlag(bool new_flag);


	//void SetLineSpaceing(int space);
	void SetSpeed(float speed);//��������̑��x��ݒ肵�܂��B
	void SetColor(unsigned int new_color);//�V���������̐F��ݒ肵�܂��B

	void DrawFile(int line = 0, float frame_time = 1.0f);//LoadFile�֐��œǂݍ��񂾕������\������B(line�ɂ̓t�@�C�����̕\���������s�����w��)
	void Draw(float frame_time = 1.0f);//Load�֐��œǂݍ��񂾕������\������B

	//void Draw(int width, float frame_time = 1.0f);//Load�֐��œǂݍ��񂾕������\������B(�\�����w���)

	void Clear();	
	
	int GetSize();//������̑傫��(����)
};