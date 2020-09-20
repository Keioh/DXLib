#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"

class DiploidCamera
{
private:
	VECTOR camera_center_position = { 1280 / 2,720 / 2,0 };//カメラの中央位置
	VECTOR origin_pos_sub_new_pos;//元になったオブジェクトがいた場所とカメラ中央の距離

	VECTOR other_position;//メインカメラに設定されたオブジェクト以外の位置

protected:

public:

	void SetMainCameraPosition(VECTOR* target);//targetの存在する位置にカメラを移動させます。

	void SetMainCameraPosition_DiploidCircleV2(DiploidCircleV2* target);//targetの存在する位置にカメラを移動させます。(Circle版)
	void SetOtherLookObjectPosition_DiploidCircleV2(DiploidCircleV2* target);//メインカメラの位置に移動していないオブジェクトを正しく移動させます。(Circle版)

	void SetMainCameraPosition_DiploidBoxV2(DiploidBoxV2* target);//targetの存在する位置にカメラを移動させます。(Box版)
	void SetOtherLookObjectPosition_DiploidBoxV2(DiploidBoxV2* target);//メインカメラの位置に移動していないオブジェクトを正しく移動させます。(Box版)


	void SetMainCameraCenterPosition(VECTOR new_position);//ターゲットを画面のどこに移動させるのか設定します。

	VECTOR GetMainCameraCenterPosition();//メインカメラの位置を取得します。
};