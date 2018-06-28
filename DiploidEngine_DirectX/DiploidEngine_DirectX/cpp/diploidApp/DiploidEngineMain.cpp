#include "diploidApp\DiploidEngineMain.h"


VECTOR DiploidEngineMain::WindowSize()
{
	VECTOR window_size;

	window_size.x = (float)diploidEngineSetting.window_x;
	window_size.y = (float)diploidEngineSetting.window_y;
	window_size.z = (float)diploidEngineSetting.window_bit;

	return window_size;
}


void DiploidEngineMain::DestorySync()//衝突処理とレイヤー処理の削除同期処理
{
	LayerTOP_ImapctBOX_Sync();//四角とレイヤーTOPの処理
	LayerMID_ImapctBOX_Sync();//四角とレイヤーMIDの処理
	LayerBOT_ImapctBOX_Sync();//四角とレイヤーBOTの処理

	LayerTOP_ImapctCIRCLE_Sync();//円とレイヤーTOPの処理
	LayerMID_ImapctCIRCLE_Sync();//円とレイヤーMIDの処理
	LayerBOT_ImapctCIRCLE_Sync();//円とレイヤーBOTの処理

	LayerTOP_ImapctPOINT_Sync();//点とレイヤーTOPの処理
	LayerMID_ImapctPOINT_Sync();//点とレイヤーMIDの処理
	LayerBOT_ImapctPOINT_Sync();//点とレイヤーBOTの処理
}

