#pragma once

#include "is_same.h"

namespace estd {
	namespace detail {
		template <typename A, typename B, typename... Rest>
		struct is_member {
			static constexpr auto value = is_same<A, B>::value ? true : is_member<A, Rest...>::value;
		};

		template <typename A, typename B>
		struct is_member<A, B> {
			static constexpr auto value = is_same<A, B>::value;
		};
	}
	template <typename... T>
	constexpr auto is_member = detail::is_member<T...>::value;
}
