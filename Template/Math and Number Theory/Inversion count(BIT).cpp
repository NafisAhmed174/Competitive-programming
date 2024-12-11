ll BITree[100009];

///do this for range: getSum(r) - getSum(l - 1)
ll getSum(ll index){
    ll sum = 0; // Iniialize result
    // Traverse ancestors of BITree[index]
    while (index>0){  
        sum += BITree[index];  // Add current element of BITree to sum
        index -= index & (-index);  // Move index to parent node in getSum View
    }
    return sum;
}

void updateBIT(ll n, ll index, ll val){
    // Traverse all ancestors and add 'val'
    while (index <= n){
       // Add 'val' to current node of BI Tree
       BITree[index] += val;
       // Update index to that of parent in update View
       index += index & (-index);
    }
}

void compress(vl &v,ll n){
    ll i;
    set<pll> st;
    fo(i,n){
        st.insert({v[i],i});
    }
    i=1;
    for(auto &it:st){
        v[it.second]=i;
        i++;
    }
}

ll getInvCount(vl &v,ll n){
    ll invcount=0;
    compress(v,n);
    for(int i=1;i<=n;i++){
        BITree[i]=0;
    }
    for(int i=n-1;i>=0;i--){
        invcount+=getSum(v[i]-1);
        updateBIT(n,v[i],1);
    }
    return invcount;
}