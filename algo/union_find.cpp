#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent;
  UnionFind(int n) : parent(n) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  // 要素xを含む根を探す
  int get_root(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = get_root(parent[x]);
    }
  }

  // 要素xを含む木と要素yを含む木を統合する
  void unite(int x, int y) {
    int root_x = get_root(x);
    int root_y = get_root(y);
    if (root_x == root_y) {
      return;
    } else {
      parent[root_x] = root_y;
    }
  }

  bool is_same(int x, int y) {
    return get_root(x) == get_root(y);
  }
};

// input
// 8 9
// 0 1 2
// 0 3 2
// 1 1 3
// 1 1 4
// 0 2 4
// 1 4 1
// 0 4 2
// 0 0 0
// 1 0 0

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> p(q, 0), a(q, 0), b(q, 0);

  UnionFind tree(n);

  for (int i = 0; i < q; i++) {
    cin >> p[i] >> a[i] >> b[i];
  }

  for (int i = 0; i < q; i++) {
    if (p[i] == 0) {
      tree.unite(a[i], b[i]);
    } else {
      bool res = tree.is_same(a[i], b[i]);
      cout << (res ? "Yes" : "No") << endl;
    }
  }

  return 0;
}
