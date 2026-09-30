// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include "glaze_ko/core/opts.hpp"
#include "glaze_ko/core/read.hpp"
#include "glaze_ko/core/write.hpp"
#include "glaze_ko/json/json_ptr.hpp"
#include "glaze_ko/util/for_each.hpp"

namespace glz_ko
{
   // Given a JSON pointer path, reads from the buffer into the object
   template <auto Opts, class T, class B>
   [[nodiscard]] error_ctx read_as(T&& root_value, const sv json_ptr, B&& buffer)
   {
      error_ctx pe{};
      bool b = seek([&](auto&& val) { pe = read<Opts>(val, buffer); }, std::forward<T>(root_value), json_ptr);
      if (b) {
         return pe;
      }
      pe.ec = error_code::seek_failure;
      return pe;
   }

   // Given a JSON pointer path, writes into a buffer the specified value
   template <auto Opts, class T, class B>
   [[nodiscard]] bool write_as(T&& root_value, const sv json_ptr, B&& buffer)
   {
      return seek(
         [&](auto&& val) {
            if constexpr (raw_buffer<B>) {
               std::ignore = write<Opts>(
                  val, buffer); // We assume the user has sufficient null characters at the end of the buffer
            }
            else {
               write<Opts>(val, buffer);
            }
         },
         std::forward<T>(root_value), json_ptr);
   }
}
