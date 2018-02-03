#pragma once
#include "start.h"
#include "load.h"
#include "exit.h"
#include "option.h"

#include "FileInput.h"

#include "sound_system.h"

#include "OptionScene.h"

#include "fade_in.h"
#include "fade_out.h"

class StartScene
{
private:
	int flag;

	int back_wall_graphics;//背景画像ハンドル
	int info_graphics;//説明文字列背景画像ハンドル

public:
	StartScene();

	FadeIn fade_in;
	FadeOut fade_out;

	SoundSystem bgm;

	OptionScene option_scene;

	Start start;
	Load load;
	Option option;
	Exit exit;

	int start_pos_x;//start_buttonアニメ開始初期位置
	int load_pos_x;//load_buttonアニメ開始初期位置
	int option_pos_x;//option_buttonアニメ開始初期位置
	int exit_pos_x;//exit_buttonアニメ開始初期位置

	float anime_x;//アニメの速度

	int start_scene_flag;//-1でゲーム終了、0でスタート画面をループ、1でnew game、2でロード画面、3でオプション画面。

	void Load();
	void Init(Filer config);//()の中は設定ファイル

	void OptionSeceneConfig(Filer config);//オプション画面のコンフィグ処理まとめ

	void DrawStartScene(int window_x, int window_y, Filer config, bool wire);

	void SoundStop();//音を停止
};