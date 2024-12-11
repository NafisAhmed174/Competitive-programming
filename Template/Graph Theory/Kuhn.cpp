mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct Kuhn {
  int n;
  vector<vector<int>> g;
  vector<int> l, r;
  vector<bool> vis;
  Kuhn(int _n, int _m) {
    n = _n;
    g.resize(n + 1);
    vis.resize(n + 1, false);
    l.resize(n + 1, -1);
    r.resize(_m + 1, -1);
  }
  void add_edge(int a, int b) {
    g[a].push_back(b);
  }
  bool yo(int u) {
    if (vis[u])  return false;
    vis[u] = true;
    for (auto v : g[u]) {
      if (r[v] == -1 || yo(r[v])) {
        l[u] = v;
        r[v] = u;
        return true;
      }
    }
    return false;
  }
  int maximum_matching() {
    for (int i = 1; i <= n; i++) shuffle(g[i].begin(), g[i].end(), rnd);
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end(), rnd);
    bool ok = true;
    while (ok) {
      ok = false;
      vis.assign(n + 1, false);
      for (auto &i : p) if(l[i] == -1) ok |= yo(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += l[i] != -1;
    return ans;
  }
};