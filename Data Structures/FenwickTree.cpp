const int mxN = 3*1e5 + 10;
template <typename T>
struct Fenwick {
    const ll n;
    vector<ll> a;
    Fenwick(ll n) : n(n+1), a(n+1) {}
    void add(ll x, ll v) {
        for (ll i = x + 1; i <= n; i += i & -i) {
            a[i] += v;
        }
    }
    T sum(ll x) {
        T ans = 0;
        for (ll i = x; i > 0; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }
    T rangeSum(ll l, ll r) {
        return sum(r) - sum(l);
    }
 
    void check(){
        FORE(i,a)
            cout<<i<<" ";
        cout<<'\n';
    }
};
void solve(){
    ll n,q;
    cin >> n >> q;
    Fenwick<ll> fen(n);
    FOR(i,0,n){
        ll x;
        cin >> x;
        fen.add(i,x);
    }
    ll ans = 0;
    while(q--){
        ll num;
        cin >> num;
        if(num == 2){
            ll l,r;
            cin >> l >> r;
            cout<<fen.rangeSum(l-1,r)<<'\n';
        }
        else{
            ll a,x;
            cin >> a >> x;
            fen.add(a-1,x-fen.rangeSum(a-1,a));
        }
    }
}      
