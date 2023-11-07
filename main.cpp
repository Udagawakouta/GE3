#include "DirectXCommon.h"
#include "Input.h"
#include "WinApp.h"

#include "SpriteCommon.h"
#include "Sprite.h"



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

#pragma region 基礎システムの初期化

	// input
	Input* input_ = nullptr;
	WinApp* winApp_ = nullptr;
	DirectXCommon* dxCommon_ = nullptr;

	// WindowsAPI初期化処理
	winApp_ = new WinApp();
	winApp_->Initialize();

	// DirectX初期化処理
	dxCommon_ = new DirectXCommon();
	dxCommon_->Initialize(winApp_);

	// Input生成、初期化
	input_ = new Input();
	input_->Initialize(winApp_);

	SpriteCommon* spriteCommon = nullptr;
	// スプライト共通部の初期化
	spriteCommon = new SpriteCommon;
	spriteCommon->Initialize(dxCommon_);

#pragma region 最初のシーンの初期化

	Sprite* sprite = new Sprite();
	sprite->Initialize(spriteCommon);

#pragma endregion 


#pragma endregion 
	// ゲームループ
	while (true) {
		// 更新
		if (winApp_->Update() == true)
		{
			break;
		}
		//	入力
		input_->Update();

		// 更新前処理
		dxCommon_->PreDraw();

		// 更新後処理
		dxCommon_->PostDraw();
	}

	delete input_;

	delete dxCommon_;

	delete spriteCommon;

	winApp_->Finalize();
	delete winApp_;

	return 0;
}
