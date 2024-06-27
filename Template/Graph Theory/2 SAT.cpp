const int MaxN = 2e5 + 10;
 
struct TwoSat {
    int st[MaxN], top, col, co[MaxN], num, dfn[MaxN], low[MaxN];
    vector<int> G1[MaxN];
    int N;
    void clear(int n) {
        col = top = num = 0;
        for (int i = 0; i <= 2 * n; i++) {
            st[i] = co[i] = dfn[i] = low[i] = 0;
            G1[i].clear();
        }
    }
    void init(int n) {
        clear(n);
        N = n;
    }
 
    inline void tarjan(int x) {
        dfn[x] = low[x] = ++num;
        st[++top] = x;
        for (auto y : G1[x]) {
            if (!dfn[y]) {
                tarjan(y);
                low[x] = min(low[x], low[y]);
            }
            else if (!co[y]) {
                low[x] = min(low[x], dfn[y]);
            }
        }
        if (low[x] == dfn[x]) {
            co[x] = ++col;
            while (st[top] != x) {
                co[st[top]] = col;
                top--;
            }
            top--;
        }
    }
    int inv(int x) {
        if (x > N) return x - N;
        return x + N;
    }
    void insert(int x, int y) {
        G1[x].push_back(y);
    }
    void add1(int x, int y) {
        G1[x].push_back(y);
        G1[inv(y)].push_back(inv(x));
    }
    void equal(int x, int y) {
        add1(x, y);
        add1(inv(x), inv(y));
    }
    void unequal(int x, int y) {
        add1(x, inv(y));
        add1(inv(x), y);
    }
    void either(int x, int y) {
        G1[inv(x)].push_back(y);
        G1[inv(y)].push_back(x);
    }
    void equalTrue(int x) {
        G1[inv(x)].push_back(x);
    }
    bool run() {
        for (int i = 1; i <= 2 * N; i++) {
            if (!dfn[i]) tarjan(i);
        }
        for (int i = 1; i <= N; i++) {
            if (co[i] == co[i + N]) return 0;
        }
        return 1;
    }
} TwoSat;