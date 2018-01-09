#pragma once
#include "Object_Base.h"

class Input : public ObjectBase
{
private:
	int button_buffer, button_input_log_buffer, x_buffer, y_buffer;//瞬間クリックのデータ保存用

public:
	~Input(){};		//デストラクタ

	bool click;

	void init();

	bool MouseCilck(int MouseInput);//瞬間のクリック
	bool MouseClickContinuation(int mouseinput);//継続クリック
		
};