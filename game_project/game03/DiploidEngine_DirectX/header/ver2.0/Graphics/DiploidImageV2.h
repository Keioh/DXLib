#pragma once
#include "DxLib.h"

class DiploidImageV2
{
private:
	int graphics_handl;//グラフィックハンドル
	int graphics_x, graphics_y;//オリジナルの大きさ

	VECTOR graphics_size;//いろいろ変更を加えた大きさ

	VECTOR position;//描画位置
	VECTOR rotate_position;//回転する際の中心点
	VECTOR graphics_scale = { 1.0f,1.0f,1.0f };//画像の倍率
	float angle;//回転角度
	bool turn = FALSE;//左右反転のフラグ

protected:

public:
	void Load(const char* path);//画像を読み込みます。
	void Init(VECTOR pos, bool shift_flag = true);//読み込んだ画像を初期化します。(shift_flagがtrueで画像を中心にして描画します。)
	void MoveUpdata();//設定した移動速度を反映します。
	void Draw(bool draw = true);//画像を描画します。

	void SetScale(float scale_x, float scale_y);//画像の表示倍率を変更します。
	void SetAngle(float new_angle);//新しく回転角を設定します。
	void SetPosition(VECTOR new_position);//新しく表示位置を設定します。
	void SetTurnFlag(bool new_flag);//新しく画像反転フラグを設定します。
	void SetRotatePosition(VECTOR new_position);//新しく回転軸を設定します。
	void SetMoveSpeed(VECTOR new_move_speed);//新しく移動する速度を設定します。(3軸指定版)
	void SetMoveSpeed(float angle, float new_move_speed);//新しく移動する速度を設定します。(ラジアン角指定版)

	int GetGraphicsHandl();//読み込まれた現在のグラフィックハンドルを取得します。
	VECTOR GetScale();//現在の画像の表示倍率を取得します。
	VECTOR GetSize();//現在の画像の大きさを取得します。
	VECTOR GetPosition();//現在の画像の位置を取得します。
	VECTOR GetRotatePosition();//現在の画像の回転軸座標を取得します。
	float GetAngle();//現在の画像の回転角を取得します。(ラジアン)
	bool GetTurnFlag();//現在の画像反転フラグを取得します。(TRUEで反転)
	VECTOR GetMoveSpeed();//現在のオブジェクトの移動速度を取得します。
	float GetMoveAngle();//現在のオブジェクトの移動している方角を取得します。(ラジアン)

};