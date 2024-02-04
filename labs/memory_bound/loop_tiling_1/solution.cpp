#include "solution.hpp"
#include <algorithm>

const int TILE_SIZE = 16;

bool solution(MatrixOfDoubles &in, MatrixOfDoubles &out) {
  int size = in.size();
#ifdef SOLUTION
  for (int r = 0; r < size; r += TILE_SIZE) {
    for (int c = 0; c < size; c += TILE_SIZE) {
      for (int i = r; i < std::min(r + TILE_SIZE, size); i++) {
        for (int j = c; j < std::min(c + TILE_SIZE, size); j++) {
          out[i][j] = in[j][i];
        }
      }
    }
  }
#else
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      out[i][j] = in[j][i];
    }
  }
#endif
  return out[0][size - 1];
}
