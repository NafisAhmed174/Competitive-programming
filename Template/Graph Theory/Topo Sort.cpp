vector<ll> topoSort(ll n){
    queue<ll> q;
    vector<ll> indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto &it:g[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<n;i++){
        if(!indegree[i]) q.push(i);
    }
    vector<ll> topo;
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        topo.pb(node);
        for(auto &it:g[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
}