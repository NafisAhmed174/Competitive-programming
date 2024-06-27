const int N = 2e5 + 10;

ll seg[4*N];
ll lazy[4*N];

ll merge(ll x,ll y){
    return x+y;
}

void build(vector<ll>& arr, ll indx, ll lo, ll hi){

    if (lo == hi) {
        seg[indx] = arr[lo];
        lazy[indx] = 0;
        return;
    }

    ll mid = lo + (hi - lo) / 2;
    build(arr, 2 * indx + 1, lo, mid);
    build(arr, 2 * indx + 2, mid + 1, hi);

    seg[indx] = merge(seg[2 * indx + 1], seg[2 * indx + 2]);
}

void update(ll indx, ll lo, ll hi, ll i, ll j, ll val){
    if (lazy[indx] != 0) {
        seg[indx] += (hi - lo + 1) * lazy[indx];
        if (lo != hi) {
            lazy[2 * indx + 1] += lazy[indx];
            lazy[2 * indx + 2] += lazy[indx];
        }
        lazy[indx] = 0;
    }
    if (lo > hi || lo > j || hi < i) return;

    if (i <= lo && hi <= j) {
        seg[indx] += (hi - lo + 1) * val;
        if (lo != hi) {
            lazy[2 * indx + 1] += val;
            lazy[2 * indx + 2] += val;
        }
        return;
    }

    ll mid = lo + (hi - lo) / 2;

    update(2 * indx + 1, lo, mid, i, j, val);
    update(2 * indx + 2, mid + 1, hi, i, j, val);

    seg[indx] = merge(seg[2 * indx + 1] , seg[2 * indx + 2]);
}

ll query(ll indx, ll lo, ll hi, ll i, ll j){
    if (lo > j || hi < i) return 0;

    if (lazy[indx] != 0) { 
        seg[indx] += (hi - lo + 1) * lazy[indx];
        if (lo != hi) {
            lazy[2 * indx + 1] += lazy[indx];
            lazy[2 * indx + 2] += lazy[indx];
        }
        lazy[indx] = 0;
    }

    if (i <= lo && j >= hi) return seg[indx];

    ll mid = lo + (hi - lo) / 2;       

    if (i > mid)
        return query(2 * indx + 2, mid + 1, hi, i, j);
    else if (j <= mid)
        return query(2 * indx + 1, lo, mid, i, j);

    ll L = query(2 * indx + 1, lo, mid, i, mid);
    ll R = query(2 * indx + 2, mid + 1, hi, mid + 1, j);

    return merge(L , R);
}