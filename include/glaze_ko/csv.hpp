// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include "glaze_ko/core/as_array_wrapper.hpp"
// CSV cannot serialize a glz_ko::custom field - its columnar layout requires every struct field to be
// a container of row values, not a single value. This is included anyway so that attempting it
// fails inside the CSV writer, which names the real constraint, rather than on an undefined
// from/to specialization that reads like a missing include.
#include "glaze_ko/core/custom.hpp"
#include "glaze_ko/core/wrapper_traits.hpp"
#include "glaze_ko/csv/read.hpp"
#include "glaze_ko/csv/skip.hpp"
#include "glaze_ko/csv/write.hpp"
#include "glaze_ko/thread/atomic.hpp"
