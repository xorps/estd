#pragma once

#include "is_same.h"

namespace estd {
	namespace detail {
		template <typename A, typename B, typename... Rest>
		struct member_count {
			static constexpr auto value = is_same<A, B>::value ? 1 + member_count<A, Rest...>::value : member_count<A, Rest...>::value;
		};

		template <typename A, typename B>
		struct member_count<A, B> {
			static constexpr auto value = is_same<A, B>::value ? 1 : 0;
		};
	}

	template <typename... T>
	constexpr auto member_count = detail::member_count<T...>::value;
}
