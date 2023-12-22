#include "image.hpp"

using std::vector;

namespace pixelator {
Image::Image(int rows, int cols)
    : data_{static_cast<size_t>(rows),
            vector<ftxui::Color>{static_cast<size_t>(cols)}} {}

auto Image::empty() const noexcept -> bool { return data_.empty(); }
auto Image::rows() const noexcept -> int { return this->size().row; }
auto Image::cols() const noexcept -> int { return this->size().col; }
auto Image::size() const noexcept -> Size {
  if (data_.empty()) { return Size{0, 0}; }

  return Size{static_cast<int>(data_.size()),
              static_cast<int>(data_.at(0).size())};
}
auto Image::at(int row, int col) -> ftxui::Color& {
  return data_.at(row).at(col);
}
}  // namespace pixelator