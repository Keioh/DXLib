#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

class SkipNovel
{
private:
	DiploidAnimation anime;
	DiploidSelectedUIV2 button;
	DiploidBoxV2 box;
	
	float skip_speed = 525;
	float next_time = 60;
	float time;

	int next_flag = 1;//次に行っていいよのflag

public:
	void Load();
	void Init(VECTOR pos);
	void Update(DiploidEngineInput& input, float frame_time = 1.0f);
	void Draw(float frame_time = 1.0f, bool draw = true,  bool debug = false);


	void Reset();


	void SetSelected(int new_flag);


	bool GetHit();//カーソルが当たっているか
	bool GetClick();//クリックされたか
	int GetSelected();//選択状態か

	int GetNextFlag();//1で次へいくflagが立っている、-1で選択状態でない、0で選択状態だがスキップ条件を満たしてない。
};