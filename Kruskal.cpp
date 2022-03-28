struct Edge {
    int from, to, w;
    Edge() {}
    Edge(int a, int b, int c) : from(a), to(b), w(c) { }
    bool operator <(Edge const& e) const {
        return w < e.w;
    }
};

struct UnionFind {
    int numSets = 0;
    int setSize[MAXN];
    int parent[MAXN];
    int rank[MAXN];

    UnionFind(int n) {
        numSets = n;
        FOR(i, 0, n)    parent[i] = i;
    }

    void make_set(int i) {
        parent[i] = i;
        rank[i] = 0;
    }

    int find_set(int i) {
        if (i != parent[i])
            parent[i] = find_set(parent[i]);
        return parent[i];
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = find_set(i), y = find_set(j);

            if (rank[x] > rank[y]) {
                parent[y] = x;
                setSize[x] += setSize[y];
            }
            else {
                parent[x] = y;
                setSize[y] += setSize[x];

                if (rank[x] == rank[y])     rank[y]++;
            }
        }
    }

    bool isSameSet(int i, int j) {
        return find_set(i) == find_set(j);
    }
};

vector<Edge> v;
vector<Edge> tree;

int kruskal(int n, int m) { // O(ELogE + ELogV)
    sort(v.begin(), v.end());

    int mst_w = 0;
    UnionFind UF(n);

    FOR(i, 0, m) {
        Edge e = v[i];

        if (! UF.isSameSet(e.from, e.to)) {
            mst_w += e.w;
            UF.unionSet(e.from, e.to);
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
