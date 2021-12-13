# DiploidEngineについて
>DiploidEngineとは、DXライブラリを用いたゲーム開発フレームワークです。
>DXライブラリは基本的な機能しか提供していません。
>このDiploidEnigneでは主に2Dにおける、当たり判定やUIオブジェクト、アニメーションなどのDXライブラリが提供していない機能を実現します。

## DiploidEnigneの始め方
0. VC++の[DXライブラリ](https://dxlib.xsrv.jp/index.html) をCドライブ直下に入れる。(C:/DxLib_VC)
1. C++の拡張ライブラリ、Boostを入れる。
2. Pythonの実行環境を構築する。
3. Cドライブ直下にGameProjectフォルダを作成する。(C:/GameProject)
4. 上記で作成したGameProjectフォルダにdiploidフォルダを入れる。(C:/GameProject/diploid)
5. DiploidEngine_DirectX.slnをダブルクリック。

## DiploidEnigneの使い方
- cppフォルダ内のDiploidEnigneApp.cppとheaderフォルダ内のDiploidEnigneApp.hを開きます。
- 基本はヘッダー内のprivateに変数などを宣言していきます。
- privateで宣言した変数などをDiploidEnigneApp.cppの各関数内で処理をしていきます。
- DiploidEnigneApp.hで最も重要なpublic関数は４つです。
- ・void GraphicsLoad(DiploidEngineApp* app)
  - 画像などを１回だけ読み込みます。
- 画面解像度を変更した際に再び一度だけこの関数が呼ばれます。
- ・void GraphicsInit(DiploidEngineApp* app)
  - 画像などのオブジェクトを１回だけ初期化します。
- 画面解像度を変更した際に再び一度だけこの関数が呼ばれます。
- ・void Updata(DiploidEngineApp* app)
   - 様々なオブジェクトの処理を実行します。
- Updata回数はFPSに依存しています。
- ・void Draw(DiploidEngineApp* app)
  - Updata()での結果を描画します。
- 初期でprivateに宣言されているLogoScene、TitleScene、GameScene、OptionSceneはゲームの雛形です。無くても動きます。
- ゲーム内で画面解像度を変更したい時など、システムに大きくかかわる処理を実行する際はDiploidEngineApp* appからdiploidEngineSettingを参照し、そこから変更してください。
- アクセスの仕方。
  - DiploidEninge::Updata()関数内などでapp->diploidEngineSettingを呼ぶ。
    - 例えば、app->diploidEngineSetting.SetExit(1);を実行するとゲームが終了する。

## DiploidEngineの機能
- DXライブラリが提供する機能。
- グラフィック関係の簡略化。
- ボタンやスライダーなどのUIオブジェクト。
- 画面解像度を変更した際のデータ再読み込み。
- 文字送りの描画機能。
- アニメーション機能。
- 統括されたマウス、キーボードの機能。
- 2Dにおける当たり判定。(一部制限あり)
- 1ループに掛かる時間の計測
- 他
