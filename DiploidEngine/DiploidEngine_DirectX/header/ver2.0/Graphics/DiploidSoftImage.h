#pragma once
#include <vector>
#include "DxLib.h"
#include  "ver2.0/Graphics/DiploidBoxV2.h"
#include  "ver2.0/Graphics/DiploidImageV2.h"
#include  "ver2.0/Graphics/DiploidCircleV2.h"

class SoftImageData
{
public:
	int r;
	int g;
	int b;
	int a;

	VECTOR pos;
	VECTOR size;

	int soft_handle;
	int image_handle;
};

class DiploidSoftImage
{
private:
	int soft_handle, graphics_handle, div_graphics_handle;//ハンドル
	int graphics_size_x, graphics_size_y;//画像サイズ
		
	int r, g, b, a;//ピクセルの色情報

	float scale_x = 1.0f, scale_y = 1.0f, angle = 0.0f;//画像１枚１枚のスケールと角度

	SoftImageData data_buffer;
	DiploidBoxV2 box;

	std::vector<SoftImageData> data;
	std::vector<DiploidBoxV2> image_box;


	std::vector<SoftImageData> screen_0, screen_1, screen_2, screen_3;

public:
	void Load(const char* path);

	int GetGraphicsHandle();//一枚の画像としてのハンドルを得る。

	void CreatSoftImage(float x = 1, float y = 1);//BOXを用いて描画する際のデータを作成します。(x,yには１ドットの大きさを指定,resizeは1以上を指定)
	void CreatGraphicsImage(int x = 1, int y = 1);//Imageを用いて描画する際のデータを作成します。(x,yには１ドットの大きさを指定,resizeは1以上を指定)


	void SetSoftPixelSize(float x, float y);//描画で使用しているBOXの大きさを変更します。(非推奨)
	void SetSoftPosition(VECTOR pos);
	void SetSoftFill(bool fill);
	void SetSoftThickness(float thickness);

	void SetGraphicsScale(float x, float y);

	void Draw(bool debug = false);//GPU経由で描画します。(未実装)
	void SoftwareDraw(bool debug = false);//BOXを用いて描画します。
	void GraphicsDraw(bool debug = false);//DrawGraphを用いて描画します。

	void SoftImageDelet();
};

