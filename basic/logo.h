#pragma once
#include "Object_Base.h"

class Logo : public ObjectBase
{
private:
	int logo_D, logo_d, logo_i, logo_l, logo_o, logo_p;//�摜�n���h���ۑ��p


public:
	Logo();

	int timer;//�A�j���^�C�}�[
	float anime_pos_x = -anime_x;//�A�j�������J�n��
	float anime_x = 25.0f;//�A�j���̂��߂ɍ��W���炷��
	int alph_graphics;//�摜���l


	void LoadGraphics();
	void Inti();
	void DrawLogo(int x, int y);
};