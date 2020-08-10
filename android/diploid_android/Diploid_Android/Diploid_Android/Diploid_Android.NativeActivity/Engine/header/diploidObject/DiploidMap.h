//配列のmapではなく、画像からゲームマップを作製するためのクラスです。

#pragma once
#include <list>
#include "DxLib.h"


struct MAP_DATA
{
	float x;
	float y;

	int red;
	int green;
	int blue;
	int alph;

	int size;
};

class DiploidMap
{
private:
	float map_moved_x, map_moved_y;

public:
	int handl;
	int Width, Height;//画像の縦と横の大きさ

	int MAP_SIZE = 2;//マップチップの大きさを指定します。(1ドット単位)

	float position_x = 0.0f, position_y = 0.0f;

	std::list<MAP_DATA> MAP;

	void SetMapChipSize(int size = 4);//マップチップの大きさをしてい
	void SetPosition(float x = 0.0f, float y = 0.0f);//マップの初期位置を指定します。(Create関数の前に実行したときだけ効果を発揮します)
	int Load(const char* path, int data_size_x, int data_size_y);//マップデータを読み込みます。
	void Create();//マップを作製します。(動作としてはMAP配列にLoadで読み込んだ画像の大きさ分だけ縦横RBGとα値をプッシュバックしています。)
	void Updata(float move_x, float move_y);//キャラクターを使って移動するときにマップを移動させます(動く量)
	void Draw(bool wire = false);//マップデータを元にマップを描写します
};