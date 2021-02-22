#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "diploidScreen\DiploidEngineScreen.h"


class DiploidNovelScene
{
private:
	std::unordered_map<std::string, DiploidImageV2> image_map;
	std::unordered_map<std::string, int> map_alpha;
	DiploidImageV2 image;

	std::string object_name;//名前保存用
	int alpha_speed = 500;

public:
	void SetAlphaSpeed(int new_speed);

	void Load(const char* path, std::string name);
	void Init(VECTOR pos);

	void SetDrawName(std::string name);//名前による画像の変更。
	void Update(DiploidEngineScreen& screen);//場面の切り替え処理
	void Draw(bool draw = true);

	void AlphaMax();//アルファ値を最大にします。

	void NameDraw(std::string name, bool draw = true);//オブジェクトの名前を指定して描画(非推奨)
};