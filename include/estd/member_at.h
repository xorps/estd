#pragma once

namespace estd {
	namespace detail {
		template <unsigned int index, unsigned int count, bool, typename Head, typename... Tail>
		struct member_at;

		template <unsigned int index, unsigned int count, typename Head, typename... Tail>
		struct member_at<index, count, true, Head, Tail...> {
			using type = Head;
		};

		template <unsigned int index, unsigned int count, typename Head, typename... Tail>
		struct member_at<index, count, false, Head, Tail...> {
			using type = typename member_at<index, count + 1, index == count + 1, Tail...>::type;
		};
	}
	template <unsigned int index, typename... T>
	using member_at = typename detail::member_at<index, 0, 0 == index, T...>::type;
}
