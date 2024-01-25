#pragma once
#include <Windows.h>

#include <wrl.h>
#include <string>
#include <dxcapi.h>

#include "DirectXCommon.h"

class SpriteCommon
{
public: // メンバ変数
	// 初期化
	void Initialize(DirectXCommon*dxCommon);
	// 共通描画設定
	void DrawSetCommon();

private:
	static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcUtils* dxcUils,
		IDxcCompiler3* dxCompiler,
		IDxcIncludeHandler* includeHandler
		);
	// ルートシグネチャの作成
	void GetRootSignature();
	// グラフィックスパイプラインの生成
	void GetPipelineState();

	DirectXCommon* dxCommon_;
public:
	DirectXCommon* dxCommon_ = nullptr;

	DirectXCommon* GetDxCommon()const { return dxCommon_; }
};

