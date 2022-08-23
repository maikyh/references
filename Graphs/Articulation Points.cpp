// adj[u] = adjacent nodes of u
// ap = AP = articulation points
// p = parent
// disc[u] = discovery time of u
// low[u] = 'low' node of u

const int mxN = 1e4 + 10;
vi adj[mxN];
vector<int> low,disc,ap;
int Time = 0;

int dfsAP(int u, int p) {
  int children = 0;
  low[u] = disc[u] = ++Time;
  for (int& v : adj[u]) {
    if (v == p) continue; // we don't want to go back through the same path.
                          // if we go back is because we found another way back
    if (!disc[v]) { // if V has not been discovered before
      children++;
      dfsAP(v, u); // recursive DFS call
      if (disc[u] <= low[v]) // condition #1
        ap[u] = 1;
      low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
    } else // if v was already discovered means that we found an ancestor
      low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
  }
  return children;
}

void AP() {
  ap = low = disc = vector<int>(mxN);
  Time = 0;
  for (int u = 0; u < mxN; u++)
    if (!disc[u]){
      ap[u] = dfsAP(u, u) > 1; // condition #2
    }
}

void solve(){
    clr(adj,0);
    ap.clear();
    low.clear();
    disc.clear();
    int n,m;
    cin >> n >> m
    while(m--){
        int u,v;
        cin >> u >> v; u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    AP();
    int cnt = 0;
    FOR(i,0,mxN){
        if(ap[i])
            cnt++;
    }
    cout<<cnt<<'\n';
}  
