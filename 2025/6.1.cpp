#include <iostream>
#include <sstream>
#include <vector>

using ull = unsigned long long;
const char add = '+';
const char multiply = '*';

int main() {
  std::string line;
  std::vector<std::vector<int>> numbers;
  std::vector<char> operators;
  ull result = 0;

  while (std::getline(std::cin, line)) {
    std::stringstream stream(line);

    if (line.find(add) == line.npos && line.find(multiply) == line.npos) {
      std::vector<int> vec;
      int num;
      while (stream >> num) vec.push_back(num);
      numbers.push_back(vec);
    } else {
      char c;
      while (stream >> c) operators.push_back(c);
    }
  }

  for (int i = 0, size = numbers[0].size(); i < size; ++i) {
    ull temp = 0;

    if (operators[i] == add) {
      for (int j = 0, vecSize = numbers.size(); j < vecSize; ++j)
        temp += numbers[j][i];

    } else if (operators[i] == multiply) {
      temp = 1;
      for (int j = 0, vecSize = numbers.size(); j < vecSize; ++j)
        temp *= numbers[j][i];
    }

    result += temp;
  }

  std::cout << result << '\n';
}