#include <iostream>
#include <set>

int main() {
  std::multiset<int> first, second;
  int a, b, res = 0;
  while (std::cin >> a >> b) {
    first.insert(a);
    second.insert(b);
  }

  for(auto iter = first.begin(); iter != first.end(); iter++){
    res += *(iter) * (second.count(*iter));
  }

  std::cout << res << '\n';

  return 0;
}