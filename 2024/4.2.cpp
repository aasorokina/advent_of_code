#include <iostream>
#include <vector>

bool accert_left_diagonal(std::vector<std::vector<char>> &vec, int x, int y);
bool accert_right_diagonal(std::vector<std::vector<char>> &vec, int x, int y);

int main() {
  unsigned long long int res = 0;
  std::vector<std::vector<char>> vec(140);

  char c;
  for (int i = 0; i < 140; i++) {
    for (int j = 0; j < 140; j++) {
      std::cin >> c;
      vec[i].push_back(c);
    }
  }

  for (int i = 0; i < 138; i++) {
    for (int j = 0; j < 138; j++) {
      if (accert_left_diagonal(vec, i, j) && accert_right_diagonal(vec, i, j))
        res++;
    }
  }

  std::cout << res << '\n';
  return 0;
}

bool accert_left_diagonal(std::vector<std::vector<char>> &vec, int x, int y) {
  return ((vec[x][y] == 'M' && vec[x + 1][y + 1] == 'A' &&
           vec[x + 2][y + 2] == 'S') ||
          (vec[x][y] == 'S' && vec[x + 1][y + 1] == 'A' &&
           vec[x + 2][y + 2] == 'M'));
}

bool accert_right_diagonal(std::vector<std::vector<char>> &vec, int x, int y) {
  return ((vec[x][y + 2] == 'M' && vec[x + 1][y + 1] == 'A' &&
           vec[x + 2][y] == 'S') ||
          (vec[x][y + 2] == 'S' && vec[x + 1][y + 1] == 'A' &&
           vec[x + 2][y] == 'M'));
}