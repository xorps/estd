#pragma once

#include "max_size.h"
#include "is_member.h"
#include "enable_if.h"
#include "member_count.h"
#include "inplace_new.h"
#include "member_index.h"
#include "member_at.h"
#include "indice.h"

namespace estd {
	template <typename... T>
	class variant {
	private:
		char storage[max_size<T...>];
		unsigned int type_index;
	public:
		variant() = delete;
		template <typename U, typename = enable_if<member_count<U, T...> == 1>>
		constexpr variant(U u) noexcept(noexcept(static_cast<U&&>(u))) : type_index(member_index<U, T...>) {
			new (&storage) inplace_new<U>(static_cast<U&&>(u));
		}
		template <unsigned int index, typename U, typename = enable_if<is_same<U, member_at<index, T...>>>>
		constexpr variant(indice<index>, U u) noexcept(noexcept(static_cast<U&&>(u))) : type_index(index) {
			new (&storage) inplace_new<U>(static_cast<U&&>(u));
		}
	};
}
