struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int egcd(int a, int b, int& x, int& y){
    if (!b) {y = 0, x = 1; return a;}
    int g = egcd(b, a % b, y, x);
    y -= ((a / b) * x);
    return g;
}

int discrete_log(int g, int h, int p){
    // returns smallest x such that (g^x) % p = h, -1 if none exists
    // function returns x, the discrete log of h with respect to g modulo p

    if (h >= p) return -1;
    if ((g % p) == 0){
        if (h == 1) return 0; // return -1 if strictly positive integer solution is required
        else return -1;
    }

    int i, c, x, y, z, r, m, counter = 0;
    long long v = 1, d = 1, mul = 1, temp = 1 % p;

    for (int i = 0; i < 100; i++){
        if (temp == h) return i;
        temp = (temp * g) % p;
    }

    while ((v = __gcd(g, p)) > 1){
        if (h % v) return -1;
        h /= v, p /= v;
        d = (d * (g / v)) % p;
        counter++;
    }

    m = ceil(sqrt(p)); // try sqrtl()
    unordered_map <int, int,custom_hash> mp;

    for (i = 0; i < m; i++){
        if(!mp[mul]) mp[mul] = i + 1;
        mul = (mul * g) % p;
    }

    for (i = 0; i < m; i++){
        z = egcd(d, p, x, y);
        c = p / z;
        r = ((((long long)x * h) / z) % p + p) % p;
        if (mp[r]) return ((i * m) + mp[r] + counter - 1);
        d = (d * mul) % p;
    }
    return -1;
}