const int mxN = 1e5 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
long long true_rand(long long n) {
    // Returns a random number between 0 and n - 1 inclusive using mt19937.
    uniform_int_distribution<long long> uid(0, n - 1);
    return uid(rng);
}
 
class Factorize{    //ALL OF THE BELOW CODE WAS TAKEN FROM cp-algorithms.com
 public:
    ll binpower(ll base, ll e, ll mod) {
        ll result = 1;
        base %= mod;
        while (e) {
            if (e & 1)
                result = (ull)result * base % mod;
            base = (ull)base * base % mod;
            e >>= 1;
        }
        return result;
    }
 
    bool check_composite(ll n, ll a, ll d, int s) {
        ll x = binpower(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (int r = 1; r < s; r++) {
            x = (ull)x * x % n;
            if (x == n - 1)
                return false;
        }
        return true;
    };
 
    bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
        if (n < 2)
            return false;
 
        int r = 0;
        ll d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            r++;
        }
 
        for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (n == a)
                return true;
            if (check_composite(n, a, d, r))
                return false;
        }
        return true;
    }
 
    long long mult(long long a, long long b, long long mod) {
        return (ull)a * b % mod;
    }
 
    long long f(long long x, long long c, long long mod) {
        return (mult(x, x, mod) + c) % mod;
    }
 
    long long rho(long long n) {
        if(n%2==0)  return 2;
        long long x0=(true_rand(LLONG_MAX)%(n-2))+2;
        long long c=(true_rand(LLONG_MAX)%(n-1))+1;
        long long x = x0;
        long long y = x0;
        long long g = 1;
        while (g == 1) {
            x = f(x, c, n);
            y = f(y, c, n);
            y = f(y, c, n);
            g = __gcd(abs(x - y), n);
            if (g == n) return rho(n);
        }
        return g;
    }
 
    void factor(int x,vector<int>& pf){
        if(x==1)    return;
        if(!MillerRabin(x)){
            int y=rho(x);
            factor(y,pf);
            factor(x/y,pf);
        }else{
            pf.push_back(x);
            return;
        }
    }
 
};
 
void solve(){
    int n; cin >> n;
    vi a(n); cin >> a;
    map<int,int> mp;

    bool flg = 0;
    FOR(i,0,n){
        if(a[i] == 1) continue;
        vector<int> facts;
        Factorize fa;
        fa.factor(a[i],facts);
        sort(all(facts));
        erase_duplicates(facts);
        FORE(p,facts){
            mp[p]++;
            if(mp[p] > 1) flg = 1;
        }
        
    }
    cout<<(flg?"YES":"NO")<<'\n';
}
