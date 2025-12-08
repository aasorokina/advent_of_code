#include <algorithm>
#include <iostream>
#include <vector>

using ull = unsigned long long;

struct {
  bool operator()(std::pair<ull, ull> a, std::pair<ull, ull> b) const {
    return a.first < b.first;
  }
} less_range_begin;

int main() {
  std::string line = "start";
  std::vector<std::pair<ull, ull>> ranges;
  ull result = 0;

  std::getline(std::cin, line);

  while (line != "") {
    size_t pos = line.find_first_of('-');
    ull first = std::stoull(std::string{line.begin(), line.begin() + pos});
    ull second = std::stoull(std::string{line.begin() + pos + 1, line.end()});
    ranges.push_back({first, second});
    std::getline(std::cin, line);
  }

  std::sort(ranges.begin(), ranges.end(), less_range_begin);

  for (int i = 0, size = ranges.size() - 1; i < size; ++i) {
    auto& range = ranges[i];
    auto& next_range = ranges[i + 1];

    if (range.second >= next_range.first) {
      next_range.first = range.first;
      next_range.second = std::max(range.second, next_range.second);
      range = {0, 0};
    }
  }

  for (int i = 0, size = ranges.size(); i < size; ++i) {
    auto& range = ranges[i];
    if (range.first == 0 && range.second == 0) continue;
    result += (range.second - range.first + 1);
  }

  std::cout << result << '\n';
}