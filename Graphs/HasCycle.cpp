bool hasCycleUtil(int me, vector<int> &state, vector<vector<int>> &graph){
    if(state[me] == 1) return true;
    if(state[me] == 2) return false;
    state[me] = 1;

    bool sol = false;
    for(auto child:graph[me]){
        sol = sol || hasCycleUtil(child, state, graph);
    }
    state[me] = 2;
    return sol;
}   
bool hasCycle(vector<vector<int>>& graph, int n){
    vector<int> state(n, 0);
    bool ans = false;
    for(int i=0; i<n; i++){
        if(state[i] == 0) ans = ans || hasCycleUtil(i, state, graph);
    }
    return ans;
}
void solve(){
    int n,m;
    cin >> n >> m;
    vt<vi> adj(n);
    while(m--){
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
    }
    cout<<(hasCycle(adj,n) ? "YES" : "NO")<<'\n';
}  
