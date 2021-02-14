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
#include "ver2.0/Objects/button/OptionNovel.h"

#include "data/text_data/ja.h"

class GameScene
{
private:
	DiploidScreenGraphics screen_graphics;//モザイク処理とか

	AutoNovel auto_button;//オートボタン
	SkipNovel skip_button;//スキップボタン
	OptionNovel option_button;//オプションボタン

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

	bool in_game = false;//ゲーム中なのかのflag(trueでgame中)

	//透過処理の変数
	int alpha = 255;
	int alpha_speed = 4;//透過速度

	int box_draw_flag = 0;//0でフェードアウト、1でフェードアウト完了、2でフェードイン、3でフェードイン完了

public:
	void Load();

	void Init(DiploidEngineSetting& setting);

	void Updata(DiploidEngineInput& input);

	void Draw();

	void Reset();//文字列データを最初から描画するように設定します。

	void SetInGameFlag(bool new_flag);//ゲーム中かのフラグを変更します。
	bool GetInGameFlag();//ゲーム中かのフラグを取得します

	void SetOptionButtonFlag(int new_flag);//オプションボタンのflagを変更します
	bool GetOptionButtonFlag();//オプションボタンの状態を取得します。

};