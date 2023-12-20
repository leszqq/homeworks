#include <filesystem>
#include <ftxui/screen/color.hpp>

namespace pixelator {

struct Size {
  int row;
  int col;
};

class StbImageDataView {
 public:
  // ctors
  StbImageDataView();
  explicit StbImageDataView(std::filesystem::path &path);
  StbImageDataView(const StbImageDataView &other) = delete;
  StbImageDataView(StbImageDataView &&other) noexcept;

  ~StbImageDataView();

  // operators
  auto operator=(const StbImageDataView &other) -> StbImageDataView & = delete;
  auto operator=(StbImageDataView &&other) noexcept -> StbImageDataView &;

  // getters
  [[nodiscard]] auto size() const -> Size;
  [[nodiscard]] auto rows() const -> int;
  [[nodiscard]] auto cols() const -> int;

  [[nodiscard]] auto at(int row, int col) const -> ftxui::Color;

 private:
};
}  // namespace pixelator