void DiploidEngineMain::LayerTOP_ImapctPOINT_Sync()
{
	if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.point_vector.empty())
	{
		//画像TOP
		for (auto image = diploidEngineLayer.image_top_vector.begin(); image != diploidEngineLayer.image_top_vector.end(); ++image)
		{
			//円ヒットボックス
			for (auto impact = diploidEngineImpact.point_vector.begin(); impact != diploidEngineImpact.point_vector.end(); ++impact)
			{
				//エラー回避のための処理
				if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.circle_vector.empty())
				{
					//最初：トップ配列画像オブジェクト番号と衝突配列四角オブジェクト番号が一緒　かつ　最後：四角オブジェクトにヒットしていたら
					if ((image->number == impact->number))
					{
						if (impact->impacted == true)
						{
							if ((impact->destory == true) && (image->destory == true))
							{
								diploidEngineLayer.image_top_vector.erase(image);
								diploidEngineImpact.point_vector.erase(impact);

								image = diploidEngineLayer.image_top_vector.begin();
								impact = diploidEngineImpact.point_vector.begin();
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerMID_ImapctPOINT_Sync()
{
	if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.point_vector.empty())
	{
		//画像TOP
		for (auto image = diploidEngineLayer.image_mid_vector.begin(); image != diploidEngineLayer.image_mid_vector.end(); ++image)
		{
			//円ヒットボックス
			for (auto impact = diploidEngineImpact.point_vector.begin(); impact != diploidEngineImpact.point_vector.end(); ++impact)
			{
				//エラー回避のための処理
				if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.point_vector.empty())
				{
					//最初：トップ配列画像オブジェクト番号と衝突配列四角オブジェクト番号が一緒　かつ　最後：四角オブジェクトにヒットしていたら
					if ((image->number == impact->number))
					{
						if (impact->impacted == true)
						{
							if ((impact->destory == true) && (image->destory == true))
							{
								diploidEngineLayer.image_mid_vector.erase(image);
								diploidEngineImpact.point_vector.erase(impact);

								image = diploidEngineLayer.image_mid_vector.begin();
								impact = diploidEngineImpact.point_vector.begin();
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerBOT_ImapctPOINT_Sync()
{
	if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.point_vector.empty())
	{
		//画像TOP
		for (auto image = diploidEngineLayer.image_bot_vector.begin(); image != diploidEngineLayer.image_bot_vector.end(); ++image)
		{
			//円ヒットボックス
			for (auto impact = diploidEngineImpact.point_vector.begin(); impact != diploidEngineImpact.point_vector.end(); ++impact)
			{
				//エラー回避のための処理
				if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.point_vector.empty())
				{
					//最初：トップ配列画像オブジェクト番号と衝突配列四角オブジェクト番号が一緒　かつ　最後：四角オブジェクトにヒットしていたら
					if ((image->number == impact->number))
					{
						if (impact->impacted == true)
						{
							if ((impact->destory == true) && (image->destory == true))
							{
								diploidEngineLayer.image_bot_vector.erase(image);
								diploidEngineImpact.point_vector.erase(impact);

								image = diploidEngineLayer.image_bot_vector.begin();
								impact = diploidEngineImpact.point_vector.begin();
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerTOP_ImapctCIRCLE_Sync()
{
	if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.circle_vector.empty())
	{
		//画像TOP
		for (auto image = diploidEngineLayer.image_top_vector.begin(); image != diploidEngineLayer.image_top_vector.end(); ++image)
		{
			//円ヒットボックス
			for (auto impact = diploidEngineImpact.circle_vector.begin(); impact != diploidEngineImpact.circle_vector.end(); ++impact)
			{
				//エラー回避のための処理
				if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.circle_vector.empty())
				{
					//最初：トップ配列画像オブジェクト番号と衝突配列四角オブジェクト番号が一緒　かつ　最後：四角オブジェクトにヒットしていたら
					if ((image->number == impact->number))
					{
						if (impact->impacted == true)
						{
							if ((impact->destory == true) && (image->destory == true))
							{
								diploidEngineLayer.image_top_vector.erase(image);
								diploidEngineImpact.circle_vector.erase(impact);

								image = diploidEngineLayer.image_top_vector.begin();
								impact = diploidEngineImpact.circle_vector.begin();
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerMID_ImapctCIRCLE_Sync()
{
	if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.circle_vector.empty())
	{
		//画像TOP
		for (auto image = diploidEngineLayer.image_mid_vector.begin(); image != diploidEngineLayer.image_mid_vector.end(); ++image)
		{
			//円ヒットボックス
			for (auto impact = diploidEngineImpact.circle_vector.begin(); impact != diploidEngineImpact.circle_vector.end(); ++impact)
			{
				//エラー回避のための処理
				if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.circle_vector.empty())
				{
					//最初：トップ配列画像オブジェクト番号と衝突配列四角オブジェクト番号が一緒　かつ　最後：四角オブジェクトにヒットしていたら
					if ((image->number == impact->number))
					{
						if (impact->impacted == true)
						{
							if ((impact->destory == true) && (image->destory == true))
							{
								diploidEngineLayer.image_mid_vector.erase(image);
								diploidEngineImpact.circle_vector.erase(impact);

								image = diploidEngineLayer.image_mid_vector.begin();
								impact = diploidEngineImpact.circle_vector.begin();
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerBOT_ImapctCIRCLE_Sync()
{
	if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.circle_vector.empty())
	{
		//画像TOP
		for (auto image = diploidEngineLayer.image_bot_vector.begin(); image != diploidEngineLayer.image_bot_vector.end(); ++image)
		{
			//円ヒットボックス
			for (auto impact = diploidEngineImpact.circle_vector.begin(); impact != diploidEngineImpact.circle_vector.end(); ++impact)
			{
				//エラー回避のための処理
				if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.circle_vector.empty())
				{
					//最初：トップ配列画像オブジェクト番号と衝突配列四角オブジェクト番号が一緒　かつ　最後：四角オブジェクトにヒットしていたら
					if ((image->number == impact->number))
					{
						if (impact->impacted == true)
						{
							if ((impact->destory == true) && (image->destory == true))
							{
								diploidEngineLayer.image_bot_vector.erase(image);
								diploidEngineImpact.circle_vector.erase(impact);

								image = diploidEngineLayer.image_bot_vector.begin();
								impact = diploidEngineImpact.circle_vector.begin();
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerTOP_ImapctBOX_Sync()
{
	if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.box_vector.empty())
	{
		//画像TOP
		for (auto image = diploidEngineLayer.image_top_vector.begin(); image != diploidEngineLayer.image_top_vector.end(); ++image)
		{
			//四角ヒットボックス
			for (auto impact = diploidEngineImpact.box_vector.begin(); impact != diploidEngineImpact.box_vector.end(); ++impact)
			{
				//エラー回避のための処理
				if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.box_vector.empty())
				{
					//最初：トップ配列画像オブジェクト番号と衝突配列四角オブジェクト番号が一緒　かつ　最後：四角オブジェクトにヒットしていたら
					if ((image->number == impact->number))
					{
						if (impact->impacted == true)
						{
							if ((impact->destory == true) && (image->destory == true))
							{
								diploidEngineLayer.image_top_vector.erase(image);
								diploidEngineImpact.box_vector.erase(impact);

								image = diploidEngineLayer.image_top_vector.begin();
								impact = diploidEngineImpact.box_vector.begin();
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerMID_ImapctBOX_Sync()
{
	if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.box_vector.empty())
	{
		//画像TOP
		for (auto image = diploidEngineLayer.image_mid_vector.begin(); image != diploidEngineLayer.image_mid_vector.end(); ++image)
		{
			//四角ヒットボックス
			for (auto impact = diploidEngineImpact.box_vector.begin(); impact != diploidEngineImpact.box_vector.end(); ++impact)
			{
				//エラー回避のための処理
				if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.box_vector.empty())
				{
					//最初：トップ配列画像オブジェクト番号と衝突配列四角オブジェクト番号が一緒　かつ　最後：四角オブジェクトにヒットしていたら
					if ((image->number == impact->number))
					{
						if (impact->impacted == true)
						{
							if ((impact->destory == true) && (image->destory == true))
							{
								diploidEngineLayer.image_mid_vector.erase(image);
								diploidEngineImpact.box_vector.erase(impact);

								image = diploidEngineLayer.image_mid_vector.begin();
								impact = diploidEngineImpact.box_vector.begin();
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerBOT_ImapctBOX_Sync()
{
	if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.box_vector.empty())
	{
		//画像TOP
		for (auto image = diploidEngineLayer.image_bot_vector.begin(); image != diploidEngineLayer.image_bot_vector.end(); ++image)
		{
			//四角ヒットボックス
			for (auto impact = diploidEngineImpact.box_vector.begin(); impact != diploidEngineImpact.box_vector.end(); ++impact)
			{
				//エラー回避のための処理
				if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.box_vector.empty())
				{
					//最初：トップ配列画像オブジェクト番号と衝突配列四角オブジェクト番号が一緒　かつ　最後：四角オブジェクトにヒットしていたら
					if ((image->number == impact->number))
					{
						if (impact->impacted == true)
						{
							if ((impact->destory == true) && (image->destory == true))
							{
								diploidEngineLayer.image_bot_vector.erase(image);
								diploidEngineImpact.box_vector.erase(impact);

								image = diploidEngineLayer.image_bot_vector.begin();
								impact = diploidEngineImpact.box_vector.begin();
							}
						}
					}
				}
			}
		}
	}
}