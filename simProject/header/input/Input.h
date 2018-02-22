#pragma once
#include "Object_Base.h"

class Input : public ObjectBase
{
private:
	int button_buffer, button_input_log_buffer, x_buffer, y_buffer;//瞬間クリックのデータ保存用
	bool key_press_flag, press_one;

	char key[256];
	int frame[256];//カウンター

public:
	~Input(){};		//デストラクタ

	bool click, key_press;

	void init();

	int GetKeyFrame();//キーフレームを習得

	bool MouseCilck(int MouseInput);//瞬間のクリック
	bool MouseClickContinuation(int mouseinput);//継続クリック

	bool KeyCilick(int keyInput);//瞬間のクリック
	bool KeyCilickContinuation(int keyInput);//瞬間のクリック

};