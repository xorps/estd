#pragma once

namespace estd {
	namespace detail {
		template <typename... T>
		struct max_size;

		template <typename A, typename B, typename... Rest>
		struct max_size<A, B, Rest...> {
			static constexpr auto value = sizeof A > sizeof B ? max_size<A, Rest...>::value : max_size<B, Rest...>::value;
		};

		template <typename A, typename B>
		struct max_size<A, B> {
			static constexpr auto value = sizeof A > sizeof B ? sizeof A : sizeof B;
		};

		template <typename T>
		struct max_size<T> {
			static constexpr auto value = sizeof T;
		};

		template <>
		struct max_size<> {
			static constexpr auto value = 0;
		};
	}
	template <typename... T>
	constexpr auto max_size = detail::max_size<T...>::value;
}
