#include <iostream>

int main() {
  std::string line;
  int result = 0;
  int dialVal = 50;

  while (std::getline(std::cin, line)) {

    int sign = (line[0] == 'L') ? -1 : 1;

    line.erase(0, 1);
    int number = std::stoi(line);
    int rotations = dialVal + number * sign;
    int newDialVal = (dialVal + sign * number + 100) % 100;

    if (newDialVal == 0) result++;

    dialVal = newDialVal;
  }

  std::cout << result << '\n';
}