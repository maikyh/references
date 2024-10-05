void dfs(int node,int parent,vector<vector<int>> &adj,vector<int>&euler){
    euler.pb(node);
    for(auto x:adj[node]){
        if(x!=parent){
            dfs(x,node,adj,euler);
        }
    }
    euler.pb(node);
}
void push(int node,vector<ll>&lazy,vector<ll>&tree){
    if(lazy[node]!=0){
        tree[node] = 1LL << lazy[node];
        int l = 2*node+1;
        int r = l+1;
        if(l<sz(lazy)){
            lazy[l] = lazy[node];          
        }
        if(r<sz(lazy)){
            lazy[r] = lazy[node];         
        }
        lazy[node]= 0;   
    }

}


void init(int node,int b,int e,vector<ll> &tree,vector<int> &v,vector<int>&euler){
    if(b==e){
        tree[node]= 1LL << v[euler[b]];
        return;
    }

    int m = (b+e)/2;
    int l = 2*node+1;
    int r = l+1;

    init(l,b,m,tree,v,euler);
    init(r,m+1,e,tree,v,euler);
    // union bits left node and right node
    tree[node] = tree[l] | tree[r];
}

void update(int node,int b,int e,int i,int j,ll color,vector<ll>&tree,vector<ll>&lazy){
    push(node,lazy,tree);
    if(b>j || e<i){
        return;
    }
    if(b>=i && e<=j){
        lazy[node]=color;
        push(node,lazy,tree);
        return;
    }
  
    int m = (b+e)/2;
    int l = 2*node+1;
    int r = l+1;

    update(l,b,m,i,j,color,tree,lazy);
    update(r,m+1,e,i,j,color,tree,lazy);
    // if(j<=m){
    //     update(l,b,m,i,j,color,tree,lazy);
    // }else if(i>m){
    //     update(r,m+1,e,i,j,color,tree,lazy);
    // }else{
    //     update(l,b,m,i,j,color,tree,lazy);
    //     update(r,m+1,e,i,j,color,tree,lazy);        
    // }
    tree[node] = tree[l] | tree[r];

}

ll query(int node,int b,int e,int i,int j,vector<ll>&tree,vector<ll>&lazy){
    push(node,lazy,tree);
    if(b>j || e<i){
        return 0;
    }
    if(b>=i && e<=j){;
        return tree[node];
    }
  
    int m = (b+e)/2;
    int l = 2*node+1;
    int r = l+1;

    // ll setBits = 0;
    ll setBits=query(l,b,m,i,j,tree,lazy) | query(r,m+1,e,i,j,tree,lazy);
    // if(j<=m){
    //     setBits = setBits | query(l,b,m,i,j,tree,lazy);
    // }else if(i>m){
    //     setBits = setBits | query(r,m+1,e,i,j,tree,lazy);
    // }else{
    //     setBits = setBits | query(l,b,m,i,j,tree,lazy);
    //     setBits = setBits | query(r,m+1,e,i,j,tree,lazy);        
    // }
    return setBits;
}


void solve(){
    ll n,q;cin>>n>>q;
    vector<int>v(n);
    FOR(i,0,n){
        cin>>v[i];
    }

    vector<vector<int>>adj(n);

    FOR(i,0,n-1){
        ll u,z;cin>>u>>z;
        u--;z--;
        adj[u].pb(z);
        adj[z].pb(u);
    }

    //implementar euler tour
    vector<int>euler;
    dfs(0,-1,adj,euler);

    //obtener posiciones de cada nodo para segment tree
    vector<pair<int,int>> positions(n,{-1,-1});

    FOR(i,0,sz(euler)){
        if(positions[euler[i]].fi==-1){
            positions[euler[i]].fi=i;
        }else{
            positions[euler[i]].se=i;
        }
    }

    //init segment tree

    vector<ll>tree(sz(euler)*4,0);
    vector<ll>lazy(sz(euler)*4,0);

    init(0,0,sz(euler)-1,tree,v,euler);


    FOR(i,0,q){
        ll type;cin>>type;
        if(type==1){
            ll node,color;cin>>node>>color;
            node--;
            update(0,0,sz(euler)-1,positions[node].fi,positions[node].se,color,tree,lazy);
        }else{
            ll node;cin>>node;
            node--;
            //query
            ll ans = query(0,0,sz(euler)-1,positions[node].fi,positions[node].se,tree,lazy);
            ll cont =__builtin_popcountll(ans); 
            cout << cont << "\n";
        }
    }  
}
