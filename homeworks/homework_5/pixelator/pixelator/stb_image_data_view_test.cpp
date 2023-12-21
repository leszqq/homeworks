#include "stb_image_data_view.hpp"
#include "gtest/gtest.h"

// Test fixture for stb_image_data_view
class StbImageDataViewTest : public ::testing::Test {
 protected:
  // You may want to add any setup code here, if needed.
};

// Test default constructor
TEST_F(StbImageDataViewTest, DefaultConstructor) {
  pixelator::StbImageDataView image;

  // Test rows and cols
  ASSERT_EQ(image.rows(), 0);
  ASSERT_EQ(image.cols(), 0);

  // Test size
  ASSERT_EQ(image.size().row, 0);
  ASSERT_EQ(image.size().col, 0);

  // Test calling at() with any argument should throw std::out_of_range
  ASSERT_THROW(static_cast<void>(static_cast<void>(image.at(0, 0))),
               std::out_of_range);
  ASSERT_THROW(static_cast<void>(static_cast<void>(image.at(1, 1))),
               std::out_of_range);
  // Add more test cases as needed
}

// Test constructor with path to non-existing file
TEST_F(StbImageDataViewTest, ConstructorWithNonExistingPath) {
  const std::filesystem::path non_existing_path(
      "path/to/non_existing_image.png");
  ASSERT_THROW(pixelator::StbImageDataView image(non_existing_path),
               std::ios_base::failure);
}

// Test constructor with path and image data
TEST_F(StbImageDataViewTest, ConstructorWithPathAndImageData) {
  const char *data_dir_path = std::getenv("DATADIR");
  const std::filesystem::path test_image_path{std::string(data_dir_path) +
                                              "test.png"};
  pixelator::StbImageDataView image(test_image_path);

  std::cout << "path is: " << std::filesystem::current_path() << std::endl;

  // Test rows and cols
  ASSERT_EQ(image.rows(), 6);
  ASSERT_EQ(image.cols(), 4);

  // Test size
  ASSERT_EQ(image.size().row, 6);
  ASSERT_EQ(image.size().col, 4);

  // Test getter functions
  ASSERT_EQ(image.rows(), 6);
  ASSERT_EQ(image.cols(), 4);

  // Test color retrieval
  ASSERT_EQ(image.at(0, 0), ftxui::Color(0, 0, 0));
  ASSERT_EQ(image.at(0, 1), ftxui::Color(0, 0, 0));
  ASSERT_EQ(image.at(0, 2), ftxui::Color(0, 0, 0));
  ASSERT_EQ(image.at(1, 0), ftxui::Color(0, 0, 0));
  ASSERT_EQ(image.at(1, 1), ftxui::Color(0, 0, 0));
  ASSERT_EQ(image.at(1, 2), ftxui::Color(0, 0, 0));
  ASSERT_EQ(image.at(2, 0), ftxui::Color(0, 0, 0));
  ASSERT_EQ(image.at(2, 1), ftxui::Color(0, 0, 0));
  ASSERT_EQ(image.at(2, 2), ftxui::Color(0, 0, 0));
  ASSERT_EQ(image.at(3, 0), ftxui::Color(255, 255, 255));
  ASSERT_EQ(image.at(3, 1), ftxui::Color(255, 255, 255));
  ASSERT_EQ(image.at(3, 2), ftxui::Color(255, 255, 255));
  ASSERT_EQ(image.at(4, 0), ftxui::Color(255, 255, 255));
  ASSERT_EQ(image.at(4, 1), ftxui::Color(255, 255, 255));
  ASSERT_EQ(image.at(4, 2), ftxui::Color(255, 255, 255));
  ASSERT_EQ(image.at(5, 0), ftxui::Color(255, 255, 255));
  ASSERT_EQ(image.at(5, 1), ftxui::Color(255, 255, 255));
  ASSERT_EQ(image.at(5, 2), ftxui::Color(255, 255, 255));

  ASSERT_EQ(image.at(3, 3), ftxui::Color(255, 255, 255));
  // Add more test cases as needed
}

// Test move constructor
TEST_F(StbImageDataViewTest, MoveConstructor) {
  const char *data_dir_path = std::getenv("DATADIR");
  const std::filesystem::path test_image_path{std::string(data_dir_path) +
                                              "test.png"};
  pixelator::StbImageDataView original_image(test_image_path);

  // Save the original state before moving
  const int original_rows = original_image.rows();
  const int original_cols = original_image.cols();

  // Move construct another instance using std::move
  pixelator::StbImageDataView moved_image(std::move(original_image));

  // After moving, the original image should have zero rows and cols
  ASSERT_EQ(original_image.rows(), 0);
  ASSERT_EQ(original_image.cols(), 0);

  // The moved image should have the original dimensions
  ASSERT_EQ(moved_image.rows(), original_rows);
  ASSERT_EQ(moved_image.cols(), original_cols);

  // Test calling at() with any argument on the moved image
  ASSERT_NO_THROW(static_cast<void>(moved_image.at(0, 0)));
  ASSERT_NO_THROW(static_cast<void>(moved_image.at(1, 1)));

  ASSERT_THROW(static_cast<void>(original_image.at(0, 0)), std::out_of_range);
  ASSERT_THROW(static_cast<void>(original_image.at(1, 1)), std::out_of_range);
  // Add more test cases as needed
}

// Add more test cases for other functions as needed