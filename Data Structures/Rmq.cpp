struct STree { // segment tree for min over integers
    vector<int> st;int n;
    STree(int n): st(4*n+5,INF), n(n) {}
    void init(int k, int s, int e, int *a){
        if(s+1==e){st[k]=a[s];return;}
        int m=(s+e)/2;
        init(2*k,s,m,a);init(2*k+1,m,e,a);
        st[k]=min(st[2*k],st[2*k+1]);
    }
    void upd(int k, int s, int e, int p, int v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=min(st[2*k],st[2*k+1]);
    }
    int query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return INF;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return min(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void init(int *a){init(1,0,n,a);}
    void upd(int p, int v){upd(1,0,n,p,v);}
    int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);
void solve(){
    int n,q;
    cin >> n >> q;
    STree rmq(n);
    int a[n];
    FOR(i,0,n)
        cin >> a[i];
    rmq.init(a);
    while(q--){
        int num;
        cin >> num;
        if(num == 2){
            int l,r;
            cin >> l >> r;
            cout<<rmq.query(l-1,r)<<'\n';
        }
        else{
            int a,x;
            cin >> a >> x;
            rmq.upd(a-1,x);
        }
    }
}         
