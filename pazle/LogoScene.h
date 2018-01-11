#pragma once
#include "DxLib.h"
#include "FileInput.h"

#include "logo.h"

#include "sound_system.h"

#include "fade_in.h"
#include "fade_out.h"

class LogoScene
{
private:
	Logo logo;//ロゴ表示関連

	SoundSystem logo_sound;//ロゴを表示するときに鳴らす音

	FadeIn fade_in;//フェードイン
	FadeOut fade_out;//フェードアウト

public:
	LogoScene();//コンストラクタ

	int logo_scene_flag;

	int logo_sound_handl;

	void init();//初期化

	void Load();//読み込み
	void DrawLogoScene(int x, int y, Filer config);//描写

};