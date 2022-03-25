class Kosaraju{
  private:
    int V;
    vector<int>* adj;
  
  public:
    Kosaraju(int V, vector<int> adj[]){
        this->V=V;
        this->adj=adj;
    }
    
    void dfs(int node, vector<bool> &vis, vector<int> &temp){
        vis[node]=true;
        temp.push_back(node);
        for(auto nei: adj[node]){
            if(vis[nei]==false){
                dfs(nei,vis,temp);
            }
        }
    }
    
    void topoSort(int node, stack<int> &s, vector<bool> &vis){
        vis[node]=true;
        for(auto nei : adj[node]){
            if(vis[nei] == false){
                topoSort(nei, s, vis);
            }
        }
        s.push(node);
    }
    
    void Transpose(int V){
        vector<int> adjR[V];
        for(int i=0;i<V;i++){
            for(auto nei: adj[i]){
                adjR[nei].push_back(i);
            }
        }
        for(int i=0;i<V;i++){
            adj[i]=adjR[i];
        }
    }
    
    vector<vector<int>> SCC(){
        vector<vector<int>> res;
        stack<int> s;
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                topoSort(i,s,vis);
            }
        }
        
        Transpose(V);
        
        for(int i=0;i<V;i++){
            vis[i]=false;
        }
        
        while(s.empty()==false){
            vector<int> temp;
            int v=s.top();
            s.pop();
            if(vis[v]==false){
                dfs(v,vis,temp);
                sort(temp.begin(),temp.end());
                res.push_back(temp);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
}; 
