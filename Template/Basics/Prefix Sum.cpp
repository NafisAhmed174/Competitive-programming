#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct prefixSum{
    vector<ll> pref;

    void build(){
        for(ll i = 1; i < pref.size(); i++){
            pref[i] += pref[i - 1];
        }
    }
    prefixSum(){}
    prefixSum(vector<int> &v){
        for(auto x: v) pref.push_back(x);
        build();
    }
    prefixSum(vector<ll> &v){
        pref = v;
        build();
    }

    ll query(ll l, ll r){ // 0-based
        if(l > r) swap(l, r);
        ll ans = pref[r];
        if(l) ans -= pref[l - 1];
        return ans;
    }
};


int main(){

    vector<int> v = {1, 2, -3, 4, 5};
    vector<ll> v2 = {-1, 2, -3, 4, -5};

    prefixSum pf(v);
    prefixSum pf2(v2);

    cout << pf.query(0, 2) << "\n";
    cout << pf.query(1, 3) << "\n";
    cout << pf.query(0, 4) << "\n";
    cout << pf.query(2, 4) << "\n";

    cout << pf2.query(0, 2) << "\n";
    cout << pf2.query(1, 3) << "\n";
    cout << pf2.query(0, 4) << "\n";
    cout << pf2.query(2, 4) << "\n";

    return 0;
}