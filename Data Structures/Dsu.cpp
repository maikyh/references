struct unionFind {
    static const int MAXN=2 * 1e5+1;
    int P[MAXN], R[MAXN];
    int _size;
    void init(int n){ // init
        static int i;
        for(int i = 0; i <= n; i++)
            P[i] = i, R[i] = 1;
        _size = n;
    }

    void make_set(int u) {
        P[u] = u;
        R[u] = 1;
    }

    int get(int x){ // find o root   get
        if (P[x] != x) P[x] = get(P[x]);
        return P[x];
    }

    int unify(int x, int y) { //joint o unite   unify
        x = get(x), y = get(y);
        if(x != y) {
            _size--;
            if(R[x] > R[y]){
                R[x] += R[y], P[y] = x;
                // cout<<(R[x])<<'\n';
            }
            else{
                R[y] += R[x], P[x] = y;
                // cout<<(R[y])<<'\n';
            }
            return 1;
        }
        // cout<<(R[x])<<'\n';
        return 0;
    }

    bool same(int a,int b){
        return get(a)==get(b);
    }

    int getSize() {
        return _size;
    }
};
