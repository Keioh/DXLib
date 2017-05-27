#include "Sound.h"

Sound::Sound()
{	
	stop_sound_dont_use = 0;//なぜか初期化できない
	stop_sound_dont_use_1 = 0;//なぜか初期化できない
	//stop_sound_dont_use_2 = 0;//なぜか初期化できない

	stop				= 0;//再生ストップ
	wait				= 1;//待機
	quiet_battle		= 2;//静かな戦闘
	intense_battle		= 3;//激しい戦闘
	normal_time_in_game = 4;//平常
	deity				= 5;//神格遭遇
	reasoning			= 6;//推理
	fear				= 7;//恐怖
	climax				= 8;//クライマックス
}

void Sound::Load()
{
	sound[1] = LoadSoundMem("pack/sound/待機.mp3");
	sound[2] = LoadSoundMem("pack/sound/静かな戦闘.mp3");
	sound[3] = LoadSoundMem("pack/sound/激しい戦闘.mp3");
	sound[4] = LoadSoundMem("pack/sound/平常.mp3");
	sound[5] = LoadSoundMem("pack/sound/神格遭遇.mp3");
	sound[6] = LoadSoundMem("pack/sound/推理.mp3");
	sound[7] = LoadSoundMem("pack/sound/恐怖.mp3");
	sound[8] = LoadSoundMem("pack/sound/クライマックス.mp3");

}

void Sound::Play(int sound_number)//サウンド再生関数(再生したいサウンドの番号)	0はなにも再生しない。
{
	switch (sound_number)
	{
	case 0:	//すべての再生を停止する
			StopSoundMem(sound[1]);
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 1:	//待機
		ChangeVolumeSoundMem(180, sound[1]);//ボリューム変更

		if(CheckSoundMem(sound[1]) == 0)PlaySoundMem(sound[1], DX_PLAYTYPE_LOOP);//再生されていなければ再生する
			StopSoundMem(sound[2]);//sound[1]以外を再生停止する
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 2:	//静かな戦闘	
		ChangeVolumeSoundMem(180, sound[2]);//ボリューム変更

		if (CheckSoundMem(sound[2]) == 0)PlaySoundMem(sound[2], DX_PLAYTYPE_LOOP);//再生されていなければ再生する
			StopSoundMem(sound[1]);//sound[2]以外を再生停止する
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 3://激しい戦闘
		ChangeVolumeSoundMem(180, sound[3]);//ボリューム変更

		if (CheckSoundMem(sound[3]) == 0)PlaySoundMem(sound[3], DX_PLAYTYPE_LOOP);//再生されていなければ再生する
			StopSoundMem(sound[1]);//sound[3]以外を再生停止する
			StopSoundMem(sound[2]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 4://平常
			ChangeVolumeSoundMem(180, sound[4]);//ボリューム変更

		if (CheckSoundMem(sound[4]) == 0)PlaySoundMem(sound[4], DX_PLAYTYPE_LOOP);//再生されていなければ再生する
			StopSoundMem(sound[1]);//sound[4]以外を再生停止する
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 5://神格遭遇
			ChangeVolumeSoundMem(255, sound[5]);//ボリューム変更

		if (CheckSoundMem(sound[5]) == 0)PlaySoundMem(sound[5], DX_PLAYTYPE_LOOP);//再生されていなければ再生する
			StopSoundMem(sound[1]);//sound[5]以外を再生停止する
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 6://平常
			ChangeVolumeSoundMem(180, sound[6]);//ボリューム変更

		if (CheckSoundMem(sound[6]) == 0)PlaySoundMem(sound[6], DX_PLAYTYPE_LOOP);//再生されていなければ再生する
			StopSoundMem(sound[1]);//sound[6]以外を再生停止する
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 7://恐怖
			ChangeVolumeSoundMem(190, sound[7]);//ボリューム変更
	
		if (CheckSoundMem(sound[7]) == 0)PlaySoundMem(sound[7], DX_PLAYTYPE_LOOP);//再生されていなければ再生する
			StopSoundMem(sound[1]);//sound[7]以外を再生停止する
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[8]);

			break;

	case 8://クライマックス
			ChangeVolumeSoundMem(190, sound[7]);//ボリューム変更

		if (CheckSoundMem(sound[8]) == 0)PlaySoundMem(sound[8], DX_PLAYTYPE_LOOP);//再生されていなければ再生する
			StopSoundMem(sound[1]);//sound[8]以外を再生停止する
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);

			break;

	default:
		break;
	}
}