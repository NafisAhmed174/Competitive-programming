const int LOG = 19;

ll merge(ll x, ll y){
    return __gcd(x, y);
}

ll table[N][LOG], ar[N];//note: ar is 1 based
void build(ll n) {
    for(ll i = 1; i <= n; ++i) table[i][0] = ar[i];
    for(ll k = 1; k < LOG; ++k) {
        for(ll i = 1; i + (1 << k) - 1 <= n; ++i) {
            table[i][k] = merge(table[i][k - 1], table[i + (1 << (k - 1))][k - 1]);
        }
    }
}
 
ll query(ll l, ll r) {
    ll k = 31 - __builtin_clz(r - l + 1);
    return merge(table[l][k], table[r - (1 << k) + 1][k]);
}