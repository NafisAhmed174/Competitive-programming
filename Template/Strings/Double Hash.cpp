/// Hashing Bases & MOD
///           0123456789
#define Base1 10000019ULL
#define Base2 10000079ULL
#define Base3 10000103ULL
#define MOD1  1000000007ULL
#define MOD2  1000000009ULL
#define MOD3  1000000021ULL
 
char a[N],b[N];
ull  B1[N],B2[N];
bool flag=0;
 
void Init(){
    flag=1;
    B1[0] = B2[0] = 1;
 
    for (int i=1;i<N;i++){
        B1[i] = (B1[i-1]*Base1);
        B2[i] = (B2[i-1]*Base2);
    }
}
 
struct Hash{
    pair<ull,ull> H[N];
    int digit[N];
    int L;
 
    Hash(){
        L = 0;
        H[0] = mp(0,0);
        if(!flag) Init();
    }
 
    void Insert(char x){
        digit[++L] = x-'a'+1;
        H[L].ff = (H[L-1].ff * Base1 + digit[L]);
        H[L].ss = (H[L-1].ss * Base2 + digit[L]);
    }
 
    pair<ull,ull> SubStr(int l,int r){
        int len = r-l+1;
 
        pair<ull,ull> ans;
 
        ans.ff = (H[r].ff - (H[l-1].ff * B1[len]));
        ans.ss = (H[r].ss - (H[l-1].ss * B2[len]));
 
        return ans;
    }
 
    pair<ull,ull> Concate(pair<ull,ull> h,int l,int r){
        pair<ull,ull> x = SubStr(l,r);
 
        h.ff = h.ff * B1[r-l+1] + x.ff;
        h.ss = h.ss * B2[r-l+1] + x.ss;
 
        return h;
    }
 
    bool operator==(const Hash& p)const{
        return L == p.L && H[L] == p.H[p.L];
    }
 
    pair<ull,ull>& operator[] (int index){
        return H[index];
    }
};

Hash A,B;