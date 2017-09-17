#pragma once

#include <memory>

namespace Core
{
	template <class T>
	using UniquePtr = std::unique_ptr<T>;

	template <class T>
	using SharedPtr = std::shared_ptr<T>;

	template <class T>
	using WeakPtr = std::weak_ptr<T>;
};