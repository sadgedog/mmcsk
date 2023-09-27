#include <bits/stdc++.h>
using namespace std;

// BFS: 最短経路
int main() {
  int n, m;
  cin >> n >> m;
  // aとbが連結
  vector<int> a(m), b(m);
  vector<vector<int>> Graph(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  
  for (int i = 0; i < m; i++) {
    Graph[a[i]-1].push_back(b[i]-1);
    Graph[b[i]-1].push_back(a[i]-1);
  }
  
  queue<int> Q;
  vector<int> dist(n, -1);
  Q.push(0);
  dist[0] = 0;
  while (!Q.empty()) {
    int pos = Q.front();
    Q.pop();
    for (int i = 0; i < Graph[pos].size(); i++) {
      int to = Graph[pos][i];
      if (dist[to] == -1) {
        dist[to] = dist[pos] + 1;
        Q.push(to);
      }
    }
  }
  
  return 0;
}
