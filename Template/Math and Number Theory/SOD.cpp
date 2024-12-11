int SOD[N];
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
 
void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {2};
 
    for (int p = 2; p <= maximum; p += 2) {
        prime[p] = p == 2;
        smallest_factor[p] = 2;
    }
 
    for (int p = 3; p * p <= maximum; p += 2)
        if (prime[p])
            for (int i = p * p; i <= maximum; i += 2 * p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
 
    for (int p = 3; p <= maximum; p += 2)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
        }
}

void sum_of_div(){ // SOD(n)= (p1^(e1+1)-1)/(p1-1) * (p2^(e2+1)-1)/(p2-1) * .......
    sieve(N);
    SOD[1]=1;
    for(ll i=2;i<N;i++){
        ll ans=1;
        ll now=i;
        ll a;
        while(now>1){
            a=smallest_factor[now];
            ll p=a;
            while(now%a==0){
                now/=a;
                p*=a;
            }
            ans*=(p-1)/(a-1);
        }
        SOD[i]=ans;
    }
}