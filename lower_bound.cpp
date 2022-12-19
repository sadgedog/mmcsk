#include <iostream>
#include <vector>

int lower_bound(vector<int> x, int n) {
  int l = 1;
  int r = x.size();

  while (l <= r) {
    int m = (l + r) / 2;
    if (n < x.at(m))
      r = m - 1;
    if (n > x.at(m))
      l = m + 1;
    if (n == x.at(m))
      return m + 1;
    if (r - l == 1)
      return r + 1;
  }
  return -1;
}
