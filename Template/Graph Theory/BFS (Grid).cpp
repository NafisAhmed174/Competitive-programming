vpll Move={ {1,0},{-1,0},{0,1},{0,-1} };

bool vis[N][N];
ll level[N][N];
ll n,m;

bool isValid(ll x,ll y){
    return (x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0);
}

void bfs(pll source){
    queue<pll> q;
    q.push(source);
    vis[source.first][source.second]=1;
    level[source.first][source.second]=0;
    while(!q.empty()){
        pll cur_v=q.front();
        q.pop();
        for(pll &child:Move){
            ll x=cur_v.first+child.first;
            ll y=cur_v.second+child.second;
            if(isValid(x,y)){
                q.push({x,y});
                vis[x][y]=1;
                level[x][y]=1+level[cur_v.first][cur_v.second];
            }
        }
    }
}