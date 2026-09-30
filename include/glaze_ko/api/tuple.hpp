// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include "glaze_ko/core/meta.hpp"
#include "glaze_ko/core/tuple.hpp"

namespace glz_ko
{
   template <class... T>
   struct meta<glz_ko::tuple<T...>>
   {
      static constexpr std::string_view name = []<size_t... I>(std::index_sequence<I...>) {
         return join_v<chars<"glz_ko::tuple<">,
                       ((I != sizeof...(T) - 1) ? join_v<name_v<T>, chars<",">> : join_v<name_v<T>>)..., chars<">">>;
      }(std::make_index_sequence<sizeof...(T)>{});
   };
}
