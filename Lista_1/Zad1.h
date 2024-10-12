#pragma once
#include <iostream>
#include <algorithm>


// template <T a, T c, C comp>
// void my_max(a* aa, c* cc)
// {
// 	return std::max(aa, cc);
// }

template<typename T, typename C>
auto my_max(T a, T c, C comp)
{
	return comp(a, c);
}
