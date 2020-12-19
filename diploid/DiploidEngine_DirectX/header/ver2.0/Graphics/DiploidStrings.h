#pragma once
#include <string>
#include <vector>
#include "DxLib.h"

class DiploidStrings
{
private:
	char strings[128];
	char load_strings[128];

	int font_handle;
	float pos_x, pos_y;

	int count;//������z��̌��݈ʒu
	int next_time;//���̕�����\�����鎞��

	int next_speed = 2;//��������̑��x

public:

	int CreateFontData(int Size, int Thick, int FontType, char *FontName = NULL);//DXLIB���Q��
	int GetHandle();

	void Load(const char* str);
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);

	void ChangeFont(int handle);
	void Reset();//�����z��̒����폜���A�Ăѕ�������`������܂��B

	void SetSpeed(int speed);//��������̑��x��ݒ肵�܂��B

	void Draw(float x = 0, float y = 0);//Load�֐��œǂݍ��񂾕������\������B(128�����܂�)
	void DrawStrings(int x, int y, const char* str);//128�����܂�

};