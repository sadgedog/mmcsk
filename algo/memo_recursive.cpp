#include <bits/stdc++.h>
using namespace std;

map<long long, long long> memo;
// vector<long long> memo(1000);

long long fibonacci(long long n) {
  cout << n << endl;
  if (n <= 1) {
    return n;
  }

  if (memo[n] != 0) {
    return memo[n];
  }

  return memo[n] = fibonacci(n-1) + fibonacci(n-2);
}

// f(x) = 1 (x == 0)
// f(x) = f(n/2) + f(n/3)
long long fn(long long n) {
  cout << n << endl;
  if (n == 0) {
    return 1;
  }
  if (memo[n] != 0) {
    return memo[n];
  }
  return memo[n] = fn(n/2) + fn(n/3);
}

int main() {
  long long n = 100;
  // cout << fibonacci(n) << endl;
  cout << "------" << endl;
  memo.clear();
  long long m = 100;
  cout << fn(m) << endl;
  
  return 0;
}
