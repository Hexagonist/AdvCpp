#pragma once
#include <iostream>

// Ogólny szablon klasy dla obliczania silni
// template <int N>
// class Factorial {
//     public:
//     constexpr int value = N * Factorial<N - 1>::value;  // Rekurencyjne obliczanie
// };

template <int N>
struct Factorial 
{
  enum { value = N * Factorial<N-1>::value };
};
 
template <>
struct Factorial<0> 
{
  enum { value = 1 } ;
};