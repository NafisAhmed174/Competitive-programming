struct dsu {
    vector<ll> par, rnk, size; 
    ll c;
    dsu(ll n) : par(n+1), rnk(n+1,0), size(n+1,1), c(n) {
        for (ll i = 1; i <= n; ++i) par[i] = i;
    }
    ll find(ll i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
    bool same(ll i, ll j) { return find(i) == find(j); }
    ll get_size(ll i) { return size[find(i)]; }
    ll count() { return c; } //connected components
    ll merge(ll i, ll j) {
        if ((i = find(i)) == (j = find(j))) return -1; else --c;
        if (rnk[i] > rnk[j]) swap(i, j);
        par[i] = j; size[j] += size[i];
        if (rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
};

ll MST(vector<array<ll,3>> ed){// ***  ed = {w,u,v}  ***
    sort(ed.begin(), ed.end());
    ll ans = 0;
    dsu d(n);
    for (auto e: ed){
        int u = e[1], v = e[2], w = e[0];
        if (d.same(u, v)) continue;
        ans += w;
        d.merge(u, v);
    }
    return ans;
}