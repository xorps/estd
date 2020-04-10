#pragma once

namespace estd {
	namespace detail {
		template <bool cond, typename T = void>
		struct enable_if {};

		template <typename T>
		struct enable_if<true, T> {
			using type = T;
		};
	}
	template <bool cond, typename T = void>
	using enable_if = typename detail::enable_if<cond, T>::type;
}
