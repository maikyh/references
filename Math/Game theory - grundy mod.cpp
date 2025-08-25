
int grundy_mod_for_subtraction_game(vector<int> moves) {
    sort(moves.begin(), moves.end());
    moves.erase(unique(moves.begin(), moves.end()), moves.end());
    // must start at 1 and be consecutive
    if (moves.empty() || moves.front() != 1) return 0;
    for (int i = 0; i < (int)moves.size(); ++i) {
        if (moves[i] != i + 1) return 0;
    }
    return (int)moves.size() + 1; // K+1
}

void solve(){
    vi moves;
    FOR(i,0,1e9+1){

    }
    vi moves = {1,2,3};

    int grundy = grundy_mod_for_subtraction_game(moves);


    int n; cin >> n;
    int ans = 0;
    FOR(i,0,n){
        int x; cin >> x;
        ans ^= x % grundy;
    }

    if(ans == 0) cout<<"second"<<ENDL;
    else cout<<"first"<<ENDL;

}
