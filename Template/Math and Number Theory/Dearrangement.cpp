const int N = 1e6 + 9, mod = 1e9 + 7;

int d[N];

void compute(){
    d[0] = 1; d[1] = 0;
    for (int i = 1; i < N; i++) {
        d[i] = 1LL * (i - 1) * (d[i - 1] + d[i - 2]) % mod;
    }
}