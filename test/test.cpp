#include <estd/option.h>
#include <estd/variant.h>
#include <estd/member_at.h>

using namespace estd;

option<int> foo(bool a)
{
	if (a) return 3;
	return {};
}

void bar()
{
	static_assert(member_index<int, char, bool, int> == 2, "test");
	static_assert(member_index<int, int> == 0, "test");
	static_assert(is_same<member_at<2, int, char, float>, float>, "test");
	variant<int, bool> a{ 1 };
	variant<int, int> b{ indice<1>{}, 1 };
}

void bar1()
{
}

int main(int argc, const char** argv)
{
	auto a = foo(true);
	auto b = foo(false);
	return 0;
}