#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::string line;
  int batteries = 12;
  unsigned long long result = 0;

  while (std::getline(std::cin, line)) {
    std::vector<int> vec;
    vec.reserve(batteries);
    int i = line.size() - batteries;

    for (; i < line.size(); i++) vec.push_back(line[i] - '0');

    for (i = line.size() - batteries - 1; i >= 0; i--) {
      int num = line[i] - '0';

      for (int j = 0; j < vec.size(); j++) {
        if (num >= vec[j])
          std::swap(vec[j], num);
        else
          break;
      }
    }

    unsigned long long value = 0;
    for (int x : vec) value = value * 10 + x;
    result += value;
  }
  std::cout << result << '\n';
}