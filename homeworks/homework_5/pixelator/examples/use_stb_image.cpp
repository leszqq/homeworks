#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include <stb/stb_image.h>

#include <filesystem>
#include <iostream>

using std::cout;

// A dummy color structure
struct Color {
  int red;
  int green;
  int blue;
};

auto main(int argc, char** argv) -> int {
  if (argc < 2) { std::cerr << "No image provided.\n"; }
  const std::filesystem::path image_path{argv[1]};
  if (!std::filesystem::exists(image_path)) {
    std::cerr << "No image file: " << image_path << std::endl;
  }

  // Load the data
  int width{};
  int height{};
  int channels{};
  auto image_data{stbi_load(image_path.c_str(), &width, &height, &channels, 0)};
  cout << "Loaded image of size: [" << width << ", " << height << "] with "
       << channels << " channels\n";
  if (!image_data) {
    std::cerr << "Failed to load image data from file: " << image_path
              << std::endl;
  }

  int query_x = 2;
  int query_y = 3;
  const auto index{channels * (query_y * width + query_x)};
  const Color color{
      image_data[index], image_data[index + 1], image_data[index + 2]};
  std::cout << "Color at pixel: [" << query_x << ", " << query_y << "] = RGB: ("
            << color.red << ", " << color.green << ", " << color.blue << ")\n";

  // We must explicitly free the memory allocated for this image.
  // The reason for this is that stb_image is a C library,
  // which has no classes and no RAII in the form about which we talked before.
  // Now you see why people want to write C++ and not C? ;)
  stbi_image_free(image_data);

  return 0;
}
