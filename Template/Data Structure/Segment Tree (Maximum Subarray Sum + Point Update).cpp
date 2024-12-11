struct node{
    ll mxsum=0,mxpre=0,mxsuff=0,sum=0;
};
 
node tre[4*N];
 
node merge(node x,node y){
    node now;
    now.mxsum=max({0LL,x.mxsum,y.mxsum,x.mxsuff+y.mxpre});
    now.sum=x.sum+y.sum;
    now.mxpre=max({0LL,now.sum,x.sum+y.mxpre,x.mxpre});
    now.mxsuff=max({0LL,now.sum,y.sum+x.mxsuff,y.mxsuff});
    return now;
}
 
void buildSegTree(vector<ll>& arr, ll treeIndex, ll lo, ll hi){
 
    if (lo == hi) {                 // leaf node. store value in node.
        tre[treeIndex].sum = arr[lo];
        tre[treeIndex].mxsum = tre[treeIndex].mxpre = tre[treeIndex].mxsuff = max(0LL,arr[lo]);
        return;
    }
 
    ll mid = lo + (hi - lo) / 2;   // recurse deeper for children.
    buildSegTree(arr, 2 * treeIndex + 1, lo, mid);
    buildSegTree(arr, 2 * treeIndex + 2, mid + 1, hi);
 
    // merge build results
    tre[treeIndex] = merge(tre[2 * treeIndex + 1], tre[2 * treeIndex + 2]);
}
 
// call this method as buildSegTree(arr, 0, 0, n-1);
// Here arr[] is input array and n is its size.
 
node querySegTree(ll treeIndex, ll lo, ll hi, ll i, ll j){
    // query for arr[i..j]
 
    if (lo > j || hi < i){               // segment completely outside range
        node now;
        now.sum=now.mxsum=now.mxpre=now.mxsuff=0;                       // represents a null node
        return now;
    }
    if (i <= lo && j >= hi)             // segment completely inside range
        return tre[treeIndex];
 
    ll mid = lo + (hi - lo) / 2;       // partial overlap of current segment and queried range. Recurse deeper.
 
    if (i > mid)
        return querySegTree(2 * treeIndex + 2, mid + 1, hi, i, j);
    else if (j <= mid)
        return querySegTree(2 * treeIndex + 1, lo, mid, i, j);
 
    node leftQuery = querySegTree(2 * treeIndex + 1, lo, mid, i, mid);
    node rightQuery = querySegTree(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);
 
    // merge query results
    return merge(leftQuery, rightQuery);
}
 
// call this method as querySegTree(0, 0, n-1, i, j);
// Here [i,j] is the range/interval you are querying.
// This method relies on "null" nodes being equivalent to storing zero.
 
void updateValSegTree(ll treeIndex, ll lo, ll hi, ll arrIndex, ll val)
{
    if (lo == hi) {                 // leaf node. update element.
        tre[treeIndex].sum = val;
        tre[treeIndex].mxsum = tre[treeIndex].mxpre = tre[treeIndex].mxsuff = max(0LL,val);
        return;
    }
 
    ll mid = lo + (hi - lo) / 2;   // recurse deeper for appropriate child
 
    if (arrIndex > mid)
        updateValSegTree(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
    else if (arrIndex <= mid)
        updateValSegTree(2 * treeIndex + 1, lo, mid, arrIndex, val);
 
    // merge updates
    tre[treeIndex] = merge(tre[2 * treeIndex + 1], tre[2 * treeIndex + 2]);
}
 
// call this method as updateValSegTree(0, 0, n-1, i, val);
// Here you want to update the value at index i with value val.