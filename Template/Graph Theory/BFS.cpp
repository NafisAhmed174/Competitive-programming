const int N = 2e5 + 10;
vector<int> g[N];
bool vis[N];
ll level[N];

void bfs(ll src){
    queue<ll> q;
    q.push(src);
    vis[src]=1;
    level[src]=0;
    while(!q.empty()){
        ll v=q.front();
        q.pop();
        for(ll c:g[v]){
            if(!vis[c]){
                q.push(c);
                vis[c]=1;
                level[c]=1+level[v];
            }
        }
    }
}