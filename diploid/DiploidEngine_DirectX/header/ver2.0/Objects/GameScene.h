#pragma once
#include "DxLib.h"
//#include "diploidApp\DiploidEngineApp.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "system/define.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "ver2.0/Objects/DiploidNovelScene.h"

#include "ver2.0/Objects/button/AutoNovel.h"
#include "ver2.0/Objects/button/SkipNovel.h"

#include "data/text_data/ja.h"

class GameScene
{
private:
	DiploidScreenGraphics test;//モザイク処理

	AutoNovel auto_button;//オートボタン
	SkipNovel skip_button;//スキップボタン

	ja_text jp;//テキストデータ

	DiploidBoxV2 box;//フェード用BOX

	DiploidAnimation end_anime;//anime

	DiploidNovelScene novel_scene;

	DiploidImageV2 string_back_wall;//文字列の後ろの黒いやつ
	DiploidImageV2 data_back_wall;//日付の後ろの赤いやつ
	DiploidImageV2 data_test;//test日付
	DiploidImageV2 place_test;//test場所

	DiploidImageV2 image_00;//背景画像(仮)

	int click = 0;//現在のテキスト位置

	//透過処理の変数
	int alpha = 255;
	int alpha_speed = 4;//透過速度

	int box_draw_flag = 0;//0でフェードアウト、1でフェードアウト完了、2でフェードイン、3でフェードイン完了

public:
	void Load();

	void Init(DiploidEngineSetting& setting);

	void Updata(DiploidEngineInput& input);

	void Draw();

};