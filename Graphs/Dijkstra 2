const int mxN = 1e5 + 10;
vpl adj[mxN];
ll dist[mxN], par[mxN];
bool vis[mxN];
bool dijkstra(int n, int s, int t){ // int n, int source, int to
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    fill(dist, dist+n+1, 1e18);

    pq.push(pi(0, s));
    dist[s] = 0;
    par[s] = -1;

    while(!pq.empty()) {
        ll u = pq.top().second; pq.pop();

        if(u == t) return true;
        vis[u] = 1;

        for(auto &neigh : adj[u]) {
            ll v = neigh.first, w = neigh.second;

            if(!vis[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(pi(dist[v], v));
                par[v] = u;
            }
        }
    }

    return false;
}
void solve() {
    int n,m; cin >> n >> m;
    clr(adj,0);

    while(m--) {
        ll u,v,w; cin >> u >> v >> w;
        adj[u].push_back(pi(v, w));
        adj[v].push_back(pi(u, w));
    }

    if(dijkstra(n, 1, n)) {
        vi path;

        for(int v = n; v != -1; v = par[v]) path.pb(v);

        for(int i = path.size()-1; i >= 0; --i) 
            cout<<path[i]<<" ";
        cout<<'\n';
    }
    else 
        cout<<"-1"<<'\n';

    FOR(i,1,n+1) cout<<(dist[i])<<" ";
}
