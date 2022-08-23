// br = bridges, p = parent

    const int mxN = 710;
    vi adj[mxN];
    vector<pair<int, int>> br;
    vector<int> low,disc;
    int Time = 0;

    int dfsBR(int u, int p) {
      low[u] = disc[u] = ++Time;
      for (int& v : adj[u]) {
        if (v == p) continue; // we don't want to go back through the same path.
                              // if we go back is because we found another way back
        if (!disc[v]) { // if V has not been discovered before
          dfsBR(v, u);  // recursive DFS call
          if (disc[u] < low[v]) // condition to find a bridge
            br.push_back({u, v});
          low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
        } else // if v was already discovered means that we found an ancestor
          low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
      }
    }

    void BR() {
      low = disc = vector<int>(mxN);
      Time = 0;
      for (int u = 0; u < mxN; u++)
        if (!disc[u])
          dfsBR(u, u);
    }
    
    void solve(){
        clr(adj,0);
        br.clear();
        low.clear();
        disc.clear();
        int n,m;
        cin >> n >> m;
        while(m--){
            int u,v;
            cin >> u >> v; u--; v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        BR();
        
        for(auto bridge : br)
            cout<<bridge.fi+1<<" "<<bridge.se+1<<'\n';
    }  
