const int N = 2e5 + 10;
vector<int> g[N];
bool vis[N];

void dfs(ll v){
    /*
    take action on vertex after entering the vertex
    */
    vis[v]=true;
    for(ll c: g[v]){
        /*
        take action on child before entering the child node
        */
        if(vis[c]) continue;
        dfs(c);
        /*
        take action on child after entering the child node
        */
    }
    /*
    take action on vertex before exiting the vertex
    */
}