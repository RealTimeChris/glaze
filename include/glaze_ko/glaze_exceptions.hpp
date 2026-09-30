// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#if __cpp_exceptions

// These files provide convenience functions that throw C++ exceptions, which can make code cleaner for users

#include "glaze_ko/exceptions/binary_exceptions.hpp"
#include "glaze_ko/exceptions/cbor_exceptions.hpp"
#include "glaze_ko/exceptions/csv_exceptions.hpp"
#include "glaze_ko/exceptions/json_exceptions.hpp"
#include "glaze_ko/exceptions/msgpack_exceptions.hpp"

namespace glz_ko::ex
{
   template <auto Opts>
   void read(auto& value, auto&& buffer)
   {
      auto ec = glz_ko::read<Opts>(value, buffer);
      if (ec) {
         if constexpr (Opts.format == JSON) {
            throw std::runtime_error("read error: " + glz_ko::format_error(ec, buffer));
         }
         else {
            throw std::runtime_error("read error");
         }
      }
   }

   template <auto Opts, class T, output_buffer Buffer>
   void write(T&& value, Buffer& buffer) noexcept
   {
      glz_ko::write<Opts>(std::forward<T>(value), buffer);
   }

   template <auto Opts, class T, raw_buffer Buffer>
   size_t write(T&& value, Buffer&& buffer) noexcept
   {
      return glz_ko::write<Opts>(std::forward<T>(value), std::forward<Buffer>(buffer));
   }
}

#endif
