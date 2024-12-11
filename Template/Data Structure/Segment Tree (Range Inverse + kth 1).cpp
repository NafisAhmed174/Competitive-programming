ll tre[4*N];
ll lazy[4*N];

ll merge(ll x,ll y){
    return x+y;
}

void updateLazySegTree(ll treeIndex, ll lo, ll hi, ll i, ll j){
    if (lazy[treeIndex]%2 != 0) {                             // this node is lazy
        tre[treeIndex] = (hi - lo + 1) - tre[treeIndex]; // normalize current node by removing laziness

        if (lo != hi) {                                     // update lazy[] for children nodes
            lazy[2 * treeIndex + 1] += 1;
            lazy[2 * treeIndex + 2] += 1;
        }

        lazy[treeIndex] = 0;                                // current node processed. No longer lazy
    }

    if (lo > hi || lo > j || hi < i)
        return;                                             // out of range. escape.

    if (i <= lo && hi <= j) {                               // segment is fully within update range
        tre[treeIndex] = (hi - lo + 1)-tre[treeIndex];             // update segment

        if (lo != hi) {                                     // update lazy[] for children
            lazy[2 * treeIndex + 1] += 1;
            lazy[2 * treeIndex + 2] += 1;
        }

        return;
    }

    ll mid = lo + (hi - lo) / 2;                             // recurse deeper for appropriate child

    updateLazySegTree(2 * treeIndex + 1, lo, mid, i, j);
    updateLazySegTree(2 * treeIndex + 2, mid + 1, hi, i, j);

    // merge updates
    tre[treeIndex] = merge(tre[2 * treeIndex + 1] , tre[2 * treeIndex + 2]);
}
// call this method as updateLazySegTree(0, 0, n-1, i, j, val);
// Here you want to update the range [i, j] with value val.

ll find(ll treeIndex, ll lo, ll hi, ll k){

    if (lazy[treeIndex]%2 != 0) {                             // this node is lazy
        tre[treeIndex] = (hi - lo + 1) - tre[treeIndex]; // normalize current node by removing laziness

        if (lo != hi) {                                     // update lazy[] for children nodes
            lazy[2 * treeIndex + 1] += 1;
            lazy[2 * treeIndex + 2] += 1;
        }

        lazy[treeIndex] = 0;                                // current node processed. No longer lazy
    }
    if(tre[treeIndex]<=k) return -1;
    if(lo==hi) return lo;



    ll mid = lo + (hi - lo) / 2;                           // partial overlap of current segment and queried range. Recurse deeper.

    ll leftQuery = find(2 * treeIndex + 1, lo, mid, k);

    if(leftQuery!=-1) return leftQuery;
    return find(2 * treeIndex + 2, mid + 1, hi, k - tre[2*treeIndex+1]);
}