#include "image.hpp"
#include "gtest/gtest.h"
#include "image.hpp"

using pixelator::Image;
using pixelator::Size;
// Test fixture for Image class
class ImageTest : public ::testing::Test {
 protected:
  Image img_default;    // Image with default constructor
  Image img_4x8{4, 8};  // Image with size 4x8

  const ftxui::Color yellowish{ftxui::Color::RGB(255, 200, 100)};

  // This function will be called before each test
  void SetUp() override {
    // Additional setup code can go here if needed
  }
};

// Test cases for Image class
TEST_F(ImageTest, DefaultConstructor) {
  // Test empty()
  EXPECT_TRUE(img_default.empty());

  // Test rows()
  EXPECT_EQ(img_default.rows(), 0);

  // Test cols()
  EXPECT_EQ(img_default.cols(), 0);

  // Test size()
  Size size = img_default.size();
  EXPECT_EQ(size.row, 0);
  EXPECT_EQ(size.col, 0);

  // Test at() should throw std::out_of_range for an empty image
  EXPECT_THROW(static_cast<void>(img_default.at(0, 0)), std::out_of_range);
}

// Test case for Image class with size 4x8
TEST_F(ImageTest, SizeConstructor) {
  // Test empty() for non-empty image
  EXPECT_FALSE(img_4x8.empty());

  // Test rows()
  EXPECT_EQ(img_4x8.rows(), 4);

  // Test cols()
  EXPECT_EQ(img_4x8.cols(), 8);

  // Test size()
  Size size = img_4x8.size();
  EXPECT_EQ(size.row, 4);
  EXPECT_EQ(size.col, 8);

  // Test at() for valid indices
  EXPECT_NO_THROW(static_cast<void>(img_4x8.at(2, 5)));

  // Test at() should throw std::out_of_range for invalid indices
  EXPECT_THROW(static_cast<void>(img_4x8.at(4, 8)), std::out_of_range);
}

// Test cases for Image class
TEST_F(ImageTest, CopyConstructor) {
  // Create a copy using the copy constructor
  Image img_copy(img_4x8);

  // Verify that the copy has the same size
  EXPECT_EQ(img_4x8.size().row, img_copy.size().row);
  EXPECT_EQ(img_4x8.size().col, img_copy.size().col);

  // Verify that the copy has a separate data array
  EXPECT_NE(&img_4x8.at(0, 0), &img_copy.at(0, 0));

  // Modify the original, and verify the copy is not affected
  img_4x8.at(2, 2) = yellowish;
  EXPECT_NE(img_4x8.at(2, 2), img_copy.at(2, 2));
}

TEST_F(ImageTest, CopyAssignment) {
  // Create an empty image
  Image img_empty;

  // Assign the content of img_4x8 to img_empty using copy assignment
  img_empty = img_4x8;

  // Verify that img_empty has the same size
  EXPECT_EQ(img_4x8.size().row, img_empty.size().row);
  EXPECT_EQ(img_4x8.size().col, img_empty.size().col);

  // Verify that img_empty has a separate data array
  EXPECT_NE(&img_4x8.at(0, 0), &img_empty.at(0, 0));

  // Modify the original, and verify the copy is not affected
  img_4x8.at(2, 2) = yellowish;
  EXPECT_NE(img_4x8.at(2, 2), img_empty.at(2, 2));
}

TEST_F(ImageTest, MoveConstructor) {
  // Create a move using the move constructor
  Image img_moved(std::move(img_4x8));

  // Verify that the moved-from object is in a valid but unspecified state
  EXPECT_TRUE(img_4x8.empty());

  // Verify that the moved image has the correct size
  EXPECT_EQ(img_moved.size().row, 4);
  EXPECT_EQ(img_moved.size().col, 8);

  // Verify that the moved image has the original data array
  EXPECT_EQ(&img_4x8.at(0, 0), &img_moved.at(0, 0));
}

TEST_F(ImageTest, MoveAssignment) {
  // Create an empty image
  Image img_empty;

  // Assign the content of img_4x8 to img_empty using move assignment
  img_empty = std::move(img_4x8);

  // Verify that img_empty has the correct size
  EXPECT_EQ(img_empty.size().row, 4);
  EXPECT_EQ(img_empty.size().col, 8);

  // Verify that img_empty has the original data array
  EXPECT_EQ(&img_empty.at(0, 0), &img_4x8.at(0, 0));

  // Verify that the moved-from object is in a valid but unspecified state
  EXPECT_TRUE(img_4x8.empty());
}

TEST_F(ImageTest, Modify) {
  img_4x8.at(2, 2) = yellowish;
  EXPECT_TRUE(img_4x8.at(2, 2) == yellowish);
}
