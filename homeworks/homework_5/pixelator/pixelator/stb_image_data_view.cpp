#include "stb_image_data_view.hpp"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include <stb/stb_image.h>

using std::vector;

namespace pixelator {
StbImageDataView::StbImageDataView(const std::filesystem::path &path) {
  int rows{};
  int cols{};
  int channels{};
  auto *char_image{stbi_load(path.c_str(), &cols, &rows, &channels, 0)};
  if (char_image == nullptr || (channels != 4 && channels != 3)) {
    throw std::ios_base::failure("Failed to open file: " + path.native());
  }

  image_data_.resize(rows, vector<Color>(cols));

  size_t offset{};
  for (int row{}; row < rows; row++) {
    for (int col{}; col < cols; col++) {
      image_data_[row][col] = Color{
          char_image[offset], char_image[offset + 1], char_image[offset + 2]};
      offset += channels;
    }
  }
  free(char_image);
}

auto StbImageDataView::size() const -> Size {
  if (image_data_.empty()) { return Size{0, 0}; }

  if (image_data_.at(0).empty()) { return Size{0, 0}; }

  return Size{static_cast<int>(image_data_.size()),
              static_cast<int>(image_data_.at(0).size())};
}

auto StbImageDataView::rows() const -> int {
  return static_cast<int>(image_data_.size());
}

auto StbImageDataView::cols() const -> int {
  if (image_data_.empty()) { return 0; }

  return image_data_.at(0).size();
}

auto StbImageDataView::at(int row, int col) const -> ftxui::Color {
  Color rgb = image_data_.at(row).at(col);
  return ftxui::Color{rgb.red, rgb.green, rgb.blue};
}

}  // namespace pixelator