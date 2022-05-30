const int mxN = 10005;
int graph[mxN][mxN];
int dist[mxN][mxN];
void floydWarshall(int n) { // O(n^3)
    for(int i = 0; i<n; i++) 
        for(int j = 0; j<n; j++) 
            dist[i][j] = graph[i][j];

    for(int k = 0; k<n; k++)  {
        for(int i = 0; i<n; i++)  {
            for(int j = 0; j<n; j++)  {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve() {
    for(int i = 0; i<mxN; i++)
        for(j = 0; j<mxN; j++)
            dist[i][j] = INF;

    int n, m;
    cin >> n >> m;
    for(int i = 0; i<m; i++) {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    floydWarshall(n);
}
