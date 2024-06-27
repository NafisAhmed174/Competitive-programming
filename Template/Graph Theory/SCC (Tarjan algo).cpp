struct SCC {
    int V;
    vector<vector<int>> adj;
    vector<int> discovery, low_link;
    int index;
 
    int S;
    vector<int> stack;
    vector<bool> on_stack;
 
    vector<vector<int>> components;
    vector<int> which_component;
 
    SCC(int v = 0) {
        if (v > 0)
            init(v);
    }
 
    void init(int v) {
        V = v;
        adj.assign(V, vector<int>());
    }
 
    void add_edge(int a, int b) {
        adj[a].push_back(b);
    }
 
    void dfs(int node) {
        discovery[node] = low_link[node] = index++;
        stack[S++] = node;
        on_stack[node] = true;
 
        for (int neighbor : adj[node])
            if (discovery[neighbor] == -1) {
                dfs(neighbor);
                low_link[node] = min(low_link[node], low_link[neighbor]);
            } else if (on_stack[neighbor]) {
                low_link[node] = min(low_link[node], discovery[neighbor]);
            }
 
        if (low_link[node] == discovery[node]) {
            components.push_back({});
            vector<int> &component = components.back();
            int x;
 
            do {
                x = stack[--S];
                on_stack[x] = false;
                component.push_back(x);
                which_component[x] = components.size() - 1;
            } while (x != node);
        }
    }
 
    void build() {
        discovery.assign(V, -1);
        low_link.assign(V, -1);
        which_component.assign(V, -1);
 
        S = 0;
        stack.resize(V);
        on_stack.assign(V, false);
        index = 0;
 
        components.clear();
 
        for (int i = 0; i < V; i++)
            if (discovery[i] == -1)
                dfs(i);
    }
};