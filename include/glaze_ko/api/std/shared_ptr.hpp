// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include <memory>

#include "glaze_ko/core/meta.hpp"

namespace glz_ko
{
   template <class T>
   struct meta<std::shared_ptr<T>>
   {
      static constexpr std::string_view name = join_v<chars<"std::shared_ptr<">, name_v<T>, chars<">">>;
   };
}
