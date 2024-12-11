struct line {
    ll m, c; // y = mx+c
    line(ll _m, ll _c) {
        m = _m, c = _c;
    }
};

struct CHT {
    vector < line > vec;
    ll t, ptr;
    void init(ll x) {
        t = x, ptr = 0;
        vec.clear();
    }
    inline ll func(ll idx, ll x) {
        return vec[idx].m * x + vec[idx].c;
    }
    bool bad(line f1, line f2, line f3) {
        __int128 a = (f3.c - f1.c);
        a = a * (f1.m - f2.m);
        __int128 b = (f2.c - f1.c);
        b = b * (f1.m - f3.m);

        if(t == 1) return a <= b; // m_i > m_i+1. min query.
        if(t == 2) return a >= b; // m_i > m_i+1. max query.
        if(t == 3) return a >= b; // m_i < m_i+1. min query.
        if(t == 4) return a <= b; // m_i < m_i+1. max query.
        assert(0);
        return 69;
    }
    void add(line x) {
        ll sz = vec.size();
        while(sz >= 2 && bad(vec[sz - 2], vec[sz - 1], x)) {
            vec.pop_back();
            sz--;
        }
        vec.push_back(x);
    }
    ll ask(ll x) // ternary search
    {
        if(vec.empty())
        return 0;

        ll lo = 0, hi = vec.size() - 1;
        ll ret = (t & 1)? inf : -inf;
        while(lo <= hi) {
            ll mid1 = (lo + (hi - lo) / 3);
            ll mid2 = (hi - (hi - lo) / 3);

            ll ans1 = func(mid1,x);
            ll ans2 = func(mid2,x);

            if(ans1 > ans2) {
                if(t & 1)
                    ret = min(ret, ans2), lo = mid1 + 1;
                else
                    ret = max(ret, ans1), hi = mid2 - 1;
            }
            else {
                if(t & 1)
                    ret =  min(ret,ans1), hi = mid2 - 1;
                else
                    ret = max(ret,ans2), lo = mid1 + 1;
            }
        }
        return ret;
    }
    ll ask1(ll x) // pointer search (linear)
    {
        if(vec.empty())
            return 0;
        if(ptr >= vec.size()) ptr = vec.size() - 1;

        while(ptr < (vec.size() - 1)) {
            if(t & 1) {
                if(func(ptr,x) > func(ptr + 1,x))
                    ptr++;
                else break;
            }
            else {
                if(func(ptr,x) < func(ptr + 1,x))
                    ptr++;
                else break;
            }
        }
        return func(ptr,x);
    }
};