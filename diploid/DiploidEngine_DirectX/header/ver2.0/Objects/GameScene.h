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
#include "diploidScreen\DiploidEngineScreen.h"


#include "ver2.0/Objects/button/AutoNovel.h"
#include "ver2.0/Objects/button/SkipNovel.h"
#include "ver2.0/Objects/button/OptionNovel.h"
#include "ver2.0/Objects/button/SaveNovel.h"
#include "ver2.0/Objects/button/LoadNovel.h"
#include "ver2.0/Objects/button/QuickLoadNovel.h"
#include "ver2.0/Objects/button/QuickSaveNovel.h"

#include "data/text_data/ja.h"

class GameScene
{
private:
	DiploidScreenGraphics screen_graphics;//モザイク処理とか

	AutoNovel auto_button;//オートボタン
	SkipNovel skip_button;//スキップボタン
	OptionNovel option_button;//オプションボタン
	SaveNovel save_button;//セーブボタン
	LoadNovel load_button;//ロードボタン
	QuickLoadNovel quick_load_button;//クイックロードボタン
	QuickSaveNovel quick_save_button;//クイックセーブボタン


	ja_text jp;//テキストデータ

	DiploidBoxV2 box;//フェード用BOX

	DiploidAnimation end_anime;//anime

	DiploidNovelScene novel_scene;

	DiploidImageV2 string_back_wall;//文字列の後ろの黒いやつ

	DiploidImageV2 data_back_wall;//日付の後ろの赤いやつ
	DiploidImageV2 data_test;//test日付
	DiploidImageV2 place_test;//test場所

	DiploidImageV2 image_00;//背景画像(仮)

	SystemData system_data;

	int click = 0;//現在のテキスト位置

	bool in_game = false;//ゲーム中なのかのflag(trueでgame中)

	int is_save_or_load = GAME_LOAD;

	//透過処理の変数
	int alpha = 255;
	int alpha_speed = 500;//透過速度

	int box_draw_flag = 0;//0でフェードアウト、1でフェードアウト完了、2でフェードイン、3でフェードイン完了

public:
	void Load();

	void Init(DiploidEngineSetting& setting);

	void Updata(DiploidEngineInput& input, DiploidEngineScreen& screen);

	void Draw(DiploidEngineScreen& screen);

	void Reset();//文字列データを最初から描画するように設定します。

	void SetInGameFlag(bool new_flag);//ゲーム中かのフラグを変更します。
	bool GetInGameFlag();//ゲーム中かのフラグを取得します

	void SetOptionButtonFlag(int new_flag);//オプションボタンのflagを変更します
	bool GetOptionButtonFlag();//オプションボタンの状態を取得します。

	void SetLoadButtonFlag(int new_flag);//ロードボタンのflagを変更します
	bool GetLoadButtonFlag();//ロードボタンの状態を取得します。

	void SetSaveButtonFlag(int new_flag);//セーブボタンのflagを変更します
	bool GetSaveButtonFlag();//セーブボタンの状態を取得します。

	void SetSystemData(SystemData data);

	int GetSelectedScene();
};