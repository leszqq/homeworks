#include <string>
#include <vector>

namespace no_strings_attached {
auto Split(const std::string& str, const std::string& delimiter)
    -> std::vector<std::string>;

auto Split(const std::string& str,
           const std::string& delimiter,
           int number_of_chunks) -> std::vector<std::string>;

}