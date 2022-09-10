const int mxN = 1e5 + 10;
vpl adj1[mxN];
ll dist1[mxN], par1[mxN];

vpl adj2[mxN];
ll dist2[mxN], par2[mxN];

bool vis[mxN];

void dijkstra(int s, int t, ll dist[], vpl adj[], ll par[]){ // int n, int source, int to
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    FOR(i,0,mxN) dist[i] = 1e18;
    clr(vis,0);
    pq.push(pi(0, s));
    dist[s] = 0;
    par[s] = -1;

    while(!pq.empty()){
        ll u = pq.top().se; pq.pop();
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
void solve() {
    ll n,m; cin >> n >> m;
    vt<array<ll,3>> edges;
    while(m--) {
        ll u,v,w; cin >> u >> v >> w;
        edges.pb({u,v,w});
        adj1[u].push_back(pi(v, w));
        adj2[v].push_back(pi(u, w));
    }

    ll mini = 1e18;
    dijkstra(1,n,dist1,adj1,par1);
    dijkstra(n,1,dist2,adj2,par2);
    FORE(edge,edges) {
        ll u = edge[0];
        ll v = edge[1];
        ll w = edge[2];
        ll curr = dist1[u] + dist2[v] + w/2;
        umin(mini,curr);
    }

    // FOR(i,1,n+1) cout<<(dist1[i])<<" ";
    // FOR(i,1,n+1) cout<<(dist2[i])<<" ";
    cout<<mini<<'\n';
}   
