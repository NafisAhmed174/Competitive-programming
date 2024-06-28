vector<int> prime;
vector<int> primes;

void sieve(int n){
    prime.resize(n + 1);
    for (int i=2; i <= n; ++i) {
        if (prime[i] == 0) {
            prime[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] <= n; ++j) {
            prime[i * primes[j]] = primes[j];
            if (primes[j] == prime[i]) {
                break;
            }
        }
    }
}