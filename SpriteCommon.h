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

	// ルートシグネチャの作成
	ID3D12RootSignature* GetRootSignature() {
		return rootSignature;
	}
	// グラフィックスパイプラインの生成
	ID3D12PipelineState* GetPipelineState() {
		return graphicsPipelineState;
	}

private:
	static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcUtils* dxcUils,
		IDxcCompiler3* dxCompiler,
		IDxcIncludeHandler* includeHandler
		);
	ID3D12RootSignature* rootSignature = nullptr;
	ID3D12PipelineState* graphicsPipelineState = nullptr;
public:
	DirectXCommon* dxCommon_ = nullptr;

	DirectXCommon* GetDxCommon()const { return dxCommon_; }
};

