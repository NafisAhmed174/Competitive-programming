const ll inf = 1e18;
const int N = 1e3 + 10;
vector<pair<ll,ll>> g[N];

ll n,m;

vector<ll> dist(N,INF);
vector<ll> par(N,-1);

void bellman_ford(){
    ll x = -1;
    dist[1] = 0;
    for(int i=2; i<=n; i++) dist[i] = inf;
    for(int i=0; i<n; i++){
        x=-1;
        for(int node=1; node <= n; node++){
            if(dist[node] == inf) continue;
            for(auto a : g[node]){
                if(dist[a.ff] > dist[node] + a.ss){
                    dist[a.ff] = dist[node] + a.ss;
                    x=a.ff;
                }
            }
        }
        // if(x==-1) break;
    }
    if(x==-1){
        cout << "NO" << "\n"; // no negative cycle
    }else{
        int y=x; //x can be on any cycle or reachable from some cycle
        for (int i=0; i<n; ++i) y = par[y];
        vector<ll> path;
        for(int cur=y; ; cur=par[cur]) {
            path.push_back (cur);
            if(cur==y && path.size() > 1) break;
        }
        reverse(path.begin(), path.end());
        cout << "YES" <<"\n";
        for(auto x: path){
            cout << x << " ";
        }
        cout << "\n";
    }
}