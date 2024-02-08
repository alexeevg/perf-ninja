#include "solution.hpp"

static int getSumOfDigits(int n) {
  int sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}

int solution(const hash_map_t *hash_map, const std::vector<int> &lookups) {
  int result = 0;

#ifdef SOLUTION
  for (int val : lookups) {
    hash_map->prefetch(val);
    int sum = getSumOfDigits(val);
    if (hash_map->find(val))
      result += sum;
  }
#elif defined(REFERENCE_SOLUTION)
  constexpr int PREFETCH_DISTANCE = 32;
  for (size_t i = 0; i < lookups.size(); i++) {
    int val = lookups[i];
    hash_map->prefetch(lookups[ std::min(i + PREFETCH_DISTANCE, lookups.size() - 1)]);
    if (hash_map->find(val))
      result += getSumOfDigits(val);
  }
#else
  for (int val : lookups) {
    if (hash_map->find(val))
      result += getSumOfDigits(val);
  }
#endif

  return result;
}
