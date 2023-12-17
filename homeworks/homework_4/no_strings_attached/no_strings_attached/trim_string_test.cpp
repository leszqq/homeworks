#include "gtest/gtest.h"
#include "string_trim.h"

using no_strings_attached::Side;
using no_strings_attached::Trim;
using std::string;

TEST(TrimStringTest, ExampleTest1) {
  string result = Trim("  hello ", ' ', Side::kLeft);
  EXPECT_STREQ(result.c_str(), "hello ");
}

TEST(TrimStringTest, ExampleTest2) {
  string result = Trim("  hello ", ' ', Side::kRight);
  EXPECT_STREQ(result.c_str(), "  hello");
}

TEST(TrimStringTest, ExampleTest3) {
  string result = Trim("  hello ", ' ', Side::kBoth);
  EXPECT_STREQ(result.c_str(), "hello");
}

TEST(TrimStringTest, ExampleTest4) {
  string result = Trim("hello", 'h', Side::kLeft);
  EXPECT_STREQ(result.c_str(), "ello");
}
