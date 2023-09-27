#include <bits/stdc++.h>
using namespace std;

// DFS : グラフの全探索、循環検出
int main() {
  int n, m;
  cin >> n >> m;
  // aとbが連結
  vector<int> a(m), b(m);
  vector<vector<int>> Graph(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  // a->bの有向グラフなら二行目はいらない
  for (int i = 0; i < m; i++) {
    Graph[a[i]-1].push_back(b[i]-1);
    Graph[b[i]-1].push_back(a[i]-1);
  }
  
  // DFS(再帰)
  vector<bool> visited(n, false);
  vector<int> path;
  auto dfs = [&] (auto self, int pos) -> void {
    visited[pos] = true;
    for (int i = 0; i < Graph[pos].size(); i++) {
      int nex = Graph[pos][i];
      if (!visited[nex]) {
        self(self, nex);
      }
      // 最短経路の例(関数の最初にpos==n-1でreturnを追加)
      // if (!visited[nex]) {
      //   path.push_back(nex);
      //   self(self, nex);
      //   path.pop_back();
      // }
    }
    // 帰りがけの例
    // path.push_back(pos);
    return;
  };

  // DFS(stack)
  vector<bool> visited(n, false);
  stack<int> st;
  st.push(0);
  while (!st.empty()) {
    int pos = st.top();
    st.pop();
    // 最短経路の例
    // visited[pos] = true;
    // res.push_back(pos);
    // if (pos == n-1) {
    //   break;
    // }
    for (int i = 0; i < Graph[pos].size(); i++) {
      int to = Graph[pos][i];
      if (!visited[to]) {
        visited[to] = true;
        st.push(to);
      }
    }
  }


  
  
  return 0;
}
