#pragma once

#include "Vector.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Math
{
	// CROSS PRODUCT
	template <typename T>
	Vector3<T> CrossProduct(Vector3<T> v1, Vector3<T> v2)
	{
		T crossX = (v1.Y * v2.Z) - (v1.Z - v2.Y);
		T crossY = (v1.Z * v2.X) - (v1.X * v2.Z);
		T crossZ = (v1.X * v2.Y) - (v1.Y * v2.X);

		return Vector3<T>(crossX, crossY, crossZ);
	}

	template <template <typename T, typename A> Vector<T, A> = VectorA<T, A>>
	VectorA<T, A> Project(VectorA<T, A> v1, VectorA<T, A> v2)
	{
		auto projection = v2.Normalize();
		projection *= v2.Dot(v1);
		projection /= v2.Magnitude();

		return projection;
	}

	template <template <typename T, typename A> Vector<T, A> = VectorA<T, A>>
	VectorA<T, A> Perp(VectorA<T, A> v1, VectorA<T, A> v2)
	{
		return (v1 - Project(v1, v2));
	}

	template <template <typename T, typename A> Vector<T, A> = VectorA<T, A>>
	VectorA<T, A> Reject(VectorA<T, A> v1, VectorA<T, A> v2)
	{
		return Perp(v1, v2);
	}

	template <template <typename T, typename A> Vector<T, A> = VectorA<T, A>>
	VectorA<T, A> Distance(VectorA<T, A> v1, VectorA<T, A> v2)
	{
		auto distance = v1 - v2;
		return distance;
	}

	template <template <typename T, typename A> Vector<T, A> = VectorA<T, A>>
	VectorA<T, A> Direction(VectorA<T, A> v1, VectorA<T, A> v2)
	{
		return Distance(v1, v2).Normalize();
	}
};