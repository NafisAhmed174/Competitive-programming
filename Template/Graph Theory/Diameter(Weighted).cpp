ll t=0;
vpll g[N];
ll depth[N];
void dfs(ll vertex,ll par=-1){
    for(auto child: g[vertex]){
        if(child.first==par) continue;
        depth[child.first]=depth[vertex]+child.second;
        dfs(child.first,vertex);
    }
}

ll diameter(ll n){
    ll i;
    dfs(0);
    ll max_depth=-1;
    ll max_d_node;
    fo(i,n){
        if(max_depth<depth[i]){
            max_depth=depth[i];
            max_d_node=i;
        }
        depth[i]=0;
    }
    dfs(max_d_node);
    fo(i,n){
        if(max_depth<depth[i]){
            max_depth=depth[i];
        }
    }
    return max_depth;
}