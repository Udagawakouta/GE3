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
	ID3D12RootSignature* GetRootSignature();
	// �O���t�B�b�N�X�p�C�v���C���̐���
	ID3D12PipelineState* GetPipelineState();

private:
	static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcUtils* dxcUils,
		IDxcCompiler3* dxCompiler,
		IDxcIncludeHandler* includeHandler
		);

	DirectXCommon* dxCommon_;
public:
	DirectXCommon* dxCommon_ = nullptr;

	DirectXCommon* GetDxCommon()const { return dxCommon_; }
};

