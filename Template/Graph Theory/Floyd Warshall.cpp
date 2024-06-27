const int N = 500 + 10;
ll dp[N][N];
const ll inf = 1e18;

void floyd_warshall(int n){
    for(ll i = 1; i <= n; i++){
        dp[i][i]=0;
    }
    for(ll k = 1; k <= n; k++){
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                if(dp[i][k] != inf && dp[k][j] != inf){
                    dp[i][j]=min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
}