#pragma once
#include <iostream>

// Ogólny szablon klasy dla obliczania silni
// template <int N>
// class Factorial {
//     public:
//     constexpr int value = N * Factorial<N - 1>::value;  // Rekurencyjne obliczanie
// };

template <int N>
class Factorial 
{
  // constexpr int value = N * Factorial<N-1>::value;
  public:
  // Function during compilation time calculates recursively factorial of given N value and returns result
  constexpr int get_value()
  {
    return N * Factorial<N-1>().get_value();
  }
  private:
  // constexpr int value = ;
};
 
template <>
class Factorial<0> 
{
  public:
  constexpr int get_value()
  {
    return 1;
  }
  private:
  // int value = 1;
};