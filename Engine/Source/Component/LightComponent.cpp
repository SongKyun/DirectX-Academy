#include "Core.h"
#include "LightComponent.h"
#include "TransformComponent.h"

namespace STL
{
	LightComponent::LightComponent()
		: Component(), lightData(), lightBuffer()
	{
		lightBuffer = ConstantBuffer(&lightData, 1, sizeof(lightData));
		lightBuffer.SetBindShaderTarget(BindShaderTarget::PixelShader);
	}
	
	LightComponent::~LightComponent()
	{
	}
	
	void LightComponent::Create(ID3D11Device* device)
	{
		lightData.position = transform->Position();

		// 라이트 버퍼 생성.
		lightBuffer.Create(device);
	}

	void LightComponent::Update(ID3D11DeviceContext* context, float deltaTime)
	{
		lightData.position = transform->Position();
		lightBuffer.Update(context, &lightData);
	}

	void LightComponent::Bind(ID3D11DeviceContext* context)
	{
		lightBuffer.Bind(context, 0);
	}
	
	void LightComponent::SetLightColor(Vector3f color)
	{
		lightData.color = color;
	}
}