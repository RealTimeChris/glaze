// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include <list>

#include "glaze_ko/core/meta.hpp"

namespace glz_ko
{
   template <class T>
   struct meta<std::list<T>>
   {
      static constexpr std::string_view name = join_v<chars<"std::list<">, name_v<T>, chars<">">>;
   };
}
