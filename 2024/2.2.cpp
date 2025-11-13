#include <iostream>
#include <sstream>
#include <vector>

bool is_safe(std::vector<int> vec);

int main() {
  int safe = 0;

  std::vector<int> vec;
  std::string line;
  while (!std::cin.eof()) {
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int n;
    while (ss >> n) {
      vec.push_back(n);
    }

    if (is_safe(vec)) {
      safe++;
    } else {
      for (unsigned int i = 0; i < vec.size(); i++) {
        std::vector<int> temp = vec;
        temp.erase(temp.begin() + i);
        if (is_safe(temp)) {
          safe++;
          break;
        }
      }
    }

    vec.clear();
  }

  std::cout << safe << '\n';
  return 0;
}

bool is_safe(std::vector<int> vec) {
  int increasing = 0;
  int decreasing = 0;
  bool unsafe = false;
  for (unsigned int i = 1; i < vec.size(); i++) {
    if (vec[i] < vec[i - 1]) decreasing++;
    if (vec[i] > vec[i - 1]) increasing++;
    if (vec[i] == vec[i - 1] || abs(vec[i] - vec[i - 1]) > 3) unsafe = true;
  }
  return (unsafe == false && (decreasing == 0 || increasing == 0));
}