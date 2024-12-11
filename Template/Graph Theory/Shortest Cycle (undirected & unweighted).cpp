ll bfs(ll source,ll n){
    ll ret=INT_MAX;
    vl par(n+1,-1);
    vl dist(n+1,INT_MAX);
    queue<ll> q;
    q.push(source);
    dist[source]=0;
    
    while(!q.empty()){
        ll cur_v=q.front();
        q.pop();
        for(ll child:g[cur_v]){
            if(dist[child]==INT_MAX){
                q.push(child);
                par[child]=cur_v;
                dist[child]=1+dist[cur_v];
            }else{
                if(par[cur_v]==child) continue;
                ret=min(ret,dist[child]+dist[cur_v]+1);
            }
        }
    }
    return ret;
}

ll shortest_cycle(ll n){
    ll ans=INT_MAX,i;
    fo(i,n) ans=min(ans,bfs(i,n));
    fo(i,n+1) g[i].clear();
    if(ans==INT_MAX) return -1;
    return ans;
}