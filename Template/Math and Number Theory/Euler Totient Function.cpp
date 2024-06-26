const int MAX = 100001;
bool isPrime[MAX+1];

// Stores prime numbers upto MAX - 1 values
vector<ll> p;

// Finds prime numbers upto MAX-1 and
// stores them in vector p
void sieve(){
    for (ll i = 2; i<= MAX; i++){
        // if prime[i] is not marked before
        if (isPrime[i] == 0){
            // fill vector for every newly
            // encountered prime
            p.push_back(i);
            // run this loop till square root of MAX,
            // mark the index i * j as not prime
            for (ll j = 2; i * j<= MAX; j++)
                isPrime[i * j]= 1;
        }
    }
}

// function to find totient of n
ll phi(ll n){
    ll res = n;
    // this loop runs sqrt(n / ln(n)) times
    for (ll i=0; p[i]*p[i] <= n; i++){
        if (n % p[i]== 0){
            // subtract multiples of p[i] from r
            res -= (res / p[i]);
            // Remove all occurrences of p[i] in n
            while (n % p[i]== 0) n /= p[i];
        }
    }
    // when n has prime factor greater
    // than sqrt(n)
    if (n > 1) res -= (res / n);
    return res;
}