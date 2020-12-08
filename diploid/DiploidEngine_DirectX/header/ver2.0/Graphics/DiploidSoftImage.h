#pragma once
#include <vector>
#include "DxLib.h"
#include  "ver2.0/Graphics/DiploidBoxV2.h"
#include  "ver2.0/Graphics/DiploidCircleV2.h"

//現状JPEGのみ
class DiploidSoftImage
{
private:
	int soft_handle, graphics_handle, div_graphics_handle;//ハンドル
	int graphics_size_x, graphics_size_y;//画像サイズ
	std::vector<DiploidBoxV2> image_box;

public:
	void Load(const char* path);

	int GetGraphicsHandle();//一枚の画像としてのハンドルを得る。

	void CreatSoftImage(float x = 1, float y = 1);//BOXを用いて描画する際のデータを作成します。(x,yには１ドットの大きさを指定,resizeは1以上を指定)

	void SetPixelSize(float x, float y);//描画で使用しているBOXの大きさを変更します。(非推奨)
	void SetPosition(VECTOR pos);
	void SetFill(bool fill);

	void Draw(bool debug = false);//GPU経由で描画します。(未実装)
	void SoftwareDraw(bool debug = false);//BOXを用いて描画します。

};

