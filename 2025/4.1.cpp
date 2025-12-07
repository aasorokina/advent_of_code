#include <iostream>
#include <vector>

const char empty = '.';
const char paper = '@';

int main() {
  std::string line;
  std::vector<std::string> grid;
  unsigned long long result = 0;

  while (std::getline(std::cin, line)) grid.push_back(line);

  for (int i = 0, grid_size = grid.size(); i < grid_size; ++i) {
    int max_i = grid_size - 1;

    for (int j = 0, line_size = grid[i].size(); j < line_size; ++j) {
      if (grid[i][j] != paper) continue;

      int max_j = line_size - 1;
      int count = ((i > 0) && (grid[i - 1][j] == paper)) +
                  ((j > 0) && (grid[i][j - 1] == paper)) +
                  ((i < max_i) && (grid[i + 1][j] == paper)) +
                  ((j < max_j) && (grid[i][j + 1] == paper)) +
                  ((i > 0 && j > 0) && (grid[i - 1][j - 1] == paper)) +
                  ((i < max_i && j > 0) && (grid[i + 1][j - 1] == paper)) +
                  ((i > 0 && j < max_j) && (grid[i - 1][j + 1] == paper)) +
                  ((i < max_i && j < max_j) && (grid[i + 1][j + 1] == paper));

      if (count < 4) result++;
    }
  }
  std::cout << result << '\n';
}