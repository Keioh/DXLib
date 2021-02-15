#pragma  once
#include "vector"
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"

class DiploidAnimation
{
private:

	std::vector<DiploidImageV2> images;

	DiploidImageV2 image;

	int animation_image_number = 1;
	int animation_speed = 5;
	int time;
	int next_time = 60;

	int sheets;
	int sheets_anime = 0;
public:

	void Load(const char* path);

	void Init(VECTOR pos, int sheet, float scale_x = 1.0f, float scale_y = 1.0f);

	void Update();
	void SetPosition(VECTOR  new_pos);
	void SetScale(float new_x, float new_y);
	void SetNextAnimationTime(int new_time);//���̉摜�֍s�����Ԃ�ݒ肷��B
	void SetAnimationSpeed(int new_Speed);//�A�j���[�V�����̃X�s�[�h��ݒ肷��B
	void Reset();//�A�j���[�V�������ŏ�����Đ�(�ԍ�������)

	int GetAnimationNumber();//�`�悵�Ă���R�}�����ԖڂȂ̂��𒲂ׂ܂��B
	int GetAnimationSpeed();//���݂̃A�j���[�V�����̃X�s�[�h�𒲂ׂ܂��B

	void Draw(bool debug = false);//�ꖇ�Â`��
	void OneCellDraw(int number = 0, bool draw = true);//�ꖇ�����`��
	void StackDraw(bool debug = false);//�d�˂ĕ`��

	void AllPop();

	size_t GetImagesVectorSize();
};