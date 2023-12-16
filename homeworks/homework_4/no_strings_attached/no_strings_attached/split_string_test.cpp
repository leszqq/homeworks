#include "split_string.h"

#include <string>
#include <vector>

#include "gtest/gtest.h"

using no_strings_attached::Split;
using std::string;
using std::vector;

TEST(SplitStringTest, EmptyString) {
  const string empty_str;
  const string delimiter{" "};
  const auto splitted = Split(empty_str, delimiter);
  EXPECT_TRUE(splitted.empty());
}

TEST(SplitStringTest, EmptyDelimiter) {
  const string str{"test"};
  const string delimiter{};
  const auto splitted = Split(str, delimiter);
  EXPECT_TRUE(splitted.empty());
}

TEST(SplitStringTest, CommonUsage) {
  const string str{"t*e*s*t"};
  const string delimiter{"*"};
  const auto splitted = Split(str, delimiter);
  EXPECT_TRUE((splitted == vector<string>{"t", "e", "s", "t"}));
}

TEST(SplitStringTest, BorderDelimiters) {
  const string str{" t e s t "};
  const string delimiter{" "};
  const auto splitted = Split(str, delimiter);
  EXPECT_TRUE((splitted == vector<string>{"", "t", "e", "s", "t"}));
}

TEST(SplitStringTest, TrimmeredSplit) {
  const string str{"txexsxt"};
  const auto splitted = Split(str, "x", 3);
  EXPECT_TRUE((splitted == vector<string>{"t", "e", "s"}));
}