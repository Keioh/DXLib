#include "ver2.0/Objects/DiploidNovelScene.h"

void DiploidNovelScene::OnceFileLoad(const char* path)
{
	//ファイルを開く
	file.ReadOpen(path);

	while ((ProcessMessage() == 0) && (file.GetFileInAdr()))
	{			
		//ファイルから一行読み込み
		string_line_vector.push_back(file.GetLine());
	}

	file.Close();


	//文字列の分割
	if (!string_line_vector.empty())
	{
		//各文字列一時保存用
		std::string name_buffer;
		std::string path_buffer;

		for (int count = 0; count != (string_line_vector.size() - 1); ++count)
		{

			//文字列分割
			trans.SplitString(string_line_vector.at(count), name_buffer, path_buffer);

			//各データをプッシュ
			path_vector.push_back(path_buffer);

			name_vector.push_back(name_buffer);
		}
	}
}

void DiploidNovelScene::Create()
{
	//初期化
	image_map.clear();
	map_alpha.clear();

	//データを作成
	for (int count = 0; count != string_line_vector.size() - 1; ++count)
	{
		image.Load(path_vector.at(count).c_str());//画像読み込み
		image.SetName(name_vector.at(count));//オブジェクトの名前の設定
		image.SetActive(false);//オブジェクトのアクティブフラグをfalseに設定。
		image.SetAlpha(0);

		map_alpha[name_vector.at(count)] = 0;

		image_map[name_vector.at(count)] = image;
	}
}

void DiploidNovelScene::Load(const char* path, std::string name)
{
	image.Load(path);//画像読み込み
	image.SetName(name);//オブジェクトの名前の設定
	image.SetActive(false);//オブジェクトのアクティブフラグをfalseに設定。
	image.SetAlpha(0);

	map_alpha[name] = 0;

	image_map[name] = image;

}

void DiploidNovelScene::Init(DiploidEngineSetting& setting, VECTOR pos)
{
	if (!image_map.empty())
	{
		for (auto itr = image_map.begin(); itr != image_map.end(); ++itr)
		{
			itr->second.Init(pos);
			itr->second.SetScale(setting.GetSystemData().window_x / itr->second.GetSize().x, setting.GetSystemData().window_y / itr->second.GetSize().y);
		}
	}
}

void DiploidNovelScene::SetDrawName(std::string name)
{
	object_name = name;

	if (!image_map.empty())
	{		
		image_map[object_name].SetActive(true);


		for (auto itr = image_map.begin(); itr != image_map.end(); ++itr)
		{
			if (itr->first != object_name)
			{
				if (itr->second.GetActiveFlag() == true)
				{
					itr->second.SetActive(false);
				}
			}
		}
	}
}


void DiploidNovelScene::Update(DiploidEngineScreen& screen)
{
	//MAP連想配列が空でないとき
	if (!image_map.empty())
	{
		//キーと名前がいっしょのとき
		if (image_map[object_name].GetName() == object_name)
		{
			//オブジェクトのアクティブフラグがtrueのとき
			if (image_map[object_name].GetActiveFlag() == true)
			{
				image_map[object_name].SetAlpha(map_alpha[object_name]);

				if (map_alpha[object_name] >= 255)
				{
					map_alpha[object_name] = 255;
				}
				else
				{
					map_alpha[object_name] += alpha_speed * screen.GetFrameTime();
				}
			}
		}

		for (auto obj_itr = image_map.begin(); obj_itr != image_map.end(); ++obj_itr)
		{
			if (obj_itr->second.GetActiveFlag() == false)
			{
				obj_itr->second.SetAlpha(map_alpha[obj_itr->second.GetName()]);

				if (map_alpha[obj_itr->second.GetName()] <= 0)
				{
					map_alpha[obj_itr->second.GetName()] = 0;
				}
				else
				{
					map_alpha[obj_itr->second.GetName()] -= alpha_speed * screen.GetFrameTime();
				}
			}
		}
	}
}



void DiploidNovelScene::Draw(bool draw)
{
	//描画
	if (!image_map.empty())
	{
		for (auto itr = image_map.begin(); itr != image_map.end(); ++itr)
		{
			if (itr->second.GetAplha() > 0)
			{
				itr->second.Draw(draw);
			}
		}
	}

	//DrawFormatString(0, 200, GetColor(255, 255, 255), "map_alpha = %d", map_alpha[object_name]);
	//DrawFormatString(0, 220, GetColor(255, 255, 255), "object_alpha = %d", image_map[object_name].GetAplha());

}

void DiploidNovelScene::NameDraw(std::string name, bool draw)
{
	//名前がおなじなら
	if (image_map[name].GetName() == name)
	{
		//描画
		image_map[name].Draw(draw);
	}
}


void DiploidNovelScene::SetAlphaSpeed(int new_speed)
{
	alpha_speed = new_speed;
}

void DiploidNovelScene::AlphaMax()
{
	if (image_map[object_name].GetActiveFlag() == true)
	{
		map_alpha[object_name] = 255;
	}

	for (auto obj_itr = image_map.begin(); obj_itr != image_map.end(); ++obj_itr)
	{
		if (obj_itr->second.GetActiveFlag() == false)
		{
			map_alpha[obj_itr->second.GetName()] = 0;
		}
	}
}

void DiploidNovelScene::Reset()
{
	//MAP連想配列が空でないとき
	if (!image_map.empty())
	{
		for (auto obj_itr = image_map.begin(); obj_itr != image_map.end(); ++obj_itr)
		{
			map_alpha[obj_itr->second.GetName()] = 255;
		}
	}
}