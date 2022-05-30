const int mxN = 101;
int vis[100005], dis[100005];
vpi adj[100005];
int vis2[100005], dis2[100005];
vpi adj2[100005];
void solve(){
    int n,m; 
    while(cin >> n >> m){
        clr(vis,0);
        clr(dis,0);
        clr(adj,0);
        clr(vis2,0);
        clr(dis2,0);
        clr(adj2,0);
        FOR(i,0,m){
            int u,v,num,w; 
            cin >> u >> v >> num >> w;
            if(num == 0)
                adj[u].pb({v,w});
            else
                adj2[u].pb({v,w});
        }

        //dijkstra 1
        FOR(i,2,n+1) dis[i]=INF;
        priority_queue<pi,vpi,greater<pi>> q;
        q.push({0,1});
        while(!q.empty()){
            int u = q.top().se; q.pop();
            if (vis[u]) continue;
            vis[u]=1;
            for (auto i : adj[u]){
                int v = i.fi;
                int w = i.se;
                if (dis[v]>dis[u]+w){
                    dis[v] = dis[u]+w;
                    q.push({dis[v],v});
                }
            }
        }
        // FOR(i,1,n+1) cout<<(dis[i])<<" ";

        // cout<<'\n';

        //dijkstra 2
        FOR(i,2,n+1) dis2[i]=INF;
        priority_queue<pi,vpi,greater<pi>> q2;
        q2.push({0,1});
        while(!q2.empty()){
            int u = q2.top().se; q2.pop();
            if (vis2[u]) continue;
            vis2[u]=1;
            for (auto i : adj2[u]){
                int v = i.fi;
                int w = i.se;
                if (dis2[v]>dis2[u]+w){
                    dis2[v] = dis2[u]+w;
                    q2.push({dis2[v],v});
                }
            }
        }
        // FOR(i,1,n+1) cout<<(dis2[i])<<" ";
            cout<<min(dis[n],dis2[n])<<'\n';
    }
}     
