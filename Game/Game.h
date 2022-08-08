#pragma once

#include <Core/Core.h>
#include <Core/Application.h>

#include <Renderer/VertexBuffer.h>
#include <Renderer/InputLayout.h>
#include <Renderer/IndexBuffer.h>
#include <Renderer/Texture.h>
#include <Renderer/SamplerState.h>
#include <Renderer/ConstantBuffer.h>

#include <EngineShader/STLDefaultShader.h>
#include <EngineShader/STLPositionColorShader.h>
#include <EngineShader/STLPositionColorUVShader.h>
#include <EngineShader/STLTransformShader.h>

#include <Math/Vector3f.h>
#include <Math/Matrix4f.h>

#include <Component/Actor.h>
#include <Component/TransformComponent.h>

#include "DemoLevel.h"

namespace STL
{
	class Game : public Application
	{
	public:
		Game(
			HINSTANCE hInstance,
			uint32 width,
			uint32 height,
			const std::wstring& title
		);

		virtual ~Game();
		virtual void Initialize() override;
		virtual void Update(float deltaTime = 0.0f) override;
		virtual void RenderScene() override;

	private:
		//VertexBuffer vertexBuffer;
		//IndexBuffer indexBuffer;
		InputLayout inputLayout;
		STLTransformShader mainShader;

		// 텍스처 매핑 관련.
		Texture texture;
		Texture texture2;
		Texture texture3;
		SamplerState samplerState;

		DemoLevel mainLevel;

		//// 위치/회전/스케일.
		//// 행렬 TRS.
		//Vector3f position = Vector3f::Zero;
		//Vector3f rotation = Vector3f::Zero;
		//Vector3f scale = Vector3f::One;
		//Matrix4f worldMatrix = Matrix4f::Identity();

		//// 상수버퍼.
		//ConstantBuffer transformBuffer;

		//ID3D11ShaderResourceView* texture;
		//ID3D11ShaderResourceView* texture2;
		//ID3D11ShaderResourceView* texture3;
		//ID3D11SamplerState* samplerState;

		//Actor
		/*std::unique_ptr<Actor> actor1;
		std::unique_ptr<Actor> actor2;*/
	};
}