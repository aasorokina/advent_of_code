#include <algorithm>
#include <chrono>
#include <iostream>
#include <sstream>
#include <vector>

using ull = unsigned long long;
const char add = '+';
const char multiply = '*';

int main() {
  std::string line;
  std::vector<std::vector<char>> data;
  std::vector<char> operators;
  
  while (std::getline(std::cin, line)) {
    std::stringstream stream(line);
    std::vector<char> vec;
    char c;
    while (stream.get(c)) {
      if (c == ' ' || (c >= 48 && c <= 57)) {
        vec.push_back(c);
      } else if (c == add || c == multiply) {
        vec.push_back(' ');
        operators.push_back(c);
      }
    }
    vec.push_back(' ');
    data.push_back(vec);
  }
  
  int rows = data.size();
  int cols = data[0].size();
  std::vector<std::vector<char>> transposed(cols, std::vector<char>(rows));
  
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      transposed[j][i] = data[i][j];
    }
  }
  
  ull result = 0, temp = 1;
  for (int i = 0, j = 0, size = transposed.size(); i < size; ++i) {
    std::string str(transposed[i].begin(), transposed[i].end());
    if (str.find_first_not_of(' ') == std::string::npos) {
      if (operators[j] == add) temp -= 1;
      result += temp;
      temp = 1;
      ++j;
    } else {
      std::stringstream stream(str);
      int num;
      stream >> num;
      if (operators[j] == add) {
        temp += num;
      } else if (operators[j] == multiply) {
        temp *= num;
      }
    }
  }

  std::cout << result << '\n';
}