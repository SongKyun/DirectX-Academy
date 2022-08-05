#include "Core.h"
#include "TransformComponent.h"
#include <Utility/STLException.h>

namespace STL
{
	TransformComponent::TransformComponent()
		: isDirty(false), transformMatrix()
	{
		transformMatrix = Matrix4f::Identity();
	}

	TransformComponent::~TransformComponent()
	{
	}

	void TransformComponent::Create(ID3D11Device* device)
	{
		transformMatrix =
			Matrix4f::Scale(transformData.scale)
			* Matrix4f::Rotation(transformData.rotation)
			* Matrix4f::Translation(transformData.position);

		transformBuffer = ConstantBuffer(&transformMatrix, 1, sizeof(Matrix4f));
		transformBuffer.Create(device);
	}

	void TransformComponent::Update(ID3D11DeviceContext* context, float deltaTime)
	{
		if (isDirty == false)
		{
			return;
		}

		transformMatrix =
			Matrix4f::Scale(transformData.scale)
			* Matrix4f::Rotation(transformData.rotation)
			* Matrix4f::Translation(transformData.position);

		transformBuffer.Update(context, &transformMatrix);

		isDirty = false;
	}

	void TransformComponent::Bind(ID3D11DeviceContext* context)
	{
		transformBuffer.Bind(context, 0);
	}

	Vector3f TransformComponent::Forward() const
	{
		Vector3f rotation = transformData.rotation;
		Matrix4f orientation = Matrix4f::Rotation(rotation);
		return orientation * Vector3f::Forward;
	}

	Vector3f TransformComponent::Right() const
	{
		Vector3f rotation = transformData.rotation;
		Matrix4f orientation = Matrix4f::Rotation(rotation);
		return orientation * Vector3f::Right;
	}

	Vector3f TransformComponent::Up() const
	{
		Vector3f rotation = transformData.rotation;
		Matrix4f orientation = Matrix4f::Rotation(rotation);
		return orientation * Vector3f::Up;
	}

	void TransformComponent::SetPosition(float x, float y, float z)
	{
		transformData.position = Vector3f(x, y, z);
		SetDirty();
	}

	void TransformComponent::SetPosition(const Vector3f& position)
	{
		transformData.position = position;
		SetDirty();
	}

	Vector3f TransformComponent::Position() const
	{
		return transformData.position;
	}

	void TransformComponent::SetRotation(float x, float y, float z)
	{
		transformData.rotation = Vector3f(x, y, z);
		SetDirty();
	}

	void TransformComponent::SetRotation(const Vector3f& rotation)
	{
		transformData.rotation = rotation;
		SetDirty();
	}

	Vector3f TransformComponent::Rotation() const
	{
		return transformData.rotation;
	}

	void TransformComponent::SetScale(float x, float y, float z)
	{
		transformData.scale = Vector3f(x, y, z);
		SetDirty();
	}

	void TransformComponent::SetScale(const Vector3f& scale)
	{
		transformData.scale = scale;
		SetDirty();
	}

	Vector3f TransformComponent::Scale() const
	{
		return transformData.scale;
	}

	void TransformComponent::SetDirty()
	{
		isDirty = true;
	}
}