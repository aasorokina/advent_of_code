#include <iostream>
#include <vector>

using ull = unsigned long long;

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

  ull number;

  while (std::cin >> number) {
    for (int i = 0, size = ranges.size(); i < size; ++i) {
      auto& range = ranges[i];
      if (number >= range.first && number <= range.second) {
        result++;
        break;
      }
    }
  }

  std::cout << result << '\n';
}