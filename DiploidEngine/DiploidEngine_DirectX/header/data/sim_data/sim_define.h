//マップの大きさ
#define MAP_SIZE_X 80
#define MAP_SIZE_Y 50

//支配領域の区別
#define NOT_ANYONE_FILD 0//誰のものでもない
#define MY_FILD 1//自分の領域
#define ENEMY_FILD 2//敵の領域
#define FRENDLY_FILD 3//友好の領域

//地形の区別
#define TERRAIN_TYPE_GRASS 0//草原地帯
#define TERRAIN_TYPE_ROCKS 1//荒地帯
#define TERRAIN_TYPE_MOUNTAIN 2//山岳地帯
#define TERRAIN_TYPE_NOTHING 3//何もなし

//建物の区別
#define BUILDING_TYPE_NOTHING 0//なにも建っていない
#define BUILDING_TYPE_MY_BASE 1//自分の拠点
#define BUILDING_TYPE_ENEMY_BASE 2//敵の拠点
#define BUILDING_TYPE_FRIENDLY_BASE3 3//友好の拠点

//UIの区別
#define UI_NO_SELECTED 0//どこも選択していない
#define UI_NOTHING 1//マップ上で誰の物でもない場所をクリックしたとき
#define UI_MY_BASE 2//自拠点をクリックしたとき
