// <!--
// The MIT License (MIT)
//
// Copyright (c) 2024 Kris Jusiak <kris@jusiak.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
module;
#include "prof"
export module prof;

export namespace prof {
  /**
   * template<class T>
   * concept profiler_like = requires(T t) {
   *   t.start();
   *   t.stop();
   * };
   */
  using prof::profiler_like;

  #if __has_include(<fcntl.h>) and __has_include(<unistd.h>)
  /*
  * class perf {
  *  public:
  *   constexpr explicit perf(std::string&& control);
  *   constexpr perf(const perf&) = delete;
  *   constexpr perf(perf&& other);
  *   constexpr ~perf() noexcept;
  *   constexpr auto start();
  *   constexpr auto stop();
  * };
  */
  using prof::perf;
  #endif

  #if __has_include(<ittnotify.h>)
  /*
  * class vtune {
  *  public:
  *   constexpr explicit vtune(std::string&& domain, std::string&& task);
  *   constexpr vtune(vtune&&) = default;
  *   constexpr vtune(const vtune&) = delete;
  *   constexpr ~vtune() noexcept;
  *   constexpr auto start();
  *   constexpr auto stop();
  * };
  */
  using prof::vtune;
  #endif

  #if __has_include(<AMDProfileController.h>)
  /*
  * class uprof {
  *  public:
  *   constexpr uprof();
  *   constexpr uprof(uprof&&) = default;
  *   constexpr uprof(const uprof&) = delete;
  *   constexpr auto start();
  *   constexpr auto stop();
  * };
  */
  using prof::uprof;
  #endif

  #if __has_include(<gperftools/profiler.h>)
  /*
  * class gperf {
  *  public:
  *   constexpr explicit gperf(std::string&& fname);
  *   constexpr gperf(gperf&&) = default;
  *   constexpr gperf(const gperf&) = delete;
  *   constexpr ~gperf() noexcept;
  *   constexpr auto start();
  *   constexpr auto stop();
  *   constexpr void flush();
  * };
  */
  using prof::gperf;
  #endif

  #if __has_include(<xray/xray_interface.h>) and \
      __has_include(<xray/xray_log_interface.h>)
  /*
  * class xray {
  *  public:
  *   constexpr explicit xray(
  *     std::string&& mode = "xray-fdr",
  *     std::string&& cfg = "xray_logfile_base=xray-log.%"
  *   );
  *   constexpr xray(xray&&) = default;
  *   constexpr xray(const xray&) = delete;
  *   constexpr ~xray() noexcept;
  *   [[clang::xray_never_instrument]] constexpr auto start();
  *   [[clang::xray_never_instrument]] constexpr auto stop();
  *   [[clang::xray_never_instrument]] constexpr void flush();
  * };
  */
  using prof::xray;
  #endif

  #if __has_include(<valgrind/callgrind.h>)
  /*
  * class callgrind {
  *  public:
  *   constexpr explicit callgrind(std::string&& profile);
  *   constexpr callgrind(callgrind&&) = default;
  *   constexpr callgrind(const callgrind&) = delete;
  *   constexpr ~callgrind() noexcept;
  *
  *   constexpr auto start();
  *   constexpr auto stop();
  *   constexpr void flush();
  * };
  */
  using prof::callgrind;
  #endif
} // namespace prof

// -*- mode: c++; -*-
// vim: set filetype=cpp:
