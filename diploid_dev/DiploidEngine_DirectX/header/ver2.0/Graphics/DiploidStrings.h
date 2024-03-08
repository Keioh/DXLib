#pragma once
#include <string>
#include <vector>
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidScreen\DiploidEngineScreen.h"

class DiploidStrings
{
private:
	char string[512];//�o�͗p
	char load_string[524];//�ǂݍ��ݗp

	char font_name;
	int size;
	int thick;
	int line_spacing = 10;
	int end_flag = 0;//�`�悪�I������̂��̃t���O
	int string_all = 0;//���݂̕����̈ʒu��ۑ�

	unsigned int color = GetColor(255, 255, 255);//�����̐F

	int font_handle;
	float pos_x, pos_y;

	int count = 0;//������z��̌��݈ʒu
	int next_time = 100;//���̕�����\�����鎞��
	int time;//���ԕۑ��p

	float next_speed = 50;//��������̑��x

	bool complete = false;//���Ǎς݂��ǂ���(true�Ŋ���)

	std::string scene_number;

	bool new_line_flag = true;

public:

	int CreateFontData(int Size, int Thick, int FontType, char *FontName = NULL);//DXLIB���Q��
	int GetHandle();
	float GetDrawSpeed();

	void Load(const char* str = "");//\n�ŉ��s��\���B(1�s512�����A�T���s�܂�)
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);

	void ChangeFont(int handle);
	void Reset();//�����z��̒����폜���A�Ăѕ�������`������܂��B
	int GetEnd();//������̕`�悪�I��������̃X�e�[�^�X���擾���܂��B(1�ŕ`��I���A0�ŕ`�撆)
	std::string GetSceneName();
	void SetSceneName(std::string name);

	void AllIn();//�S�Ă̕�����\�����܂��B(�ǂݍ��񂾕������S�ĕ\���p�z��ɃR�s�[���܂��B)
	bool GetCompleteFlag();//���ǂ��ǂ����̃t���O�𓾂܂��B
	void SetCompleteFlag(bool new_flag);

	void SetLineSpaceing(int space);
	void SetSpeed(float speed);//��������̑��x��ݒ肵�܂��B
	void SetColor(unsigned int new_color);//�V���������̐F��ݒ肵�܂��B

	void Draw(float frame_time = 1.0f);//Load�֐��œǂݍ��񂾕������\������B(1�s512����)

	void Draw(int width, float frame_time = 1.0f);//Load�֐��œǂݍ��񂾕������\������B(1�s512����)(�\�����w���)

};