#pragma once
#include "SpriteCommon.h"
#include <wrl.h>
#include <d3d12.h>
#include "DirectXCommon.h"

using namespace Microsoft::WRL;

class Sprite
{
public: // ƒƒ“ƒo•Ï”
	// ‰Šú‰»
	void Initialize(DirectXCommon* dxCommon, SpriteCommon* common);
	
	void Draw();

private:
	DirectXCommon* dxCommon_ = nullptr;

	ComPtr<ID3D12Resource>vertexResource = nullptr;
	
	SpriteCommon* common_ = nullptr;
	
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};
};