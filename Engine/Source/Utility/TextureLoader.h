#pragma once

#include <Core/Core.h>

namespace STL
{
	class ENGINE_API TextureLoader
	{
	public:
		static ID3D11ShaderResourceView* CreateShaderResourceView(
			ID3D11Device* device,
			const std::wstring& filename
		);

		static void Release();

		static std::unordered_map<std::wstring, ID3D11ShaderResourceView*> textureMap;
	};
}