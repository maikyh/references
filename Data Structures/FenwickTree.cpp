const int mxN = 3e5 + 10;
template <typename T>
struct Fenwick {
    const ll n;
    vector<ll> a;
    Fenwick(ll n) : n(n+1), a(n+10) {}
    void add(ll x, ll v) {
        for (ll i = x; i < n; i += i & -i) {
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
void solve(){ //1-Indexed
    int n, tt = 0;
    while(cin >> n && n){
        if(tt >= 1) cout<<'\n';
        cout<<"Case "<<++tt<<":"<<'\n';
        Fenwick<ll> fen(n+1);
        FOR(i,1,n+1){
            ll x; cin >> x;
            fen.add(i,x);
        }
        char c;
        while(cin >> c){
            if(c == 'E'){
                cin >> c >> c; break;
            }
            else if(c == 'M'){
                ll l,r; cin >> l >> r;
                cout<<fen.rangeSum(l-1,r)<<'\n';
            }
            else{
                ll a,x; cin >> a >> x;
                fen.add(a,x-fen.rangeSum(a-1,a));
            }
        }
    }
}
