struct node{
    ll mxsum=0,mxpre=0,mxsuff=0,sum=0;
};

node tre[4*N];
ll lazy[4*N];

node merge(node x,node y){
    node now;
    now.sum=x.sum+y.sum;
    now.mxsum=max({x.mxsum,y.mxsum,x.mxsuff+y.mxpre});
    now.mxpre=max({x.mxpre,x.sum,x.sum+y.mxpre,now.sum});
    now.mxsuff=max({y.mxsuff,y.sum,y.sum+x.mxsuff,now.sum});
    return now;
}

void updateLazySegTree(ll treeIndex, ll lo, ll hi, ll i, ll j, ll val){
    if (lazy[treeIndex] != inf) {                             // this node is lazy

        tre[treeIndex].sum= (hi - lo + 1) * lazy[treeIndex];
        if(lazy[treeIndex]>=0){
            tre[treeIndex].mxsum=tre[treeIndex].mxpre=tre[treeIndex].mxsuff=tre[treeIndex].sum;
        }else{
            tre[treeIndex].mxsum=tre[treeIndex].mxpre=tre[treeIndex].mxpre=tre[treeIndex].mxsuff=0;
        }


        if (lo != hi) {                                     // update lazy[] for children nodes
            lazy[2 * treeIndex + 1] = lazy[treeIndex];
            lazy[2 * treeIndex + 2] = lazy[treeIndex];
        }

        lazy[treeIndex] = inf;                                // current node processed. No longer lazy
    }

    if (lo > hi || lo > j || hi < i)
        return;                                             // out of range. escape.

    if (i <= lo && hi <= j) {                               // segment is fully within update range
        tre[treeIndex].sum = (hi - lo + 1) * val;             // update segment
        if(val>=0){
            tre[treeIndex].mxsum=tre[treeIndex].mxpre=tre[treeIndex].mxsuff=tre[treeIndex].sum;
        }else{
            tre[treeIndex].mxsum=tre[treeIndex].mxpre=tre[treeIndex].mxpre=tre[treeIndex].mxsuff=0;
        }

        if (lo != hi) {                                     // update lazy[] for children
            lazy[2 * treeIndex + 1] = val;
            lazy[2 * treeIndex + 2] = val;
        }

        return;
    }

    ll mid = lo + (hi - lo) / 2;                             // recurse deeper for appropriate child

    updateLazySegTree(2 * treeIndex + 1, lo, mid, i, j, val);
    updateLazySegTree(2 * treeIndex + 2, mid + 1, hi, i, j, val);

    // merge updates
    tre[treeIndex] = merge(tre[2 * treeIndex + 1] , tre[2 * treeIndex + 2]);
}
// call this method as updateLazySegTree(0, 0, n-1, i, j, val);
// Here you want to update the range [i, j] with value val.

node queryLazySegTree(ll treeIndex, ll lo, ll hi, ll i, ll j){
    // query for arr[i..j]

    if (lo > j || hi < i)                                   // segment completely outside range
        return {0,0,0,0};                                           // represents a null node

    if (lazy[treeIndex] != inf) {                             // this node is lazy
        tre[treeIndex].sum= (hi - lo + 1) * lazy[treeIndex];
        if(lazy[treeIndex]>=0){
            tre[treeIndex].mxsum=tre[treeIndex].mxpre=tre[treeIndex].mxsuff=tre[treeIndex].sum;
        }else{
            tre[treeIndex].mxsum=tre[treeIndex].mxpre=tre[treeIndex].mxpre=tre[treeIndex].mxsuff=0;
        }


        if (lo != hi) {                                     // update lazy[] for children nodes
            lazy[2 * treeIndex + 1] = lazy[treeIndex];
            lazy[2 * treeIndex + 2] = lazy[treeIndex];
        }

        lazy[treeIndex] = inf;                                 // current node processed. No longer lazy
    }

    if (i <= lo && j >= hi)                                 // segment completely inside range
        return tre[treeIndex];

    ll mid = lo + (hi - lo) / 2;                           // partial overlap of current segment and queried range. Recurse deeper.

    if (i > mid)
        return queryLazySegTree(2 * treeIndex + 2, mid + 1, hi, i, j);
    else if (j <= mid)
        return queryLazySegTree(2 * treeIndex + 1, lo, mid, i, j);

    node leftQuery = queryLazySegTree(2 * treeIndex + 1, lo, mid, i, mid);
    node rightQuery = queryLazySegTree(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);

    // merge query results
    return merge(leftQuery , rightQuery);
}
// call this method as queryLazySegTree(0, 0, n-1, i, j);
// Here [i,j] is the range/interval you are querying.
// This method relies on "null" nodes being equivalent to storing zero.
