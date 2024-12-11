struct Fraction{
    long long x,y;
    // 約分
    void reduc(){
        ll minus = 1;
        if(x < 0) minus *= -1;
        if(y < 0) minus *= -1;
        ll g = gcd(abs(x), abs(y));
        x = minus * abs(x) / g;
        y = abs(y) / g;
    }
    
    Fraction(ll x = 0, ll y = 1): x(x), y(y) {reduc();};
 
    bool operator<(const Fraction& right) const {return x*right.y < y*right.x;}
    bool operator<=(const Fraction& right) const {return x*right.y <= y*right.x;}
    bool operator>(const Fraction& right) const {return x*right.y > y*right.x;}
    bool operator>=(const Fraction& right) const {return x*right.y >= y*right.x;}
    bool operator==(const Fraction& right) const {return x == right.x && y == right.y;}
    Fraction operator-() const {return Fraction(-x, y);}
    Fraction& operator+=(const Fraction& v){
        x = x*v.y + y*v.x;
        y *= v.y;
        reduc();
        return *this;
    }
    Fraction operator+(const Fraction& v) const {return Fraction(*this) += v;}
    Fraction& operator-=(const Fraction& v){
        x = x*v.y - y*v.x;
        y *= v.y;
        reduc();
        return *this;
    }
    Fraction operator-(const Fraction& v) const {return Fraction(*this) -= v;}
    Fraction& operator*=(const Fraction& v){
        x *= v.x;
        y *= v.y;
        reduc();
        return *this;
    }
    Fraction operator*(const Fraction& v) const {return Fraction(*this) *= v;}
    Fraction& operator/=(const Fraction& v){
        x *= v.y;
        y *= v.x;
        reduc();
        return *this;
    }
    Fraction operator/(const Fraction& v) const {return Fraction(*this) /= v;}
    Fraction inv() const {return Fraction(y,x);}
    Fraction pow(ll t) const {
        if(t < 0) return inv().pow(-t);
        Fraction a(1, 1), d = *this;
        while(t){
            d *= d;
            if(t & 1) a *= d;
            t >>= 1;
        }
        return a;
    }
 
    friend ostream& operator << (ostream& os, const Fraction& v){ return os << v.x << '/' << v.y;}
};