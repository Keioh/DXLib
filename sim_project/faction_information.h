#pragma once
#include "button_ui.h"
#include "FileInput.h"

class FactionInformation
{
private:
	int infomation_tab_active_flag = -1;

	void DrawFactionStrings(Filer config);

public:
	ButtonUI faction_circle;
	ButtonUI infomation_tab_close;

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, Filer config, bool wire);

	void FactionInfomationTabOff();//タブをオフにする。
	void CollisionOff();//ヒットボックスをオフにする。

};