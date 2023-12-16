#include "split_string.h"

#include <iostream>

using std::string;
using std::vector;

namespace {

auto SubstringFound(string::size_type pos) -> bool;
auto IsNextDelimiter(const string& str,
                     const string& delimiter,
                     string::size_type start_pos) -> bool;
auto GetNextTokenLength(const string& str,
                        const string& delimiter,
                        string::size_type start_pos) -> string::size_type;
auto GetNextToken(const string& str,
                  const string& delimiter,
                  string::size_type start_pos) -> string;
auto IsNextToken(const string& str, string::size_type start_pos) -> bool;
auto DoSplit(const string& str, const string& delimiter) -> vector<string>;
}  // namespace

namespace no_strings_attached {

auto Split(const std::string& str, const std::string& delimiter)
    -> std::vector<std::string> {
  return DoSplit(str, delimiter);
}

auto Split(const std::string& str,
           const std::string& delimiter,
           int number_of_chunks) -> std::vector<std::string> {
  std::vector<std::string> splitted{DoSplit(str, delimiter)};
  splitted.resize(number_of_chunks);
  return splitted;
}
}  // namespace no_strings_attached

namespace {
auto SubstringFound(string::size_type pos) -> bool {
  return string::npos != pos;
}

auto IsNextDelimiter(const string& str,
                     const string& delimiter,
                     string::size_type start_pos) -> bool {
  const string::size_type found_pos = str.find(delimiter, start_pos);
  return SubstringFound(found_pos);
}

auto GetNextTokenLength(const string& str,
                        const string& delimiter,
                        string::size_type start_pos) -> string::size_type {
  string::size_type end_pos = IsNextDelimiter(str, delimiter, start_pos)
                                  ? str.find(delimiter, start_pos)
                                  : str.length();
  return end_pos - start_pos;
}

auto GetNextToken(const string& str,
                  const string& delimiter,
                  string::size_type start_pos) -> string {
  string::size_type token_length =
      GetNextTokenLength(str, delimiter, start_pos);
  return str.substr(start_pos, token_length);
}

auto IsNextToken(const string& str, string::size_type start_pos) -> bool {
  return start_pos < str.length();
}

auto DoSplit(const string& str, const string& delimiter) -> vector<string> {
  if (delimiter.empty()) { return vector<string>{}; }

  vector<string> splitted{};
  string::size_type pos{0};

  while (IsNextToken(str, pos)) {
    splitted.push_back(GetNextToken(str, delimiter, pos));
    pos += GetNextTokenLength(str, delimiter, pos) + delimiter.length();
  }
  return splitted;
}
}  // namespace