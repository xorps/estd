#pragma once

namespace estd {
	namespace detail {
		template <typename A, typename B>
		struct is_same {
			static constexpr auto value = false;
		};

		template <typename T>
		struct is_same<T, T> {
			static constexpr auto value = true;
		};
	}
	template <typename A, typename B>
	constexpr auto is_same = detail::is_same<A, B>::value;
}