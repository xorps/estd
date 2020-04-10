#pragma once

#include "inplace_new.h"

namespace estd {
	template <typename T>
	class option {
	private:
		char storage[sizeof inplace_new<T>];
		enum { Some, None } type_tag;
	public:
		constexpr option<T>() noexcept : storage(), type_tag(None) {}
		constexpr option<T>(T value) noexcept(noexcept(T(static_cast<T&&>(value)))) : type_tag(Some) {
			new (&storage) inplace_new<T>(static_cast<T&&>(value));
		}
		constexpr operator bool() const noexcept { return type_tag == Some; }
	};
}
