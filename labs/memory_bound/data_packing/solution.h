
#include <array>

// Assume those constants never change
constexpr int N = 10000;
constexpr int minRandom = 0;
constexpr int maxRandom = 100;

#ifdef BASELINE
struct S {
  int i;
  long long l;
  short s;
  double d;
  bool b;

  bool operator<(const S &s) const { return this->i < s.i; }
};
#else
struct S {
  float d;
  unsigned i : 8;
  unsigned b : 1;
  unsigned s : 7;
  unsigned l : 16;

  bool operator<(const S &s) const { return this->i < s.i; }
};
#endif

void init(std::array<S, N> &arr);
S create_entry(int first_value, int second_value);
void solution(std::array<S, N> &arr);
