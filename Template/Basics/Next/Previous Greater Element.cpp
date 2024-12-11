pair<vl,vl> GreaterElements(vl &v,ll n){
    stack<ll> st;
    vl prv(n+2,0),nxt(n+2,0);
    st.push(0);
    for(int i = 1; i <= n; i++){
        while(SZ(st) && v[st.top()]<=v[i]) st.pop();
        if(st.empty()){}
        else prv[i] = st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop();

    st.push(n+1);
    for(int i = n; i >= 1; i--){
        while(SZ(st) && v[st.top()]<=v[i]) st.pop();
        if(st.empty()) nxt[i]=n+1;
        else nxt[i] = st.top();
        st.push(i);
    }
    // print(nxt);
    // print(prv);
    return {prv,nxt};
}