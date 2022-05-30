const int mxN = 200005 + 100;
ll tt, n,k,x,y,w,a,b;
ll st[4*mxN];
 
void update(ll act, ll l, ll r, ll pos){
    if(l == r){
        st[act]++;
        return;
    }
    ll m = (l+r)/2;
    if(pos <= m)update(act*2, l,m,pos);
    else update(act*2+1, m+1,r,pos);
 
    st[act] = st[act*2] + st[act*2 +1];
    return;
}

ll sum(ll act, ll l, ll r, ll lq, ll rq){
    if(r < lq || rq < l)return 0;
    if(l >= lq && r <= rq)return st[act];
    ll m = (l+r)/2;
 
    return sum(act*2, l, m, lq,rq) + sum(act*2+1, m+1, r, lq,rq);
}

void solve(){
    cin >> n;
    for(int i = 0; i< 4*mxN; i++)
        st[i] = 0;
    
    ll arr[n] = {};
    
    for(int i = 0; i < n; i++)cin >> arr[i];
    ll res = 0;
  
    for(int i = 0; i < n; i++){
        res += sum(1,0, n, arr[i], n);
        update(1,0,n,arr[i]);
    }

    cout << res << '\n';
}    
