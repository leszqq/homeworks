#include <iostream>
#include <string>

#include "no_strings_attached/split_string.h"

using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::string_literals::operator""s;
using std::vector;

auto main() -> int {
  cout << "Example program that splits strings.\n"s;
  cout << "Please enter a string:\n"s;

  string line{};
  getline(cin, line);
  vector<string> splitted{no_strings_attached::Split(line, " "s)};
  cout << "Your split string:"s;
  for (const auto &token : splitted) { cout << " '"s << token << "'"; }
  cout << "\n";
  return 0;
}