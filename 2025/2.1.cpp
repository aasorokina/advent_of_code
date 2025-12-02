#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  uint64_t result = 0, first, second;
  std::string line;
  std::getline(std::cin, line);
  std::stringstream stream(line);
  char symbol;

  while (stream >> first >> symbol >> second) {

    for (uint64_t i = first; i <= second; i++) {
      std::string strNum = std::to_string(i);
      int halfSize = strNum.size() / 2;
      if (strNum.size() % 2 == 0 &&
          strNum.substr(0, halfSize) == strNum.substr(halfSize, halfSize)) {
        result += i;
      }
    }
    stream >> symbol;
  }

  std::cout << result << '\n';
}