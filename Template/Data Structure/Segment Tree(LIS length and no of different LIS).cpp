struct node{
    ll mx=0,cnt=0;
};


node tre[4*N];

node merge(node x,node y){

    if(x.mx>y.mx) return x;
    if(y.mx>x.mx) return y;

    node now;
    if(x.mx==y.mx){
        now.cnt= (x.cnt+y.cnt)%M;
    }
    now.mx=x.mx;
    return now;
}


// call this method as buildSegTree(arr, 0, 0, n-1);
// Here arr[] is input array and n is its size.

node querySegTree(ll treeIndex, ll lo, ll hi, ll i, ll j){
    // query for arr[i..j]

    if (lo > j || hi < i)               // segment completely outside range
        return {0,0};                       // represents a null node

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

void updateValSegTree(ll treeIndex, ll lo, ll hi, ll arrIndex, node val)
{
    if (lo == hi) {                 // leaf node. update element.
        tre[treeIndex]= val;
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


node LIS(vl &v){
    ll n,i,j;
    n=SZ(v);
    set<ll> m;
    map<ll,ll>compress;

    for(i=1;i<=n;i++){
        cin>>v[i];
        m.insert(v[i]);
    }

    ll now=0;

    for(auto &it:m){
        compress[it]=++now;
    }
    ll mx=now;
    fo(i,n) v[i+1]=compress[v[i+1]];


    for(i=1;i<=n;i++){
        
        node q=querySegTree(0,0,mx,1,v[i]-1);
        if(q.mx==0){
            q.cnt++;
        }
        node now;
        now.mx=q.mx+1;
        now.cnt=q.cnt;
        updateValSegTree(0,0,mx,v[i],now);
    }
    return querySegTree(0,0,mx,1,mx);
}