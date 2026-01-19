#include <iostream>
#include <vector>

int main() {
  std::string line;
  std::string prevLine;
  int result = 0;

  while (std::getline(std::cin, line)) {
    for (int i = 0, size = line.size(); i < size; i++) {
      if (line[i] == 'S') line[i] = '|';
      if (prevLine.size() == 0) continue;
      if (prevLine[i] == '|' && line[i] == '.') {
        line[i] = '|';
      }
      if (prevLine[i] == '|' && line[i] == '^') {
        line[i - 1] = line[i + 1] = '|';
        result++;
      }
    }
    prevLine = line;
  }

  std::cout << result << "\n";
  return 0;
}