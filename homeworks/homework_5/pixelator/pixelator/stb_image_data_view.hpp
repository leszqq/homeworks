#include <filesystem>
#include <ftxui/screen/color.hpp>
#include <vector>

namespace pixelator {

struct Size {
  int row;
  int col;
};

class StbImageDataView {
 public:
  // ctors
  StbImageDataView() = default;
  explicit StbImageDataView(const std::filesystem::path &path);

  // can't be copied
  StbImageDataView(const StbImageDataView &other) = delete;
  auto operator=(const StbImageDataView &other) -> StbImageDataView & = delete;

  // can be moved
  StbImageDataView(StbImageDataView &&other) = default;
  auto operator=(StbImageDataView &&other) -> StbImageDataView & = default;

  ~StbImageDataView() = default;

  // getters
  [[nodiscard]] auto size() const -> Size;
  [[nodiscard]] auto rows() const -> int;
  [[nodiscard]] auto cols() const -> int;

  [[nodiscard]] auto at(int row, int col) const -> ftxui::Color;

 private:
  struct Color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
  };
  std::vector<std::vector<Color>> image_data_{};
};
}  // namespace pixelator