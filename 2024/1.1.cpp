#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> first, second;
  int a, b, res = 0;
  while (std::cin >> a >> b) {
    first.push_back(a);
    second.push_back(b);
  }

  std::sort(first.begin(), first.end());
  std::sort(second.begin(), second.end());

  for(unsigned int i = 0; i < first.size(); i++){
    res += abs(first[i] - second[i]);
  }

  std::cout << res << '\n';

  return 0;
}