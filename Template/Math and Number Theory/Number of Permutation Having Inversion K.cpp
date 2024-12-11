// Function to count permutations with
// K inversions
ll func(ll N, ll K){
    // Store number of permutations
    // with K inversions
    ll dp[2][K+1];
  
    ll mod=1000000007;
  
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<=K;j++){
            // If N = 1 only 1 permutation
            // with no inversion
            if(i==1) dp[i%2][j]=(j==0);
  
            // For K = 0 only 1 permutation
            // with no inversion
            else if(j==0) dp[i%2][j]=1;
  
            // Otherwise Update each dp
            // state as per the reccurrance
            // relation formed
            else{
                dp[i%2][j]=(dp[i%2][j-1]%mod + (dp[1-i%2][j]-((max(j-(i-1),0LL)==0)? 0:dp[1-i%2][max(j-(i-1),0LL)-1])+mod)%mod)%mod;
            }
        }
    }
  
    return dp[N%2][K];
}