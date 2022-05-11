const int mxN = 2e5;
pair<ll,ll> seg[1000005];
ll mark[1000005];
 
void push(ll k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].fi = seg[2*k + 1].fi = seg[k].fi/2;
        seg[2*k].se = seg[2*k + 1].se = 0;
        mark[2*k] = mark[2*k + 1] = 1;
    }   
}
 
void update(ll v, ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) return;
    if (a<=x && b>=y) {
        seg[k].se += v;
        return;
    }
    ll h = min(b,y) - max(a,x) + 1;
    push(k); 
    seg[k].fi += h*v;
    ll d = (x+y)/2;
    update(v, a, b, 2*k, x, d);
    update(v, a, b, 2*k + 1, d + 1, y);
}
ll assign(ll v, ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) return seg[k].fi + (y - x + 1)*seg[k].se;
    if (a <= x && b >= y) {
        seg[k].fi = (y-x+1)*v;
        seg[k].se = 0;
        mark[k] = 1; 
        return seg[k].fi;
    }
    push(k); 
    ll d = (x+y)/2;
    seg[2*k].se += seg[k].se,  seg[2*k + 1].se += seg[k].se;
    seg[k].se = 0;
    seg[k].fi = assign(v, a, b, 2*k, x, d) + assign(v, a, b, 2*k + 1, d + 1, y);
    return seg[k].fi;
 
}
ll sum(ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) {
        return seg[k].fi + (y-x+1)*seg[k].se;
    }
    push(k); 
    seg[k].fi += (y-x+1)*seg[k].se;
    seg[2*k].se += seg[k].se, seg[2*k + 1].se += seg[k].se;
    seg[k].se = 0;
    ll d = (x+y)/2;
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y);
}
 
void solve(){
    int n,q; cin>>n>>q;
    int nn =n;
    n = 1<<(int)ceil(log2(n));
    for (int i = 0; i< nn; i++) {
        int x; cin>>x;
        update(x,i,i,1,0,n-1);
    }
    while (q--) {
        int z;
        cin>>z;
        if (z == 1) {
            int a,b,x;
            cin>>a>>b>>x;
            a--,b--;
            update(x,a,b,1,0,n-1);
        }
        else if (z == 2) {
            int a,b,x;
            cin>>a>>b>>x;
            a--,b--;
            assign(x,a,b,1,0,n-1);
        }
        else {
            int a,b;
            cin>>a>>b; a--, b--;
            cout<<sum(a,b,1,0,n-1)<<'\n';
        }
    }
}           
