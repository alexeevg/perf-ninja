#include "solution.hpp"
#include <algorithm>

#ifdef CACHE_OBLIVIOUS
const int TILE_SIZE = 4;
void recurse(MatrixOfDoubles &in, MatrixOfDoubles &out, int r, int c, int size) {
  if (size <= TILE_SIZE) {
    for (int i = r; i < r + size; i++) {
      for (int j = c; j < c + size; j++) {
        out[i][j] = in[j][i];
      }
    }
  } else {
    int newSize = size / 2;
    recurse(in, out, r, c, newSize);
    recurse(in, out, r, c + newSize, size - newSize);
    recurse(in, out, r + newSize, c, size - newSize);
    recurse(in, out, r + newSize, c + newSize, size - newSize);
  }
}
#endif

bool solution(MatrixOfDoubles &in, MatrixOfDoubles &out) {
  int size = in.size();
#ifdef SOLUTION
  const int TILE_SIZE = 16;
  for (int r = 0; r < size; r += TILE_SIZE) {
    for (int c = 0; c < size; c += TILE_SIZE) {
      for (int i = r; i < std::min(r + TILE_SIZE, size); i++) {
        for (int j = c; j < std::min(c + TILE_SIZE, size); j++) {
          out[i][j] = in[j][i];
        }
      }
    }
  }
#elif defined(CACHE_OBLIVIOUS)
  recurse(in, out, 0, 0, size);
#else
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      out[i][j] = in[j][i];
    }
  }
#endif
  return out[0][size - 1];
}
