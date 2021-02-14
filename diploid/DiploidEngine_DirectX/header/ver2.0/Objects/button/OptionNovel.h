#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

class OptionNovel
{
private:
	DiploidAnimation anime;
	DiploidSelectedUIV2 button;

public:
	void Load();
	void Init(VECTOR pos);
	void Update(DiploidEngineInput& input);
	void Draw(bool draw = true,  bool debug = false);

	void Reset();

	void SetSelected(int new_flag);

	bool GetHit();//�J�[�\�����������Ă��邩
	bool GetClick();//�N���b�N���ꂽ��
	int GetSelected();//�I����Ԃ�
};