const int N = 2e5 + 10;
vector<int> g[N];

void dfs(int vertex,int par=-1){
    /*
    take action on vertex after entering the vertex
    */
    for(int child: g[vertex]){
        /*
        take action on child before entering the child node
        */
        if(child==par) continue;
        dfs(child,vertex);
        /*
        take action on child after entering the child node
        */
    }
    /*
    take action on vertex before exiting the vertex
    */
}