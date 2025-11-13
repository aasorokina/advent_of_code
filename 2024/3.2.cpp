#include <iostream>
#include <regex>

unsigned long long int get_answer(const std::string piece);

int main() {
  unsigned long long int res = 0;
  std::string input;
  std::string data;
  while (std::getline(std::cin, input)) data += input;

  const std::regex mul_reg("mul\\([0-9]+,[0-9]+\\)");
  const std::regex dont_reg("don't\\(\\)");
  const std::regex do_reg("do\\(\\)");

  std::string temp = data;
  if (std::smatch match; regex_search(temp, match, dont_reg)) {
    temp = match.prefix();
    data = match.suffix();

    for (std::smatch sm; regex_search(temp, sm, mul_reg);) {
      res += get_answer(sm.str());
      temp = sm.suffix();
    }
  }

  for (std::smatch s; regex_search(data, s, do_reg);) {
    std::string temp = s.suffix();
    std::smatch m;
    if (; regex_search(temp, m, dont_reg)) {
      temp = m.prefix();
      data = m.suffix();
    }

    for (std::smatch smm; regex_search(temp, smm, mul_reg);) {
      res += get_answer(smm.str());
      temp = smm.suffix();
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