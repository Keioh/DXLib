#pragma once
#include "DxLib.h"
#include <list>
#include <string>
#include <vector>
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidSlider.h"


class DiploidSwitchingGroupUI
{
private:
	std::vector<DiploidSelectedUIV2> selectedUI_list;

public:

	void Update();
	void Draw(bool draw = true);

	void Push(DiploidSelectedUIV2 data, std::string name);//nameにはボタンの名前を入力。(注:同じオブジェクト内では同じ名前が存在しないように)

	std::string GetName();//現在有効になっているボタンの名前を取得します。
	DiploidSelectedUIV2 GetObjectInfo();//現在有効になっているボタンの情報を取得します。

	std::vector<DiploidSelectedUIV2>& VectorPointer();

};