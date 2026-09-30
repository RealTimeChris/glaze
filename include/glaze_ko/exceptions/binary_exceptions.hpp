// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#if __cpp_exceptions

#include "glaze_ko/exceptions/core_exceptions.hpp"
#include "glaze_ko/glaze.hpp"

namespace glz_ko::ex
{
   template <class T, class Buffer>
   void read_beve(T& value, Buffer&& buffer)
   {
      auto ec = glz_ko::read_beve(value, std::forward<Buffer>(buffer));
      if (ec) {
         throw std::runtime_error("read_beve error");
      }
   }

   template <class T, class Buffer>
   [[nodiscard]] T read_beve(Buffer&& buffer)
   {
      const auto ex = glz_ko::read_beve<T>(std::forward<Buffer>(buffer));
      if (ex) {
         throw std::runtime_error("read_beve error");
      }
      return ex.value();
   }

   template <auto Opts = opts{}, class T>
   void read_file_beve(T& value, const sv file_name, auto&& buffer)
   {
      const auto ec = glz_ko::read_file_beve(value, file_name, buffer);
      if (ec) {
         throw std::runtime_error("read_file_beve error for: " + std::string(file_name));
      }
   }
}

namespace glz_ko::ex
{
   template <class T, class Buffer>
   void write_beve(T&& value, Buffer&& buffer)
   {
      glz_ko::write_beve(std::forward<T>(value), std::forward<Buffer>(buffer));
   }

   template <class T>
   [[nodiscard]] auto write_beve(T&& value)
   {
      return glz_ko::write_beve(std::forward<T>(value));
   }

   template <class T>
   void write_file_beve(T&& value, const std::string& file_name, auto&& buffer)
   {
      auto ec = glz_ko::write_file_beve(std::forward<T>(value), file_name, buffer);
      if (ec == glz_ko::error_code::file_open_failure) {
         throw std::runtime_error("file failed to open: " + file_name);
      }
      else if (ec) {
         throw std::runtime_error("write_file_beve error for: " + file_name);
      }
   }
}

#endif
