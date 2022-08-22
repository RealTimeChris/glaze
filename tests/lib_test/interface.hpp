// Glaze Library
// For the license information refer to glaze.hpp
#pragma once

#include <tuple>
#include <iostream>

#include "glaze/api/impl.hpp"
#include "glaze/api/std/deque.hpp"
#include "glaze/api/std/unordered_set.hpp"
#include "glaze/api/std/span.hpp"

struct my_api
{
   int x = 7;
   double y = 5.5;
   std::vector<double> z = {1.0, 2.0};
   std::span<double> s = z;
   std::function<double(const int&, const double&)> f =
      [](const auto& i, const auto& d) { return i * d; };
   std::function<void()> init = [] { std::cout << "init!\n"; };
};

template <>
struct glaze::meta<my_api>
{
   using T = my_api;
   static constexpr auto value = glaze::object("x", &T::x,  //
                                               "y", &T::y,  //
                                               "z", &T::z,  //
                                               "s", &T::s,  //
                                               "f", &T::f,  //
                                               "init", &T::init);
};

GLAZE_SPECIALIZE(my_api, 0, 0, 1)
