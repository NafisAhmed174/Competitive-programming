// Returns inversion count in arr[0..n-1]
ll getInvCount(vl &v,ll n){
    ordered_set<pll> st;
    ll invcount = 0;
    for(ll i = 0; i < n; i++) {
        ll temp=st.order_of_key({v[i], -1});
        temp=(ll)st.size()-temp;
        invcount+=temp;
        st.insert({v[i], i});
    }
    return invcount;
}