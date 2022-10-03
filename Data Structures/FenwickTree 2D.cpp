const int mxN = 3e5 + 10;
template <typename T>
struct Fenwick {
    const ll n;
    vector<vl> a;
    Fenwick(ll n) : n(n+1), a(6+10,vl(n+10)) {}
    void add(ll bit, ll x, ll v) {
        for (ll i = x; i < n; i += i & -i) {
            a[bit][i] += v;
        }
    }
    T sum(ll bit, ll x) {
        T ans = 0;
        for (ll i = x; i > 0; i -= i & -i) {
            ans += a[bit][i];
        }
        return ans;
    }
    T rangeSum(ll bit, ll l, ll r) {
        return sum(bit,r) - sum(bit,l);
    }
 
    void check(){
        FORE(i,a)
            cout<<i<<" ";
        cout<<'\n';
    }
};
void solve(){
    ll n,q; cin >> n >> q;
    Fenwick<ll> fen(n+1);
    ll cnt[7]; FOR(i,1,6+1) cin >> cnt[i];
    
    string s; cin >> s;
    ll len = sz(s);
    FOR(i,0,len){
        ll curr = s[i]-'0';
        fen.add(curr,i+1,1);
    }

    FOR(i,0,q){
        ll num; cin >> num;
        if(num == 3){
            ll l,r; cin >> l >> r;
            ll ans = 0;
            FOR(j,1,6+1) ans += fen.rangeSum(j,l-1,r)*cnt[j];
            cout<<ans<<'\n';
        }
        else if(num == 1){
            ll pos,newVal; cin >> pos >> newVal;
            ll cambioCon = s[pos-1]-'0';
            s[pos-1] = newVal+'0';
            fen.add(newVal,pos,1);
            fen.add(cambioCon,pos,-1);    
        }
        else{
            ll gem,val; cin >> gem >> val;
            cnt[gem] = val;
        }
    }
}     
