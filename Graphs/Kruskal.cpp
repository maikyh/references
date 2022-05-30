struct Edge {
    int from, to, w;
    Edge() {}
    Edge(int a, int b, int c) : from(a), to(b), w(c) { }
    bool operator <(Edge const& e) const {
        return w < e.w;
    }
};

struct dsu{
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
} dsu;

vector<Edge> v;
vector<Edge> tree;

int kruskal(int n, int m) { // O(ELogE + ELogV)
    sort(v.begin(), v.end());

    int mst_w = 0;
    dsu.init(n);

    FOR(i, 0, m) {
        Edge e = v[i];

        if (! dsu.same(e.from, e.to)) {
            mst_w += e.w;
            dsu.unify(e.from, e.to);
            tree.pb(Edge(e.from, e.to, e.w));
        }
    }

    return mst_w;
}

int main() {
    int n, m;
    int a, b, c;
    cin >> n >> m;
    FOR(i, 0, m) {
        cin >> a >> b >> c;
        v.pb(Edge(a, b, c));
    }

    cout << kruskal(n, m) << endl;

    return 0;
}
