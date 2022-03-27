struct lca {
  int n, root;
  vector<int> parents, euler, f, depths;
  int* depth_a;
  segtree<min_t> st;
  vector<vector<int> > edges;

  void init(int size, int r) {
    n = size;
    root = r;
    edges = vector<vector<int> >(n);
    parents = vector<int>(n);
    f = vector<int>(n, -1);
  }

  void edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  /* when graph is complete */
  void init_lca() {
    set_parents(-1, root);
    euler_tour(root, 0);
    depth_a = new int[2 * n];
    for (int i = 0; i < 2 * n - 1; i++) {
      depth_a[i] = depths[i];
      if (f[euler[i]] == -1) f[euler[i]] = i;
    }
    st.init(2 * n - 1, depth_a);
  }

  void set_parents(int parent, int node) {
    parents[node] = parent;
    for (int i: edges[node]) 
      if (i != parent) set_parents(node, i);
  }

  void euler_tour(int node, int d) {
    euler.push_back(node);
    depths.push_back(d);
    for (int i: edges[node]) 
      if (i != parents[node]) {
        euler_tour(i, d + 1);
        euler.push_back(node);
        depths.push_back(d);
      }
  }

  int q(int a, int b) {
    if (a == b) return a;
    int c = min(f[a], f[b]), d = max(f[a], f[b]);
    return euler[(st.query(c, d)).ind];
  }
};
