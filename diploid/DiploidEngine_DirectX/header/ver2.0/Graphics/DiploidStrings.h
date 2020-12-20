#pragma once
#include <string>
#include <vector>
#include "DxLib.h"

class DiploidStrings
{
private:
	char strings[6][256];//���ۂɕ\������镶����̔z��
	char load_strings[5][256];//�ǂݍ��񂾕�����
	int line = 0;//�s
	int word_count = 0;//�s�̂Ȃ�������̃J�E���g

	char font_name;
	int size;
	int thick;
	int end_flag = 0;//�`�悪�I������̂��̃t���O

	int font_handle;
	float pos_x, pos_y;

	int count;//������z��̌��݈ʒu
	int next_time;//���̕�����\�����鎞��

	int next_speed = 0;//��������̑��x

public:

	int CreateFontData(int Size, int Thick, int FontType, char *FontName = NULL);//DXLIB���Q��
	int GetHandle();

	void Load(const char* str);//\n�ŉ��s�A\f�ŕ��̏I����\���BGetEnd()�֐����g�p����ꍇ�͕��̏I����\f��t���邱�ƁB(1�s256�����A�T���s�܂�)
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);

	void ChangeFont(int handle);
	void Reset();//�����z��̒����폜���A�Ăѕ�������`������܂��B(�o�O�ɂ��g�p�s��)
	int GetEnd();//������̕`�悪�I��������̃X�e�[�^�X���擾���܂��B(1�ŕ`��I���A0�ŕ`�撆)

	void SetSpeed(int speed);//��������̑��x��ݒ肵�܂��B

	void Draw(float x = 0, float y = 0);//Load�֐��œǂݍ��񂾕������\������B(1�s256�����A�T���s�܂�)
};