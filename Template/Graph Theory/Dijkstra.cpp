template <typename T> using PQ = priority_queue<T>;
template <typename T> using QP = priority_queue<T,vector<T>,greater<T>>;

const int N = 2e5 + 10;
const ll inf = 1e18;
vector<pair<ll,ll>> g[N];
vector<ll> dist(N, inf);
vector<ll> par(N, -1);

void dijkstra(int src){
    QP<pair<ll,ll>> pq;
    pq.push(make_pair(0,src));
    dist[src]=0;
    par[src] = -1; 

    while(pq.size()){
        ll v = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();

        if(dist[v] < dis) continue;
        
        for(auto &x : g[v]){
            ll c = x.first;
            ll wt = x.second;
            
            if(dist[v] + wt < dist[c]){
                dist[c] = dist[v] + wt;
                par[c] = v;
                pq.push(make_pair(dist[c],c));
            }
        }
    }
}