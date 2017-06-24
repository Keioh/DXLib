#pragma once
#include "Object_Base.h"

class Input : public ObjectBase
{
private:
	int button_buffer, x_buffer, y_buffer;//瞬間クリックのデータ保存用

public:
	Input();		//コンストラクタ
	~Input(){};		//デストラクタ

	bool MouseCilck(int MouseInput, int flag);//瞬間のクリック
	bool MouseInputClick(int mouseinput);//継続クリック
		
};