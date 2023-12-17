#include <cassert>

#include "string_trim.h"

using no_strings_attached::Side;
using std::string;

namespace {
auto TrimLeft(const string& str, char char_to_trim) -> std::string;
auto TrimRight(const string& str, char char_to_trim) -> std::string;
auto DoTrim(const string& str, char char_to_trim, Side side) -> std::string;
}  // namespace

namespace no_strings_attached {
auto Trim(const std::string& str, char char_to_trim, Side side) -> std::string {
  return DoTrim(str, char_to_trim, side);
}

auto Trim(const std::string& str) { return DoTrim(str, ' ', Side::kBoth); }
}  // namespace no_strings_attached

namespace {
auto TrimLeft(const string& str, char char_to_trim) -> std::string {
  string trimmed{str};

  while (true) {
    if (trimmed.empty()) { return string{}; }

    if (trimmed.front() != char_to_trim) { return trimmed; }

    trimmed.erase(0, 1);
  }
}

auto TrimRight(const string& str, char char_to_trim) -> std::string {
  string trimmed{str};

  while (true) {
    if (trimmed.empty()) { return string{}; }

    if (trimmed.back() != char_to_trim) { return trimmed; }

    trimmed.pop_back();
  }
}

auto DoTrim(const string& str, char char_to_trim, Side side) -> std::string {
  if (str.empty()) { return string{}; };

  string result{};
  switch (side) {
    case Side::kLeft: {
      result = TrimLeft(str, char_to_trim);
      break;
    }
    case Side::kRight: {
      result = TrimRight(str, char_to_trim);
      break;
    }
    case Side::kBoth: {
      result = TrimRight(str, char_to_trim);
      result = TrimLeft(result, char_to_trim);
    }
    default: {
      assert(false);
      break;
    }
  }
  return result;
}
}  // namespace