#pragma once
#include <iostream>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

template <int N>
class Factorial 
{
  public:
  // Function during compilation time calculates recursively factorial of given N value and returns result
  constexpr int get_value()
  {
    return N * Factorial<N-1>().get_value();
  }
  private:
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
};