const int mxN = 2e5;
template<class T> struct Seg {
    int n;
    T ID = 0;
    vector<T> seg;
    T comb (T a, T b) {return a + b;}
    void init (int _n) {n = _n; seg.assign(n * 2, ID);}
    void pull (int p) { // SUM;
        seg[p] = comb(seg[p * 2], seg[p * 2 + 1]);
    }
    void upd (int i, T val) { // SUM; sgt.upd(i,x[i]); (ll x = sgt.seg[a-1+n] | sgt.upd(a-1,b-x)); update the value at position k to  u; what is the sum of values in range [a,b]?
        seg[i+=n] += val;
        for (i /= 2; i; i /= 2) {
            pull(i);
        }
    }
    ll sum(int a, int b){ // SUM;
        a+=n, b+=n;
        ll s = 0;
        while(a<=b){
            if (a&1) s+= seg[a++]; //a is right child
            if (~b&1) s+= seg[b--]; // b is left child
            a>>=1, b>>=1;
        }
        return s;
    }
    void updmn(int k, int x){ // MIN; sgt.upd(i,x[i]); sgt.upd(a-1,b); update the value at position k to u; what is the minimum value in range [a,b]?
        k+=n;
        seg[k] = x; k>>=1;
        while(k>=1){
            seg[k]  = min(seg[2*k], seg[2*k+1]);
            k>>=1;
        }
    }
    ll mn(int a, int b){ // MIN;
        a+=n, b+=n;
        ll s = INF;
        while(a<=b){
            if (a&1) s = min(s,seg[a++]); //a is right child
            if (~b&1) s = min(s,seg[b--]); // b is left child
            a>>=1, b>>=1;
        }
        return s;
    } 
};

//Range Update Queries
//increase each value in range [a,b] by u
//what is the value at position k?
///////////////////START HERE////////////////////////
void solve(){
    int n,q;
    cin >> n >> q;
 
    Seg<ll> sgt;
 
    sgt.init(n+1);
    vi a(n+1);
    FOR(i,1,n+1){
        cin >> a[i];
        sgt.upd(i,a[i] - a[i-1]);
    }
 
    FOR(i,0,q){
        int num;
        cin >> num;
        if(num==2){
            int v;
            cin >> v;
            cout<<sgt.sum(1,v)<<'\n';
        }
        else{
            ll x,y,u;
            cin >> x >> y >> u;
            sgt.upd(x,u);
            sgt.upd(y+1,-u);
        }
    }
}         
/////////////////END HERE//////////////////////////////
