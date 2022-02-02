#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

class AutoNovel
{
private:
	DiploidAnimation anime;
	DiploidSelectedUIV2 button;
	DiploidBoxV2 box;

	float auto_speed = 0.5f;//時間に加算する量
	float time;//現在の加算された時間の保存用
	float target_time = 64;//この時間になったらnext_flagを立てる

	bool next_flag = false;//次に行っていいよのflag

public:
	void Load();
	void Init(VECTOR pos);
	void Update(DiploidEngineInput& input,int string_get_end_flag, float frame_time = 1.0f);
	void Draw(float frame_time = 1.0f, bool draw = true,  bool debug = false);

	void Reset();

	void SetSpeed(float new_speed);
	void SetSelected(int new_flag);

	bool GetHit();//カーソルが当たっているか
	bool GetClick();//クリックされたか
	int GetSelected();//選択状態か

	bool GetNextFlag();
	float GetAutoSpeed();
};