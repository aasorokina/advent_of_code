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
      int size = strNum.size();

      for (int divider = size; divider > 1; divider--) {
        
        if (size % divider == 0) {
          int partSize = size / divider;
          std::string prevStr = strNum.substr(0, partSize);
          bool equalStrings = true;

          for (int j = partSize; j < size; j += partSize) {
            std::string str = strNum.substr(j, partSize);

            if (str != prevStr) {
              equalStrings = false;
              break;
            }
          }

          if (equalStrings) {
            result += i;
            break;
          }
        }
      }
    }
    stream >> symbol;
  }

  std::cout << result << '\n';
}