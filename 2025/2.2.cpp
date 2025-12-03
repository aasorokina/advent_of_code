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

      for (int parts = size; parts > 1; parts--) {
        
        if (size % parts == 0) {
          int partSize = size / parts;
          std::string prevStr = strNum.substr(0, partSize);
          bool equalStrings = true;

          for (int pos = partSize; pos < size; pos += partSize) {
            std::string str = strNum.substr(pos, partSize);

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