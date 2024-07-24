#include<bits/stdc++.h>
using namespace std;

using ll = long long;


struct prefixSum2D {
    vector<vector<ll>> pref;
    
    void build() {
        for(int i = 1; i < pref.size(); i++) {
            for(int j = 1; j < pref[i].size(); j++) {
                pref[i][j] += pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1];
            }
        }
    }

    prefixSum2D(vector<vector<int>> &v){
        int n = v.size();
        int m = v[0].size();
        pref = vector<vector<ll>> (n + 1, vector<ll> (m + 1, 0));

        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= m; j++){
                pref[i][j] = v[i - 1][j - 1];
            }
        }
        build();
    }

    prefixSum2D(vector<vector<ll>> &v){
        int n = v.size();
        int m = v[0].size();
        pref = vector<vector<ll>> (n + 1, vector<ll> (m + 1, 0));

        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= m; j++){
                pref[i][j] = v[i - 1][j - 1];
            }
        }
        build();
    }
    
    ll query(ll a,ll b,ll c,ll d){ // 0-based 
        return pref[c + 1][d + 1] - pref[a][d + 1] - pref[c + 1][b] + pref[a][b];
    }
    // rectangular query
    // (a, b) upper left corner cell
    // (c, d) lower right corner cell
};


int main(){
    
    vector<vector<int>> mat1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    // 1 2 3
    // 4 5 6
    // 7 8 9

    prefixSum2D pf(mat1);

    cout << pf.query(1, 1, 1, 1) << "\n";
    cout << pf.query(0, 0, 2, 2) << "\n";
    cout << pf.query(0, 0, 0, 2) << "\n";
    cout << pf.query(1, 0, 1, 2) << "\n";
    cout << pf.query(1, 1, 2, 2) << "\n";

    return 0;
}