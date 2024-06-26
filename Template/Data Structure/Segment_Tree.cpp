ll seg[4 * N];
ll Null = 0;
ll merge(ll x, ll y){
    return (x+y);
}

void build(vector<ll> &v, ll index, ll lo , ll hi){
    if(lo == hi){
        seg[index] = v[lo];
        return;
    }
    ll mid = (lo + hi) / 2;
    build(v, 2 * index + 1, lo, mid);
    build(v, 2 * index + 2, mid + 1, hi);
    seg[index] = merge(seg[2 * index + 1], seg[2 * index + 2]);
}

void update(ll index, ll lo, ll hi, ll i, ll val){
    if(i > hi || i < lo) return; // complete outside
    if(lo == hi){
        seg[index] = val;
        return;
    }
    ll mid = (lo + hi) / 2;
    update(2 * index + 1, lo , mid, i , val);
    update(2 * index + 2, mid + 1 , hi, i , val);
    seg[index] = merge(seg[2 * index + 1], seg[2 * index + 2]);
}

ll query(ll index, ll lo, ll hi, ll i, ll j){
    if(i > hi || j < lo){ // complete outside
        return Null; // null node
    }
    if(lo >= i && hi <= j){ // complete inside
        return seg[index];
    }
    ll mid = (lo + hi) / 2;
    ll L = query(2 * index + 1, lo, mid, i, j);
    ll R = query(2 * index + 2, mid + 1, hi, i, j);
    return merge(L,R);
}