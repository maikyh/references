const int mxN = 100 + 10;
vt<vt<pl>> adj;
bool spfa(int s, vl& d) {
    ll n = adj.size();
    d.assign(n, INF);
    vl cnt(n, 0);
    vb inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}
void solve() {
    ll n,m; cin >> n >> m;
    adj.resize(n);
    while(m--){
        ll u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    vl dist;
    spfa(1,dist);
    FOR(i,1,n+1) cout<<dist[i]<<" ";
}   
