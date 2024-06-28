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