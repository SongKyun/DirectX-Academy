#pragma once

#include <Core/Core.h>
#include "Component.h"
#include <Math/Vector3f.h>
#include <Math/Matrix4f.h>
#include <Renderer/ConstantBuffer.h>

namespace STL
{
	struct TransformData
	{
		TransformData()
			: position(), rotation(), scale(Vector3f::One)
		{
		}

		Vector3f position;
		Vector3f rotation;
		Vector3f scale;
	};

	class ENGINE_API TransformComponent : public Component
	{
		RTTI_DECLARATIONS(TransformComponent, Component)

	public:
		TransformComponent();
		~TransformComponent();

		virtual void Create(ID3D11Device* device) override;
		virtual void Update(ID3D11DeviceContext* context, float deltaTime = 0.0f) override;
		virtual void Bind(ID3D11DeviceContext* context) override;

		Vector3f Forward() const;
		Vector3f Right() const;
		Vector3f Up() const;

		void SetPosition(float x, float y, float z);
		void SetPosition(const Vector3f& position);
		Vector3f Position() const;

		void SetRotation(float x, float y, float z);
		void SetRotation(const Vector3f& rotation);
		Vector3f Rotation() const;

		void SetScale(float x, float y, float z);
		void SetScale(const Vector3f& scale);
		Vector3f Scale() const;

		Matrix4f transformMatrix;

	private:

		void SetDirty();

		TransformData transformData;
		ConstantBuffer transformBuffer;
		bool isDirty;
	};
}