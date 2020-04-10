#pragma once

#include "is_same.h"

namespace estd {
	namespace detail {
		template <typename... T>
		struct member_index;

		template <typename A, typename B, typename... Rest>
		struct member_index<A, B, Rest...> {
			static constexpr auto value = is_same<A, B>::value ? 0 :  1 + member_index<A, Rest...>::value;
		};

		template <typename T>
		struct member_index<T> {
			static constexpr auto value = 0;
		};
	}

	template <typename... T>
	constexpr auto member_index = detail::member_index<T...>::value;
}
