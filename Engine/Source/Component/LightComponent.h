#pragma once

#include <Core/Core.h>
#include "Component.h"
#include <Math/Vector3f.h>
#include <Renderer/ConstantBuffer.h>

namespace STL
{
	//픽셀 쉐이더로 전달할 데이터
	struct LightBufferData
	{
		LightBufferData()
			: position(), padding(0.0f),
			color(Vector3f::One), padding1(0.0f)
		{
		}

		// 16 바이트 정렬
		Vector3f position;
		float padding;
		Vector3f color;
		float padding1;
	};

	class ENGINE_API LightComponent : public Component
	{
		RTTI_DECLARATIONS(LightComponent, Component)

	public:
		LightComponent();
		virtual ~LightComponent();

		virtual void Create(ID3D11Device* device) override;
		virtual void Update(ID3D11DeviceContext* context, float deltaTime = 0.0f) override;
		virtual void Bind(ID3D11DeviceContext* context) override;

		void SetLightColor(Vector3f color);

	protected:
		LightBufferData lightData;
		ConstantBuffer lightBuffer;
	};
}