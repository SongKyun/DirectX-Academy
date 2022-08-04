#include "Core.h"
#include "TextureLoader.h"
#include <DirectXTex.h>
#include <Utility/STLException.h>

namespace STL
{
	std::unordered_map<std::wstring, ID3D11ShaderResourceView*> TextureLoader::textureMap;

	ID3D11ShaderResourceView* TextureLoader::CreateShaderResourceView(ID3D11Device* device, const std::wstring& filename)
	{
		auto search = textureMap.find(filename);
		if (search != textureMap.end())
		{
			return search->second;
		}

		std::wstring extension = filename.substr(filename.find_last_of(TEXT(".")) + 1);
		std::transform(extension.begin(), extension.end(), extension.begin(), tolower);

		static auto basePath = std::filesystem::current_path().parent_path();

		auto finalPath = basePath;
		finalPath /= "Content\\Textures";
		finalPath /= filename;

		DirectX::ScratchImage image;
		HRESULT hr = E_FAIL;
		if (extension == TEXT("tga") || extension == TEXT("targa"))
		{
			hr = DirectX::LoadFromTGAFile(
				finalPath.c_str(),
				nullptr,
				image
			);
		}
		else
		{
			hr = DirectX::LoadFromWICFile(
				finalPath.c_str(),
				DirectX::WIC_FLAGS_NONE,
				nullptr,
				image
			);
		}

		ThrowIfFailed(hr, "Failed to load scratch image.");

		ID3D11Texture2D* texture = nullptr;
		hr = DirectX::CreateTexture(
			device,
			image.GetImages(),
			image.GetImageCount(),
			image.GetMetadata(),
			reinterpret_cast<ID3D11Resource**>(&texture)
		);

		ThrowIfFailed(hr, "Failed to create texture.");

		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
		memset(&srvDesc, 0, sizeof(srvDesc));
		srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		srvDesc.Texture2D.MipLevels = 1;
		srvDesc.Format = image.GetMetadata().format;

		ID3D11ShaderResourceView* shaderResourceView = nullptr;
		hr = device->CreateShaderResourceView(
			texture,
			&srvDesc,
			&shaderResourceView
		);

		SafeRelease(texture);
		ThrowIfFailed(hr, "Failed to shader resource view.");

		textureMap.insert({ filename, shaderResourceView });

		return shaderResourceView;
	}

	void TextureLoader::Release()
	{
		for (auto pair : textureMap)
		{
			SafeRelease(pair.second);
		}
	}
}