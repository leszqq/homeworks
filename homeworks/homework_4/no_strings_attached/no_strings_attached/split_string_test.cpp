#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "string_split.h"

using no_strings_attached::Split;
using std::string;
using std::vector;

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

TEST(SplitStringTest, ExampleTest1) {
  EXPECT_TRUE((Split("hello world", " ") == vector<string>{"hello", "world"}));
}

TEST(SplitStringTest, ExampleTest2) {
  EXPECT_TRUE((Split("aaabaaba", "aa") == vector<string>{"", "ab", "ba"}));
}

TEST(SplitStringOverloadedTest, ExampleTest1) {
  EXPECT_TRUE((Split("hello world", " ", 1) == vector<string>{"hello"}));
}

TEST(SplitStringOverloadedTest, ExampleTest2) {
  EXPECT_TRUE(
      (Split("hello world", " ", 2) == vector<string>{"hello", "world"}));
}

TEST(SplitStringOverloadedTest, ExampleTest3) {
  EXPECT_TRUE((Split("aaabaaba", "aa", 2) == vector<string>{"", "ab"}));
}
