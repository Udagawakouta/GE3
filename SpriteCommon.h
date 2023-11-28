#pragma once
#include <Windows.h>

#include <wrl.h>
#include <string>
#include <dxcapi.h>

#include "DirectXCommon.h"

class SpriteCommon
{
public: // ƒƒ“ƒo•Ï”
	// ‰Šú‰»
	void Initialize(DirectXCommon*dxCommon);

private:
	static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcUtils* dxcUils,
		IDxcCompiler3* dxCompiler,
		IDxcIncludeHandler* includeHandler
		);

public:
	DirectXCommon* dxCommon_ = nullptr;
};

