#include <deque>
#include <iostream>
#include <set>
#include <vector>

typedef struct {
  int xx, xy, mx, my, ax, ay, sx, sy;
} coords;

bool operator<(const coords &a, const coords &b) {
  if (a.xx != b.xx) return a.xx < b.xx;
  if (a.xy != b.xy) return a.xy < b.xy;
  if (a.mx != b.mx) return a.mx < b.mx;
  if (a.my != b.my) return a.my < b.my;
  if (a.ax != b.ax) return a.ax < b.ax;
  if (a.ay != b.ay) return a.ay < b.ay;
  if (a.sx != b.sx) return a.sx < b.sx;
  return a.sy < b.sy;
}

unsigned long long int count_xmas(std::vector<std::vector<char>> &vec, int x,
                                  int y, std::set<coords> &xmas);

bool accert_horizontal(std::vector<std::vector<char>> &vec, int x, int y);
bool accert_vertical(std::vector<std::vector<char>> &vec, int x, int y);
bool accert_left_diagonal(std::vector<std::vector<char>> &vec, int x, int y);
bool accert_right_diagonal(std::vector<std::vector<char>> &vec, int x, int y);

int main() {
  unsigned long long int res = 0;
  std::vector<std::vector<char>> vec(140);
  std::set<coords> xmas;
  std::deque<coords> temp;

  char c;
  for (int i = 0; i < 140; i++) {
    for (int j = 0; j < 140; j++) {
      std::cin >> c;
      vec[i].push_back(c);
    }
  }

  for (int i = 0; i < 137; i++) {
    for (int j = 0; j < 137; j++) {
      res += count_xmas(vec, i, j, xmas);
    }
  }

  std::cout << res << '\n';
  return 0;
}

unsigned long long int count_xmas(std::vector<std::vector<char>> &vec, int x,
                                  int y, std::set<coords> &xmas) {
  unsigned long long int res = 0;
  for (int i = 0; i < 4; i++) {
    if ((accert_horizontal(vec, x + i, y)) &&
        (xmas.count({x + i, y, x + i, y + 1, x + i, y + 2, x + i, y + 3}) ==
         0)) {
      res++;
      xmas.insert({x + i, y, x + i, y + 1, x + i, y + 2, x + i, y + 3});
    }
    if (accert_vertical(vec, x, y + i) &&
        (xmas.count({x, y + i, x + 1, y + i, x + 2, y + i, x + 3, y + i}) ==
         0)) {
      res++;
      xmas.insert({x, y + i, x + 1, y + i, x + 2, y + i, x + 3, y + i});
    }
  }
  if (accert_left_diagonal(vec, x, y)) res++;
  if (accert_right_diagonal(vec, x, y)) res++;
  return res;
}

bool accert_horizontal(std::vector<std::vector<char>> &vec, int x, int y) {
  return ((vec[x][y] == 'X' && vec[x][y + 1] == 'M' && vec[x][y + 2] == 'A' &&
           vec[x][y + 3] == 'S') ||
          (vec[x][y] == 'S' && vec[x][y + 1] == 'A' && vec[x][y + 2] == 'M' &&
           vec[x][y + 3] == 'X'));
}

bool accert_vertical(std::vector<std::vector<char>> &vec, int x, int y) {
  return ((vec[x][y] == 'X' && vec[x + 1][y] == 'M' && vec[x + 2][y] == 'A' &&
           vec[x + 3][y] == 'S') ||
          (vec[x][y] == 'S' && vec[x + 1][y] == 'A' && vec[x + 2][y] == 'M' &&
           vec[x + 3][y] == 'X'));
}

bool accert_left_diagonal(std::vector<std::vector<char>> &vec, int x, int y) {
  return ((vec[x][y] == 'X' && vec[x + 1][y + 1] == 'M' &&
           vec[x + 2][y + 2] == 'A' && vec[x + 3][y + 3] == 'S') ||
          (vec[x][y] == 'S' && vec[x + 1][y + 1] == 'A' &&
           vec[x + 2][y + 2] == 'M' && vec[x + 3][y + 3] == 'X'));
}

bool accert_right_diagonal(std::vector<std::vector<char>> &vec, int x, int y) {
  return ((vec[x][y + 3] == 'X' && vec[x + 1][y + 2] == 'M' &&
           vec[x + 2][y + 1] == 'A' && vec[x + 3][y] == 'S') ||
          (vec[x][y + 3] == 'S' && vec[x + 1][y + 2] == 'A' &&
           vec[x + 2][y + 1] == 'M' && vec[x + 3][y] == 'X'));
}