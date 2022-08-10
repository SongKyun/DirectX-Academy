#pragma once

#include "Vector3f.h"

namespace STL
{
	class alignas(16) ENGINE_API Matrix4f
	{
	public:
		Matrix4f();
		Matrix4f(const Matrix4f& other);
		~Matrix4f();

		static Matrix4f Identity();
		static Matrix4f Translation(const Vector3f& position);
		static Matrix4f Translation(float x, float y, float z);
		static Matrix4f Rotation(const Vector3f& rotation);
		static Matrix4f Rotation(Quaternionf rotation);
		static Matrix4f Rotation(float x, float y, float z);
		static Matrix4f RotationX(float angle);
		static Matrix4f RotationY(float angle);
		static Matrix4f RotationZ(float angle);

		static Matrix4f Scale(const Vector3f& scale);
		static Matrix4f Scale(float x, float y, float z);
		static Matrix4f LookAt(Vector3f& position, Vector3f& target, Vector3f& up);
		static Matrix4f Perspective(float fov, float width, float height, float zNear, float zFar);
		static Matrix4f Transpose(const Matrix4f& target);

		float& Get(const uint32 row, uint32 col);
		float* GetM();

		Matrix4f& operator=(const Matrix4f& other);
		Matrix4f operator*(const Matrix4f& other);
		Matrix4f operator*=(const Matrix4f& other);

		Vector3f operator*(const Vector3f& other);

		static const unsigned int elementSize = 4 * 4;

	private:
		float elements[elementSize];
	};
}