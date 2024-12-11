// formula: floor sum upto n=2*floor sum upto k - k^2[k=sqrt(n)]
ll floorSum(int n){
    ll sum = 0;
    ll k = sqrt(n);
    // Summation of floor(n / i)
    for (int i = 1; i <= k; i++) {
        sum += Floor(n,i);
    }
    // From the formula
    sum *= 2;
    sum -= BigMod<ll>(k,2,LLONG_MAX);
    return sum;
}