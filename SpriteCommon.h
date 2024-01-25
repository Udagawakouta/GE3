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

private:
	static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcUtils* dxcUils,
		IDxcCompiler3* dxCompiler,
		IDxcIncludeHandler* includeHandler
		);
	// ���[�g�V�O�l�`���̍쐬
	void GetRootSignature();
	// �O���t�B�b�N�X�p�C�v���C���̐���
	void GetPipelineState();

	DirectXCommon* dxCommon_;
public:
	DirectXCommon* dxCommon_ = nullptr;

	DirectXCommon* GetDxCommon()const { return dxCommon_; }
};

