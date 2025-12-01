#include <iostream>

int main() {
  std::string line;
  int result = 0;
  int dialVal = 50;

  while (std::getline(std::cin, line)) {
    
    int sign = (line[0] == 'L') ? -1 : 1;
    line.erase(0, 1);

    int number = std::stoi(line);
    int fullCircles = number / 100;

    int remainder = number % 100;
    for (int i = 0; i < remainder; i++) {
      dialVal = (dialVal + sign + 100) % 100;
      if (dialVal == 0) result++;
    }

    result += fullCircles;
  }

  std::cout << result << '\n';
}