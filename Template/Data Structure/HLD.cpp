/* Operations:
 * 1 u x : set val[u] = x
 * 2 u v : sum of val[i] in (u,v) path
*/

const ll sz = 3e4 + 10;
vector <ll> g[sz];
ll sub[sz], in[sz], out[sz], head[sz], tim;
ll par[sz], tr[4*sz] ,ar[sz] , arr[sz];//ar[i]-> given val,set=> arr[in[i]]=ar[i]

void dfs_siz(ll u, ll p)
{
    sub[u] = 1, par[u] = p;
    for(ll &v : g[u]) {
        if(v == p)
            continue;
        dfs_siz(v, u);
        sub[u] += sub[v];
        if(sub[v] > sub[ g[u][0] ])
            swap(v, g[u][0]);
    }
}

/* DFS for Heavy-Light Decomposition
 * head[u] = Head of the chain of node u
 * Operations can be performed in [in[head[u]],in[u]] range.
 * As DFS-time is used, [in[u],out[u]] range can be used
   for performing operations on the subtree of node u.
*/
void dfs_hld(ll u, ll p)
{
    if(p == -1) head[u] = u; // root
    in[u] = ++tim;
    for(ll &v : g[u]) {
        if(v == p)
            continue;
        head[v] = (v==g[u][0]? head[u] : v);
        dfs_hld(v, u);
    }
    out[u] = tim;
}

ll merge(ll x,ll y){
    return x+y;
}

// Typical Segment Tree on [1, tim] range
void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        tr[node] = arr[lo];
        return;
    }
    ll mid = lo+hi>>1, lft=node<<1, rgt=lft|1;
    build(lo, mid, lft);
    build(mid+1, hi, rgt);
    tr[node] = merge(tr[lft],tr[rgt]);
}

void update(ll lo, ll hi, ll idx, ll v, ll node)
{
    if(lo > idx || hi < idx)
        return;
    if(lo == hi) {
        tr[node] = v;
        return;
    }
    ll mid = lo+hi>>1, lft=node<<1, rgt=lft|1;
    update(lo, mid, idx, v, lft);
    update(mid+1, hi, idx, v, rgt);
    tr[node] = merge(tr[lft],tr[rgt]);
}

ll query(ll lo, ll hi, ll l, ll r, ll node)
{
    if(lo > r || hi < l)
        return 0;
    if(lo >= l && hi <= r)
        return tr[node];
    ll mid = lo+hi>>1, lft=node<<1, rgt=lft|1;
    ll lq=query(lo, mid, l, r, lft);
    ll rq=query(mid+1, hi, l, r, rgt);
    return merge(lq,rq);
}
// Segment Tree Ends

inline bool isAncestor(int p,int u){
    return in[p]<=in[u]&&out[p]>=out[u];
}

void upd_val(ll u, ll val) {
    update(1, tim, in[u], val, 1);
}

ll query_path(ll u, ll v)
{
    ll ret = 0;
    while(!isAncestor(head[u],v)) {
        ret += query(1,tim, in[head[u]], in[u], 1);
        u=par[head[u]];
    }
    swap(u,v);
    while(!isAncestor(head[u],v)) {
        ret += query(1,tim, in[head[u]], in[u], 1);
        u=par[head[u]];
    }
    if(in[v]<in[u])swap(u,v);
    ret += query(1,tim, in[u], in[v], 1); // u is LCA
    return ret;
}

void clr(ll n) {
    tim = 0;
    for(ll i=0; i <=n; i++)
        g[i].clear();
}