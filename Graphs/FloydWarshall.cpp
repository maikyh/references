const int mxN = 500 + 10;
ll graph[mxN][mxN];
void floydWarshall(int n) { // O(n^3)
    FOR(k,0,n)
        FOR(i,0,n)
            FOR(j,0,n)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);    
}

void solve() {
    ll n,m,q; cin >> n >> m >> q;
    FOR(i,0,mxN){
        FOR(j,0,mxN)
            graph[i][j] = 1e18;
        graph[i][i] = 0;
    }

    while(m--){
        ll a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a][b] = min(graph[a][b],c);
        graph[b][a] = min(graph[b][a],c);
    }
    
    floydWarshall(n);
    while(q--){
        int u,v; cin >> u >> v; u--; v--;
        cout<<(graph[u][v] >= 1e18 ? -1 : graph[u][v])<<'\n';
    }
}
