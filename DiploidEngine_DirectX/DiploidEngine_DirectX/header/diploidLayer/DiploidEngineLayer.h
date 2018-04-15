//オブジェクトを描写する順番を決めるためのレイヤーシステム

#pragma once
#include <vector>
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"
#include "diploidGraphics\diploidCircle.h"

class DiploidEngineLayer
{
private:
	//抽象オブジェクトベクター
	std::vector<DiploidEngineObject> layer_top_object_simple;//一番上のレイヤーオブジェクト(一番手前)
	std::vector<DiploidEngineObject> layer_mid_object_simple;//真ん中のレイヤーオブジェクト(真ん中)
	std::vector<DiploidEngineObject> layer_bot_object_simple;//一番下のレイヤーオブジェクト(一番奥)

	//円オブジェクトベクター
	std::vector<DiploidCircle> layer_top_object_circle;//一番上のレイヤーオブジェクト(一番手前)
	std::vector<DiploidCircle> layer_mid_object_circle;//真ん中のレイヤーオブジェクト(真ん中)
	std::vector<DiploidCircle> layer_bot_object_circle;//一番下のレイヤーオブジェクト(一番奥)

public:

	void UpdataLayerObject();//全てのレイヤーを更新
	void DrawLayerObject();//全てのレイヤーを描写

	//抽象オブジェクトプッシュ
	void PushBackTopObject_simple(DiploidEngineObject object);//TOPレイヤーにオブジェクトを追加
	void PushBackMidObject_simple(DiploidEngineObject object);//MIDレイヤーにオブジェクトを追加
	void PushBackBotObject_simple(DiploidEngineObject object);//BOTレイヤーにオブジェクトを追加

	//円オブジェクトプッシュ
	void PushBackTopObject_circle(DiploidCircle object);//TOPレイヤーにオブジェクトを追加
	void PushBackMidObject_circle(DiploidCircle object);//MIDレイヤーにオブジェクトを追加
	void PushBackBotObject_circle(DiploidCircle object);//BOTレイヤーにオブジェクトを追加

	//抽象オブジェクトのアップデートと描写
	void UpdateLayerObject_simple();//レイヤーに追加したオブジェクトをアップデート
	void DrawLayerObject_simple();//レイヤーに追加したオブジェクトを描写

	//円オブジェクトのアップデートと描写
	void UpdateLayerObject_circle();//レイヤーに追加したオブジェクトをアップデート
	void DrawLayerObject_circle();//レイヤーに追加したオブジェクトを描写
};