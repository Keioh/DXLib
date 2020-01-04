#pragma once
#include "DxLib.h"

class Transform//変換系と色系と取得系処理
{
private:

protected:
	VECTOR position;//位置
	VECTOR size;//大きさ

	int red;//赤
	int blue;//青
	int green;//緑

public:
	virtual VECTOR GetPosition();//位置を取得します。
	virtual VECTOR GetSize();//大きさを取得します。

	virtual int GetColorRed();//赤色の数値を取得します。(整数値)
	virtual int GetColorBlue();//青色の数値を取得します。(整数値)
	virtual int GetColorGreen();//緑色の数値を取得します。(整数値)

	virtual void SetPosition(VECTOR new_position);//新しい位置を設定します。
	virtual void SetSize(VECTOR new_size);//新しい大きさを設定します。

	virtual void SetColorRed(int new_color);//新しい色を指定します。(赤)
	virtual void SetColorBlue(int new_color);//新しい色を指定します。(青)
	virtual void SetColorGreen(int new_color);//新しい色を指定します。(緑)

};
