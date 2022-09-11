const int mxN = 1e5 + 10;
vpl adj1[mxN];
ll dist1[mxN], par1[mxN];

bool vis[mxN];
bool reached = 0;

void dijkstra(int s, int t, ll dist[], vpl adj[], ll par[]){ // int n, int source, int to
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    FOR(i,0,mxN) dist[i] = 1e18;
    clr(vis,0);
    pq.push(pi(0, s));
    dist[s] = 0;
    par[s] = -1;
    reached = 0;

    while(!pq.empty()){
        ll u = pq.top().se; pq.pop();
        if(u == t) reached = 1;
        if(vis[u]) continue;
        vis[u]=1;
        for (auto &neigh: adj[u]){
            ll v = neigh.first, w = neigh.second;
            if (dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
                par[v] = u;
            }
        }
    }
}

vi restorePath(int t){
    int n = t;

    vi path;
    for(int v = n; v != -1; v = par1[v]) 
        path.pb(v);
    
    reverse(all(path));
    return path;
}

void solve() {
    ll n,m; cin >> n >> m;
    while(m--) {
        ll u,v,w; cin >> u >> v >> w;
        adj1[u].pb(pi(v,w));
        adj1[v].pb(pi(u,w));
    }

    dijkstra(1,n,dist1,adj1,par1);

    if(!reached){
        cout<<-1<<'\n';
        return;
    }

    vi path = restorePath(n);
    ROF(i,0,path.size())
        cout<<path[i]<<" ";

    // FOR(i,1,n+1) cout<<(dist[i])<<" ";
}   
