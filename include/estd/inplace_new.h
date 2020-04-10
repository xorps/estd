#pragma once

namespace estd {
	// Purpose of this class is to allow placement new operator on types
	template <typename T>
	class inplace_new {
	private:
		T m_value;
	public:
		constexpr T *ptr() noexcept { &m_value; }
		constexpr T& ref() noexcept { m_value; }
		constexpr inplace_new(T value) noexcept(noexcept(T(static_cast<T&&>(value)))) : m_value(static_cast<T&&>(value)) {}
		constexpr static void *operator new(size_t size, void *addr) noexcept {
			static_assert(sizeof T == sizeof inplace_new<T>, "same size");
			return addr;
		}
	};
}
