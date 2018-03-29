#pragma once
#include "DxLib.h"
#include "GraphicsLoad.h"

class Graphics
{
private:
	Graphics()	= default;
	~Graphics() = default;

	GraphicsLoad testLoad;


public:
	Graphics(const 	Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	Graphics(Graphics&&) = delete;
	Graphics& operator=(Graphics&&) = delete;

	static Graphics* GetInstans();
	
	void Load();
	
	void SetPos(float x, float y);

};