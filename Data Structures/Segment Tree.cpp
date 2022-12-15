const int mxN = 1e5 + 10;
int t[4 * mxN], ar[mxN];
void init(int b, int e, int node){
    if(b == e){
        t[node] = ar[b];
        return;
    }
    int mid = (b + e) / 2;
    init(b,mid,node*2);
    init(mid+1,e,node*2+1);
    t[node] = min(t[node*2],t[node*2+1]);
}
int query(int b, int e, int node, int i, int j){
    if(i <= b && e <= j) return t[node];
    int mid = (b+e) / 2;
    if(j <= mid) return query(b,mid,node*2,i,j);
    if(mid < i) return query(mid+1,e,node*2+1,i,j);
    return min(query(b,mid,node*2,i,j),query(mid+1,e,node*2+1,i,j)); 
}
void update(int b, int e, int node, int pos, int val){
    if(b == e){
        t[node] = val;
        return;
    }
    int mid = (b+e) / 2;
    if(pos <= mid) update(b,mid,node*2,pos,val);
    else update(mid+1,e,node*2+1,pos,val);
    t[node] = min(t[node*2],t[node*2+1]);
}
void solve(){
    int n,m; cin >> n >> m;
    FOR(i,0,n) cin >> ar[i];
    init(0,n-1,1);
    while(m--){
        int op; cin >> op;
        if(op == 1){
            int pos, val; cin >> pos >> val;
            update(0,n-1,1,pos,val);
        }
        else{
            int l,r; cin >> l >> r;
            int ans = query(0,n-1,1,l,r-1);
            cout<<ans<<'\n';
        }
    }
}
