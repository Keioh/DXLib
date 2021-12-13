//このファイルですべての処理をまとめてDiploidEngineAppに渡す

#pragma once
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include <string>
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidObject\DiploidEngineTag.h"
#include "diploidImpact\DiploidEngineImpact.h"
#include "diploidLayer\DiploidEngineLayer.h"
#include "diploidNetwork\DiploidEngineNetwork.h"
#include "diploidSound\diploidEnigneSound.h"
#include "diploidScreen\DiploidEngineScreen.h"
#include "diploidInput\DiploidEngineInput.h"
#include "diploidInput\DiploidEnigneFile.h"
#include "diploidDebug\DiploidDebug.h"

//Python関連
namespace python = boost::python;

class DiploidEngineMain
{
private:

	void LayerTOP_ImapctBOX_Sync();//四角とレイヤーTOPの処理
	void LayerMID_ImapctBOX_Sync();//四角とレイヤーMIDの処理
	void LayerBOT_ImapctBOX_Sync();//四角とレイヤーBOTの処理
	void LayerUI_ImapctBOX_Sync();//四角とレイヤーUIの処理

	void LayerTOP_ImapctCIRCLE_Sync();//円とレイヤーTOPの処理
	void LayerMID_ImapctCIRCLE_Sync();//円とレイヤーMIDの処理
	void LayerBOT_ImapctCIRCLE_Sync();//円とレイヤーBOTの処理
	void LayerUI_ImapctCIRCLE_Sync();//円とレイヤーUIの処理

	void LayerTOP_ImapctPOINT_Sync();//点とレイヤーTOPの処理
	void LayerMID_ImapctPOINT_Sync();//点とレイヤーMIDの処理
	void LayerBOT_ImapctPOINT_Sync();//点とレイヤーBOTの処理
	void LayerUI_ImapctPOINT_Sync();//点とレイヤーUIの処理

	void LayerTOP_ImapctLINE_Sync();//線分とレイヤーTOPの処理
	void LayerMID_ImapctLINE_Sync();//線分とレイヤーMIDの処理
	void LayerBOT_ImapctLINE_Sync();//線分とレイヤーBOTの処理
	void LayerUI_ImapctLINE_Sync();//線分とレイヤーUIの処理

public:

	DiploidEngineTag diploidEngineTag;//タグ名で使用

	DiploidEngineSound diploidEngineSound;//音関連

	DiploidEngineInput diploidEngineInput;//キー入力とマウス入力とジョイパット入力関連

	DiploidEngineScreen diploidEngineScreen;//FPSカウンタｰなどフレーム関連

	DiploidEngineSetting diploidEngineSetting;//エンジン初期化や設定などの処理。
	DiploidEngineLayer diploidEngineLayer;//レイヤーシステム処理
	DiploidEngineImpact diploidEngineImpact;//衝突処理
	DiploidEngineNetwork diploidEngineNetwork;//ネットワーク機能処理

	DiploidEngineFile diploidEngineFile;//ファイル入出力

	DiploidDebug diploidDebug;//デバッグ機能

	//以下、よく使う変数を関数として登録
	VECTOR GetWindowSize();//windowサイズを取得(z値はBIT)

	void DestorySync();//仮:衝突処理とレイヤー処理の削除同期処理(なくなる関数かもしれない)

};