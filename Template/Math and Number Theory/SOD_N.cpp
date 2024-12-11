namespace modop {
    ll madd(ll a, ll b) {
        return (a + b) % M;
    }
    ll msub(ll a, ll b) {
        return (((a - b) % M) + M) % M;
    }
    ll mmul(ll a, ll b) {
        return ((a % M) * (b % M)) % M;
    }
    ll mpow(ll base, ll exp) {
        ll res = 1;
        while (exp) {
            if (exp % 2 == 1){
                res = (res * base) % M;
            }
            exp >>= 1;
            base = (base * base) % M;
        }
        return res;
    }
    ll minv(ll base) {
        return mpow(base, M - 2);
    }
    ll mdiv(ll a, ll b) {
        return mmul(a, minv(b));
    }

    const ll FACTORIAL_SIZE = 1.1e6;
    ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
    bool __factorials_generated__ = 0;
    void gen_factorial(ll n) {
        __factorials_generated__ = 1;
        fact[0] = fact[1] = ifact[0] = ifact[1] = 1;

        for (ll i = 2; i <= n; i++) {
            fact[i] = (i * fact[i - 1]) % M;
        }
        ifact[n] = minv(fact[n]);
        for (ll i = n - 1; i >= 2; i--) {
            ifact[i] = ((i + 1) * ifact[i + 1]) % M;
        }
    }
    ll nck(ll n, ll k) {
        if (!__factorials_generated__) {
            cerr << "Call gen_factorial you dope" << endl;
            exit(1);
        }
        if (k < 0 || n < k) return 0;
        ll den = (ifact[k] * ifact[n - k]) % M;
        return (den * fact[n]) % M;
    }

}
using namespace modop;

ll SODuptoN(ll n){
    ll res=0;
    ll now=1;
    ll pre=0,last=0,q=0;
    ll inv2=ModInv<ll>(2,M);
    while(now<=n){
        q=n/now;
        last=n/q;
        res=madd(res,mmul(mmul(mmul(q,last) , last+1) , inv2));
        res=msub(res,mmul(q,mmul(mmul(now,now-1),inv2)));
        now=last+1;
    }
    return res;
}