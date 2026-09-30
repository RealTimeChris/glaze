// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include <string>

#include "glaze_ko/core/meta.hpp"
#include "glaze_ko/util/string_literal.hpp"
#include "glaze_ko/util/type_traits.hpp"

namespace glz_ko
{
   template <class T>
   concept is_help = requires { requires(T::glaze_help == true); };

   template <class T, string_literal HelpMessage>
   struct help
   {
      static constexpr auto glaze_help = true;
      static constexpr sv help_message = HelpMessage.sv();
      using value_type = T;
      T value{};

      constexpr operator T&() noexcept { return value; }

      constexpr operator const T&() const noexcept { return value; }
   };

   template <class T, string_literal HelpMessage>
   struct meta<help<T, HelpMessage>>
   {
      using V = help<T, HelpMessage>;
      static constexpr sv name =
         join_v<chars<"glz_ko::help<">, name_v<typename V::value_type>, chars<",\"">, V::help_message, chars<"\">">>;
      static constexpr auto value{&V::value};
   };
}
