#pragma once
#include <wrl.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <vector>

#include "WinApp.h"
#include <chrono>


class DirectXCommon
{
public:
	// 初期化
	void Initialize(WinApp*winApp);

	//描画前処理
	void PreDraw();

	//描画後処理
	void PostDraw();

	ID3D12Device* GetDevice() const { return device.Get(); }
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }
private:
	// デバイス
	void DeviceInitialize();
	// コマンド
	void CommandInitialize();
	// スワップチェーン
	void SwapChainInitialize();
	// レンダーターゲット
	void RenderTargetInitialize();
	// 深度バッファ
	void DepthBufferInitialize();
	// フェンス
	void FenceInitialize();

	// FPS
	void InitializeFixFPS();
	// // FPS固定処理
	void UpdateFixFPS();
	

private:

	WinApp* winapp = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Device> device;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	Microsoft::WRL::ComPtr<ID3D12CommandAllocator>commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue>commandQuene;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;

	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc{};
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;

	D3D12_RESOURCE_BARRIER barrierDesc{};
private:
	// 記録用時間計測の関数
	std::chrono::steady_clock::time_point reference_;
};

