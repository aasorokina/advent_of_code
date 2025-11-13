#include <iostream>
#include <regex>

unsigned long long int get_answer(const std::string piece);

int main() {
  unsigned long long int res = 0;
  std::string input;
  const std::regex reg("mul\\([0-9]+,[0-9]+\\)");

  while (std::getline(std::cin, input)) {
    for (std::smatch sm; regex_search(input, sm, reg);) {
      res += get_answer(sm.str());
      input = sm.suffix();
    }
  }

  std::cout << res << '\n';

  return 0;
}

unsigned long long int get_answer(std::string piece) {
  unsigned long long int answer = 1;
  const std::regex reg("[0-9]+");

  for (std::smatch sm; regex_search(piece, sm, reg);) {
    answer *= std::stoi(sm.str());
    piece = sm.suffix();
  }
  return answer;
}