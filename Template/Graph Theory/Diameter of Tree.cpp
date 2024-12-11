void dfs(int vertex,int par=-1){
    /*
    take action on vertex after entering the vertex
    */
    for(int child: g[vertex]){
        /*
        take action on child before entering the child node
        */
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        /*
        take action on child after entering the child node
        */
    }
    /*
    take action on vertex before exiting the vertex
    */
}

int diameter(int n){
    int i;
    dfs(1);
    int max_depth=-1;
    int max_d_node;
    Fo(i,1,n+1){
        if(max_depth<depth[i]){
            max_depth=depth[i];
            max_d_node=i;
        }
        depth[i]=0;;
    }
    dfs(max_d_node);
    Fo(i,1,n+1){
        if(max_depth<depth[i]){
            max_depth=depth[i];
        }
    }
    return max_depth;
}