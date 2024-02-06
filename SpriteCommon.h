#pragma once
#include <Windows.h>

#include <wrl.h>
#include <string>
#include <dxcapi.h>

#include "DirectXCommon.h"

class SpriteCommon
{
public: // �����o�ϐ�
	// ������
	void Initialize(DirectXCommon*dxCommon);
	// ���ʕ`��ݒ�
	void DrawSetCommon();

	// ���[�g�V�O�l�`���̍쐬
	ID3D12RootSignature* GetRootSignature() {
		return rootSignature;
	}
	// �O���t�B�b�N�X�p�C�v���C���̐���
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

