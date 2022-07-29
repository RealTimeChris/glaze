// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include <utility>

namespace glaze
{
   template <class = void, std::size_t...Is>
   constexpr auto indexer(std::index_sequence<Is...>) {
     return [](auto&& f) -> decltype(auto) {
       return decltype(f)(f)( std::integral_constant<std::size_t, Is>{}... );
     };
   }
   
   // takes a number N
   // returns a function object that, when passed a function object f
   // passes it compile-time values from 0 to N-1 inclusive.
   template <size_t N>
   constexpr auto indexer() {
     return indexer(std::make_index_sequence<N>{});
   }
   
   template <size_t N, class Func>
   constexpr auto for_each(Func&& f) {
      return indexer<N>()([&](auto&&...i){
         (std::forward<Func>(f)(i), ...);
      });
   }
}
