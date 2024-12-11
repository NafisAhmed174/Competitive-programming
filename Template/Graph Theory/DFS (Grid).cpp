ll n,m,t=0;
vector<string> g;
vpll Move={ {1,0},{-1,0},{0,1},{0,-1} };

bool vis[N][N];

bool isValid(ll x,ll y){
    return (x>=0&&y>=0&&x<n&&y<m&&vis[x][y]==0&&g[x][y]=='.');
}

void dfs(pll vertex){
    /*
    take action on vertex after entering the vertex
    */
    vis[vertex.first][vertex.second]=true;
    for(pll &child: Move){
        /*
        take action on child before entering the child node
        */
        ll x=child.first+vertex.first;
        ll y=child.second+vertex.second;
        if(!isValid(x,y)) continue;
        dfs({x,y});
        /*
        take action on child after entering the child node
        */
    }
    /*
    take action on vertex before exiting the vertex
    */
}