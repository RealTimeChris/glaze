// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include <tuple>

#include "glaze_ko/core/tuple.hpp"
#include "glaze_ko/reflection/get_name.hpp"
#include "glaze_ko/util/for_each.hpp"
#include "glaze_ko/util/string_literal.hpp"

namespace glz_ko
{
   template <class T>
   concept is_std_tuple = is_specialization_v<T, std::tuple>;
}
