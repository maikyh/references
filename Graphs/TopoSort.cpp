const int mxN = 1e4 + 10;
vi adj[mxN];
int degree[mxN];

vi toposort(int n){
    queue<int> q;
    FOR(i,0,n){
        if(degree[i] == 0)
            q.push(i);
    }

    vi ans;
    int cnt = 0;
    
    while(!q.empty()){
        int node = q.front(); 
        q.pop();

        ans.pb(node+1);
        degree[node] = -1;
        cnt++;
        
        for(auto &neigh : adj[node]){
            if(--degree[neigh] == 0)
                q.push(neigh);
        }
    }
    if(cnt != n)
        return {};
    return ans;
}

void solve(){
    int n,m; cin >> n >> m;
    while(m--){
        int u,v; cin >> u >> v; u--; v--;
        adj[u].pb(v);
        degree[v]++;
    }

    vi ans = toposort(n);
    if(sz(ans) != n)
        cout<<"No Toposort"<<'\n';
    else
        cout<<ans<<'\n';
}   
