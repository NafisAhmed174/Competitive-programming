void countSort(vector<ll> &v){
    ll i=0,n=v.size(), mx = -1e9, mn = 1e9;
    for(i = 0; i < n; i++){
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }
    vector<ll> cnt(mx+1 - mn,0);
    vector<ll> sorted(n);

    for(i = 0; i < n; i++) cnt[v[i] - mn]++;
    for(i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
    for(i = n - 1 ; i >= 0; i--) sorted[--cnt[v[i] - mn]] = v[i];  
    for(i = 0; i < n; i++) v[i] = sorted[i];
}