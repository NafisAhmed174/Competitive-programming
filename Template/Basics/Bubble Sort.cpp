#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll bubbleSort(vector<ll> & v){
    ll swapCount = 0, n = v.size();
    for(ll step = 1; step <= n - 1; step++) {
        for (ll i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}


int main(){
    
    vector<ll> vec = {5,3,4,2,1};

    cout << bubbleSort(vec) << "\n";
    for(auto x : vec) cout << x << " ";
    cout << "\n";

    return 0;
}