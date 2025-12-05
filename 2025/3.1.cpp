#include <algorithm>
#include <iostream>

int main() {
  std::string line;
  int result = 0;

  while (std::getline(std::cin, line)) {
    int firstNum = -1, secondNum = -1;
    size_t firstPos = 0, size = line.size();

    for (size_t i = 0; i < size; ++i) {
      int num = line[i] - '0';
      if (num > firstNum) {
        firstNum = num;
        firstPos = i;
      }
    }

    if (firstPos == size - 1) {
      for (size_t i = 0; i < size - 1; ++i)
        secondNum = std::max(secondNum, line[i] - '0');
      result += secondNum * 10 + firstNum;
    } else {
      for (size_t i = firstPos + 1; i < size; ++i)
        secondNum = std::max(secondNum, line[i] - '0');
      result += firstNum * 10 + secondNum;
    }
  }

  std::cout << result << '\n';
}