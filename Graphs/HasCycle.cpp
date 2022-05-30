bool hasCycle(int me, vector<int> &state, vector<vector<int>> &graph){
    if(state[me] == 1) return true;
    if(state[me] == 2) return false;
    state[me] = 1;

    bool sol = false;
    for(auto child:graph[me]){
        sol = sol || hasCycle(child, state, graph);
    }
    state[me] = 2;
    return sol;
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y; x--; y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    vector<int> state(n, 0);
    bool ans = false;
    for(int i=0; i<n; i++){
        if(state[i] == 0) ans = ans || hasCycle(i, state, graph);
    }
    cout << (ans?"YES":"NO") << endl;
}
