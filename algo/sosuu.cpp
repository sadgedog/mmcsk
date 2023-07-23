#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 素数判定
// O(sqrt(n))
bool is_prime(long long n) {
  if (n == 1) {
    return false;
  } else {
    for (int i = 0; i*i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
  }
  return true;
}

// 約数列挙
// O(sqrt(n))
vector<long long> enum_div(long long n) {
  vector<long long> res;
  for (long long i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i) {
        res.push_back(n/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}

// 素因数分解 : 試し割り法
// O(sqrt(n))
vector<pair<long long, long long>> trial_div(long long n) {
  vector<pair<long long, long long>> res;
  for (long long i = 2; i*i <= n; i++) {
    // 割り切れないならば次の候補
    if (n % i != 0) {
      continue;
    } else {
      // 割り切れる場合
      long long ex = 0;
      while (n % i == 0) {
        ex++;
        n /= i;
      }
      res.push_back({i, ex});
    }
  }
  
  if (n != 1) {
    res.push_back({n, 1});
  }

  return res;
}

// エラトステネスの篩
// O(n*log(n))
vector<bool> eratosthenes(long long n) {
  vector<bool> res(n+1, true);
  res[0] = false;
  res[1] = false;
  for (int i = 2; i <= n; i++) {
    if (res[i] == false) {
      continue;
    } else {
      for (int j = i*2; j <= n; j += i) {
        res[j] = false;
      }
    }
  }
  return res;
}

int main() {
  // 2023 = 17^2 * 7
  // long long a = 2023;
  
  // 1059872604593911 = 104149^2 * 97711
  long long a = 1059872604593911;
  vector<pair<long long, long long>> res = trial_div(a);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].first << "^" << res[i].second << endl;
  }

  vector<bool> e = eratosthenes(50);
  for (int i = 0; i < e.size(); i++) {
    // cout << (e[i] ? i : 0) << endl;
    if (e[i]) {
      cout << i << ", ";
    }
  } cout << endl;
  
  return 0;
}
