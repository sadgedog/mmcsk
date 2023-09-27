#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int> mp;
  int n = 10;
  for (int i = 0; i < n; i++) {
    mp[i] = i;
  }

  // 存在するmpのkeyの最小値, 最大値
  // mp.end()はmpの末尾の次を参照するiteratorなので(mp.end())->firstは未定義動作
  cout << (mp.begin())->first << endl;
  cout << (mp.rbegin())->first << endl;
  
  return 0;
}
