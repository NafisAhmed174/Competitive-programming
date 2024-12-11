ll n , v[N] ;

unordered_map<ll,ll,custom_hash> m;

ll last[1000000+10] , res[200000+10];

struct query{
    ll l=0,r=0,ind=0;
};


ll tre[4*N];

ll merge(ll x,ll y){
    return x+y;
}


ll querySegTree(ll treeIndex, ll lo, ll hi, ll i, ll j){
    // query for arr[i..j]

    if (lo > j || hi < i)               // segment completely outside range
        return 0;                       // represents a null node

    if (i <= lo && j >= hi)             // segment completely inside range
        return tre[treeIndex];

    ll mid = lo + (hi - lo) / 2;       // partial overlap of current segment and queried range. Recurse deeper.

    if (i > mid)
        return querySegTree(2 * treeIndex + 2, mid + 1, hi, i, j);
    else if (j <= mid)
        return querySegTree(2 * treeIndex + 1, lo, mid, i, j);

    ll leftQuery = querySegTree(2 * treeIndex + 1, lo, mid, i, mid);
    ll rightQuery = querySegTree(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);

    // merge query results
    return merge(leftQuery, rightQuery);
}

// call this method as querySegTree(0, 0, n-1, i, j);
// Here [i,j] is the range/interval you are querying.
// This method relies on "null" nodes being equivalent to storing zero.

void updateValSegTree(ll treeIndex, ll lo, ll hi, ll arrIndex, ll val)
{
    if (lo == hi) {                 // leaf node. update element.
        tre[treeIndex] = val;
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



void solve() {
    ll a=0,b=0,i=0,j=0,k=0,l=0,r=0,ans=0,temp=0,cnt=0,sum=0;
    string s,s1,s2,s3;
    cin>>n;

    ll now=0;

    for(i=1;i<=n;i++){
        cin>>v[i];
        // if(!m.count(v[i])){
        //     m[v[i]]=now;
        //     v[i]=now;
        //     now++;
        // }else{
        //     v[i]=m[v[i]];
        // }
    }
    cin>>k;
    vector<query> q(k);

    fo(i,k){
        cin>>q[i].l>>q[i].r;
        q[i].ind=i;
    }

    auto cmp=[&](query x, query y){
        return x.r<y.r;
    };

    sort(all(q),cmp);
    mem(last,-1);

    // cerr<<"OK"<<endl;
    ll curr=1;

    fo(i,k){
        l=q[i].l;
        r=q[i].r;
        ll id=q[i].ind;

        while(curr<=r){
            if(last[v[curr]]==-1){
                updateValSegTree(0,0,n,curr,1);
                last[v[curr]]=curr;
            }else{
                updateValSegTree(0,0,n,last[v[curr]],0);
                updateValSegTree(0,0,n,curr,1);
                last[v[curr]]=curr;
            }
            curr++;
        }
        // deb2(r,curr);

        ll now=querySegTree(0,0,n,l,r);
        // deb(now);
        res[id]=now;
    }

    for(i=0;i<k;i++) cout<<res[i]<<nn;
}