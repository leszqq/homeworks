#include <iostream>
#include <string>
#include <vector>

#include "no_strings_attached/string_trim.h"

using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::string_literals::operator""s;
using std::vector;

auto main() -> int {
  cout << "Example program that trims strings.\n"s;
  cout << "Please enter a string:\n"s;

  string line{};
  getline(cin, line);
  const string trimmed =
      no_strings_attached::Trim(line, ' ', no_strings_attached::Side::kBoth);
  cout << "Your trimmed string: '" << trimmed << "'\n";
  return 0;
}