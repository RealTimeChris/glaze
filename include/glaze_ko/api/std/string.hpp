// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include <string>
#include <string_view>

#include "glaze_ko/core/meta.hpp"

namespace glz_ko
{
   template <>
   struct meta<std::string>
   {
      static constexpr std::string_view name = "std::string";
   };
}
