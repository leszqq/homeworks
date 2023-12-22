#include <cstdint>
#include <ftxui/screen/color.hpp>
#include <vector>

#include "size.hpp"

namespace pixelator {
class Image {
 public:
  Image() = default;
  Image(int rows, int cols);

  // getters
  [[nodiscard]] auto empty() const noexcept -> bool;
  [[nodiscard]] auto rows() const noexcept -> int;
  [[nodiscard]] auto cols() const noexcept -> int;
  [[nodiscard]] auto size() const noexcept -> Size;
  [[nodiscard]] auto at(int row, int col) const -> ftxui::Color &;

 private:
  std::vector<std::vector<ftxui::Color>> data_{};
};
}  // namespace pixelator