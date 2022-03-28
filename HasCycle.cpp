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
