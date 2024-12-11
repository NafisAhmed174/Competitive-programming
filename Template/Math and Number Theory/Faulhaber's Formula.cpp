//Faulhaber's Formula
//faulhaber(n,k) = 1^k + 2^k + 3^k + ... + n^k modulo ANY number
//Complexity : O(k^2)
#define MAX 1005


ll S[MAX][MAX];

void Stirling2(){
    S[0][0] = 1;
    for(int i = 1; i < MAX; i++){
        S[i][0] = 0;
        for(int j = 1; j <= i; j++){
            S[i][j] = ((S[i - 1][j] * j) % M + S[i - 1][j - 1]) % M;
        }
    }
}

ll faulhaber(ll n, int k){
    if (!k) return n % M;

    ll res = 0;
    for(int j = 0; j <= k; j++){
        ll Div = j + 1;
        ll Mul = 1;
        ll r = n % Div + 1;
        if(r == Div) r = 0;

        for(int x = 0; x <= j; x++){
            if(x == r) Mul *= (n - x + 1) / Div;
            else Mul *= (n - x + 1);
            Mul %= M;
        }

        res += (S[k][j] * Mul) % M;
        if(res >= M) res -= M;
        if(res < 0) res+= M;
    }
    return res;
}