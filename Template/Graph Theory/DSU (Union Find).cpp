//Union-Find
struct unionfind{
    vector<int> par, siz;
 
    //initialization
    unionfind(int n) : par(n, -1), siz(n, 1) {}
 
    // find the root
    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
 
    //whether the roots (groups) of x and y match
    bool issame(int x, int y){
        return root(x) == root(y);
    }
 
    // merge groups of x and y
    bool unite(int x, int y){
        x = root(x); y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x,y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    //size of group containing x
    int size(int x){
        return siz[root(x)];
    }
};
 