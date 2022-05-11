template <typename T>
struct Fenwick {
    const int n;
    vector<int> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
 
    void check(){
        FORE(i,a)
            cout<<i<<" ";
        cout<<'\n';
    }
};
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
        a[i]--;
    }
    Fenwick<int> fen(n);
    ll ans = 0;
    FOR(i,0,n) {
        ans += fen.rangeSum(a[i],n);
        fen.add(a[i], 1);
    }
  
    cout << ans << "\n";
}        
