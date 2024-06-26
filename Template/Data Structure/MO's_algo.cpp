#include<iostream>
using namespace std;

#define ll long long
const int N = 2e5 + 10;
const int B = 440;
ll f[N], v[N],res[N];
ll now=0;

struct query {
    ll l, r, id;
    bool operator < (const query &x) const {
        if(l / B == x.l / B) return ((l / B) & 1) ? r > x.r : r < x.r;
        return l / B < x.l / B;
    }
} Q[N];



inline void add_left(int i) {
    int x = v[i];
    now += 1LL * (f[x] + f[x] + 1) * x;
    ++f[x];
}
inline void add_right(int i) {
    int x = v[i];
    now += 1LL * (f[x] + f[x] + 1) * x;
    ++f[x];
}
inline void rem_left(int i) {
    int x = v[i];
    now -= 1LL * (f[x] + f[x] - 1) * x;
    --f[x];
}
inline void rem_right(int i) {
    int x = v[i];
    now -= 1LL * (f[x] + f[x] - 1) * x;
    --f[x];
}
int main(){
    int n,k,i;
    cin >> n >> k;
    for(i=1;i<=n;i++) cin>>v[i];
    for(i=1;i<=k;i++) {
        cin>>Q[i].l>>Q[i].r;
        Q[i].id=i;
    }

    sort(Q+1,Q+k+1);
    int l=1,r=0;
    for(i=1;i<=k;i++) {
        ll L=Q[i].l,R = Q[i].r;
        if(R<l) {
            while(l>L) add_left(--l);
            while(l<L) rem_left(l++);
            while(r<R) add_right(++r);
            while(r>R) rem_right(r--);
        }else {
            while(r<R) add_right(++r);
            while(r>R) rem_right(r--);
            while(l>L) add_left(--l);
            while(l<L) rem_left(l++);
        }
        res[Q[i].id]=now;
    }

    for(int i = 1; i <= k; i++) cout << res[i] << " ";
    cout << "\n";
}