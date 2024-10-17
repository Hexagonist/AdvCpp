#pragma once
#include <iostream>
#include <algorithm>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15


template<typename T, typename C>
auto my_max(T a, T b, C comp)
{
	return comp(a, b);
}