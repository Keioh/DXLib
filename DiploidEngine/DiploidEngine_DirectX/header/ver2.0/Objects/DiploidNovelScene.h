#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "diploidScreen\DiploidEngineScreen.h"
#include "system\DiploidEngineSetting.h"
#include "diploidInput/DiploidEnigneFile.h"

class DiploidNovelScene
{
private:
	DiploidEngineFile file;
	DiploidTranslate trans;
	std::vector<std::string> string_line_vector;
	std::vector<std::string> path_vector;
	std::vector<std::string> name_vector;

	std::unordered_map<std::string, DiploidImageV2> image_map;
	std::unordered_map<std::string, int> map_alpha;
	DiploidImageV2 image;

	std::string object_name;//名前保存用
	int alpha_speed = 500;

public:
	void SetAlphaSpeed(int new_speed);

	//Load()関数を使用するときは、OnceFileLoad()とCreate()は使用しない
	void OnceFileLoad(const char* path);//txtファイルから画像パスを読み込む
	void Create();//OnceFileLoad()で読み込んだパスから画像データ参照用のデータを作成する。

	void Load(const char* path, std::string name);
	void Init(DiploidEngineSetting& setting, VECTOR pos);

	void SetDrawName(std::string name);//名前による画像の変更。
	void Update(DiploidEngineScreen& screen);//場面の切り替え処理
	void Draw(bool draw = true);

	void AlphaMax();//アルファ値を最大にします。

	void NameDraw(std::string name, bool draw = true);//オブジェクトの名前を指定して描画(非推奨)

	void Reset();
};