#pragma once
#include "DxLib.h"
#include "diploidImpact/DiploidEngineImpact.h"

class DiploidSystem
{
private:
	bool push_flag = false;
	bool delete_flag = false;

	bool push_box_flag = false;
	bool delete_box_flag = false;

	bool push_point_flag = false;
	bool delete_point_flag = false;

public:

	//BOX
	void OnePushBOX_Impact(DiploidEngineImpact& impact, DiploidBox box);//ループ中一回だけプッシュする。
	void OneDeleteBOX_Impact(DiploidEngineImpact& impact, std::string name_tag);//ループ中一回だけ削除する。

	void FlagReset_OnePushBOX();//一回読み込みフラグをリセットする。
	void FlagReset_OneDeleteBOX();//一回読み込みフラグをリセットする。

	bool GetOnePushBOX_Flag();//OnePushBOX_Impactの現在のフラグを取得する。
	bool GetOneDeleteBOX_Flag();//OneDeleteBOX_Impactの現在のフラグを取得する。

	//POINT
	void OnePushPOINT_Impact(DiploidEngineImpact& impact, DiploidPoint point);//ループ中一回だけプッシュする。
	void OneDeletePOINT_Impact(DiploidEngineImpact& impact, std::string name_tag);//ループ中一回だけ削除する。

	void FlagReset_OnePushPOINT();//一回読み込みフラグをリセットする。
	void FlagReset_OneDeletePOINT();//一回読み込みフラグをリセットする。

	bool GetOnePushPOINT_Flag();//OnePushBOX_Impactの現在のフラグを取得する。
	bool GetOneDeletePOINT_Flag();//OneDeleteBOX_Impactの現在のフラグを取得する。

};