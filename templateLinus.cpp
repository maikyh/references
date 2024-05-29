/*
USER: Linus Martinez [linusma3]
TASK: 
LANG: C++
*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <map>
#define ll long long
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a) for(auto i : a)  
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define ull unsigned long long
#define ld long double
#define clr(v, d) memset(v, d, sizeof(v))
#define vt vector
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define erase_duplicates(x) x.erase(unique(all(x)),x.end());
#define fi first
#define se second
#define mem(a,h)    memset(a,(h),sizeof(a))
#define deb(x) cout << #x << ": "<< x << '\n';
using namespace std;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<double,double>;

using vi = vt<int>;
using vb = vt<bool>;
using vl = vt<ll>;
using vd = vt<double>;
using vs = vt<string>;
using vpi = vt<pi>;
using vpl = vt<pl>;
using vpd = vt<pd>;

#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007

const vpi DIR = {{1,0},{0,1},{-1,0},{0,-1}};
const vpi DIR8 = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
const double PI = acos(-1.0);
const  int tam = 100010;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return b * (a / gcd(a, b));
}
//obtener el numero de bits de un numero

ll numBits(ll n){
    
    if(n==0){
        return n;
    }
    if(n>0){
        return 1+numBits(n&n-1);
    }

}

//suma ponderada desde 0 hasta n de la diferencia de bits entre cada numero
ll ans(ll n){
    if(n==0){
        return 0;
    }
    //????????????????????????????????????????????
    return n+ans(n/2);
}


/*
void solve2(vector<int>&v,vector<int>&sub,vector<vector<int>>&res,int index,int target){
    if(target==0){
        res.pb(sub);    
    }


    for(int i = index;i<v.size();i++){
        
        sub.pb(v[i]);

        solve2(v,sub,res,i+1,target-v[i]);
        
        sub.pop_back();

    }


}

vector<vector<int>>subset(vector<int>&v,int &target){
    vector<int>sub;
    vector<vector<int>>res;
    solve2(v,sub,res,0,target);
    return res;
}

*/
/*
struct node{
    ll data;
    node *left;
    node *right;

    node(ll val){
        data = val;
        left=NULL;
        right=NULL;
    }    

};*/
/*
bool check(vector<vector<int>>&grid,int row,int col){
    for(int i = 0;i<grid.size();i++){
        if(grid[row][i]==1||grid[i][col]==1){
            return false;
        }
    }

    for(int i=row,j=col;i>-1 && j>-1;i--,j--){
        if(grid[i][j]==1){
            return false;
        }

    }
    for(int i=row,j=col;i>-1 && j<grid.size();i--,j++){
        if(grid[i][j]==1){
            return false;
        }

    }

    return true;



}
bool ans(vector<vector<int>>&grid,int row,int queens){
    if(queens>=grid.size()){
        FOR(i,0,grid.size()){
            FOR(j,0,grid.size()){
                cout << grid[i][j]<<" ";
            }
            cout <<"\n";
        }
        return true;
    }

    for(int j = 0;j<grid.size();j++){
        if(check(grid,row,j)){
            grid[row][j]=1;
            if(ans(grid,row+1,queens+1)){
                return true;
            }
            grid[row][j]=0;
        }
    }
    return false;

}

*/





/*
void update(int b,int e,int node,int pos,char val){
    if(b==e){
        FOR(i,0,27){
            tree[node][i]=0;
        }
        tree[node][val-'a']=1;
        return;
    }
    int m = (b+e)/2;
    int l = 2*node+1;
    int r = l+1;

    if(pos<=m){
        update(b,m,l,pos,val);
    }else{  
        update(m+1,e,r,pos,val);
    }

    FOR(i,0,27){
        if(tree[l][i]==1 || tree[r][i]==1){
            tree[node][i]=1;
        }else{
            tree[node][i]=0;
        }
    }
}

void query(int b,int e,int node,int i,int j,vi &v){
    if(b>=i && e<=j){
        FOR(i,0,27){
            if(tree[node][i]==1){
                v[i]=1;
            }
        }
        return;
    }

    int m = (b+e)/2;
    int l = 2*node+1;
    int r = l+1;

    if(j<=m){
        query(b,m,l,i,j,v);
    }else if(i>m){
        query(m+1,e,r,i,j,v);
    }else{
        query(b,m,l,i,j,v);
        query(m+1,e,r,i,j,v);
    }
}

void init(int b,int e,int node,string s){
    if(b==e){
        tree[node]=0;
        return;
    }
    int m = (b+e)/2;
    int l = 2*node+1;
    int r = l+1;
    init(b,m,l,s);
    init(m+1,e,r,s);
    FOR(i,0,27){
        if(tree[l][i]==1 || tree[r][i]==1){
            tree[node][i]=1;
        }else{
            tree[node][i]=0;
        }
    }

}
*/
/*
void join(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        parent[a]=b;
        al[b]=max(al[a]+1,al[b]);

    }
}*/
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
//https://codeforces.com/contest/1791/problem/F
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
 
        // Multiply 'a' with 2
        a = (a * 2) % mod;
 
        // Divide b by 2
        b /= 2;
    }
 
    // Return result
    return res % mod;
}



vector<int> getDivisors(int n){ //divisores de un numero
    vi v;
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i==0){
            int b = n/i;
            if(b!=i){
                v.pb(b);
            }
            v.pb(i);
        }
    }
    return v;
}

vector<int> numDivisors(int n){ // numero de divisores de un numero o varios nlogn
    vi numDivs(n+1,0);
    for (int i = 1; i<=n; i++)
    {
        for (int j = i; j <=n; j+=i)
        {
            numDivs[j]++;
        }
    }
    return numDivs;

}

vector<int> getPrimes(int n){
    vi v;
    vb prime(n+1,true);
    prime[0]=prime[1]=false;
    for (int i = 4; i <=n; i+=2)
    {
        prime[i]=false;
    }
    v.pb(2);
    for (int i = 3; i<= n; i+=2)
    {
        if(prime[i]){
            v.pb(i);
            if((long long)i*i<=n){ //evitamos desbordar
                for (int j = i*i; j <= n; j+=2*i) // empezamos de impar*impar el cual da impar entonces si sumamos
                {                                 //solamente i pues seria impar+impar=par entonces si sumamos
                    prime[j]=false;                 // par+impar = impar y marcamos como false
                } 

            }
        }
    }
    return v;
}
bool isPrime(int n){
    if(n==1){
        return false;
    }
    FOR(i,2,n+1){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

bool isPrimeWithSieve(int n,vi &primes){
    if(n==1){
        return false;
    }
    for(auto x:primes){
        if(x*x>n){
            break;
        }
        if(n%x==0){
            return false;
        }
    }
    return true;
}

int al[100050];
/*
int find(int n){

    if(parent[n]==0){
        return n;
    }
    return parent[n]=find(parent[n]);

}
void join1(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(al[a]>al[b]){
            swap(a,b);
        }
        parent[a]=b;
        al[b]=max(al[a]+1,al[b]);

    }
}

*/
/*
int time2 = 0;

void dfs(int curr,int parent,vector<vi>&adj,vi &discovery,vi &low,vi &articulation){
    int children = 0;
    discovery[curr]=low[curr]=++time2;

    for(auto vecino :adj[curr]){
        if(parent==vecino){ // we don't want to go back through the same path.
                            // if we go back is because we found another way back
            continue;
        }
        if(!discovery[vecino]){ // if V has not been discovered before
            children++;
            dfs(vecino,curr,adj,discovery,low,articulation); // recursive DFS call

            if(parent != -1 && discovery[curr]<=low[vecino]){  // condition #1
                articulation[curr]=1;
            }

            low[curr]=min(low[curr],low[vecino]);// low[v] might be an ancestor of u
        }else{
            low[curr]=min(low[curr],discovery[vecino]);// finds the ancestor with the least discovery time
        }
    }
    if(parent==-1 && children>1){// condition #2  //If curr is the root of the DFS tree and it has at least 2 children 
                                                //subgraphs disconnected from each other, then U is an articulation point.
        articulation[curr]=1;
    }
}
*/
ll inverse(ll a){

    ll res = 1, pw = MOD - 2;

    while (pw)

    {

    if (pw & 1)

    res = (res * a) % MOD;

    a = (a * a) % MOD;

    pw >>= 1;

}

return res;

}
ll qexp(ll a, ll b, ll m) {

ll res = 1;

    while (b) {

        if (b & 1) res = res * a % m;

        a = a * a % m;

        b >>= 1;

    }

    return res;

}
//int usersgroup[1000050];
int group[200050];
int parent[200050];
void giveMeBinary(int x){
    if(!x){
        return;
    }
    giveMeBinary(x>>1);
    cout << (x&1);
}
// es potencia de 2??
bool isPot(int x){
    //100000
//  & 011111
    //000000
    return (x&(x-1))==0;

}

/*
struct nodo{
    //int finales;
    nodo *hijos[26];
    bool final;

    //constructor
    nodo(){
        final = false;
        FOR(i,0,26){
            hijos[i]=NULL;
        }
    }

};

    


/*
nodo *nuevoNodo(){
    nodo *nuevo = new Nodo();
    nuevo->final = false;
    FOR(i,0,26){
        nuevo->hijos[i] = NULL;
    }
    return nuevo;
}*/
/*
nodo *raiz;




void insertar(string s,nodo *nd){
    nodo *aux = raiz;
    FOR(i,0,s.length()){
        int ch = s[i]-'a';
        if(aux->hijos[ch]==NULL)
            aux->hijos[ch] = new nodo();
        aux = hijos[ch];
    }
    aux->final = true;  
}
void eliminar(){
    
}
*/

/*

bool dfs(ll src,vector<vector<pair<ll,ll>>>&adj,vb &vis){
   // cout << src << "node\n";

    if(src==vis.size()-1){

        return true;
    }
    vis[src]=1;
    bool reach = false;
    for(auto x:adj[src]){
        if(reach){
            break;
        }
        if(!vis[x.fi]){
            reach = dfs(x.fi,adj,vis);
        }

    }
    return reach;
}
*/


/*

 int n,m;cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n+1);
    vb vis(n+1,false);
    FOR(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    if(!dfs(1,adj,vis)){
        cout << -1 << "\n";
    }else{
        //cout << "adada\n";
        vi ans(n+1,-1);
        dijkstra(1,adj,ans);
        int curr = n;
        vi xx;
        xx.pb(curr);
        while(ans[curr]!=-1){
            xx.pb(ans[curr]);
            curr = ans[curr];
        }

        reverse(all(xx));
        for(auto z : xx){
            cout << z << " ";
        }

    }

void dijkstra(ll src,vector<vector<pair<ll,ll>>>&adj,vi &ans){
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    vector<ll>dist(adj.size(),1e17);
    vb vis(adj.size(),false);

    while(!pq.empty()){
        ll u = pq.top().se;
        pq.pop();
        if(vis[u]){
            continue;
        }

        vis[u]=true;
         // cout << u << "padre\n";
        for(auto x:adj[u]){
            ll v = x.fi;
            ll w = x.se;
             // cout << v << "hijos \n";
            if(dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});

                ans[v]=u;
            }
        }
    }
}
*/
/*
void setBitsInArray(ll n, vector<int> &bits) {
    int position = 1;
    while (n > 0) {
        if (n & 1) {
            bits[position]++; // Increment the corresponding bit position in the array
        }
        position++;
        n >>= 1; // Right shift the number to check the next bit
    }
}

void removeBitsInArray(ll n, vector<int> &bits) {
    int position = 1;
    while (n >0) {
        if (n & 1) {
            bits[position]--;
            if(bits[position]<0){
                bits[position] = 0;
            }
        }
        position++;
        n >>= 1; 
    }
}
*/



void solve() {


    //ifstream fin("diamond.in"); 
    //ofstream fout("diamond.out");
   // mem(parent,0);  //DSU
    //complemento a 1   -   ~
    //complemento a 2   -   +1
    /*
    int x = 3;
    cout << (x<<3) << "\n";
    cout << (x>>1) << "\n";
*/
    /*
    giveMeBinary(x);
    cout << "\n";
    int y = 12;
    giveMeBinary(y);
    cout << "\n";
    giveMeBinary(x&y);

    if((4&1)){
        cout << "YES\n";
    }else{
        cout << "NO\n";

    }*/
    /*
    if(isPot(x)){
        cout << "YES\n";
    }else{
        cout << "NO\n";        
    }*//*
    ll n;cin>>n;
    vl v(n);

    FOR(i,0,n){
        cin>>v[i];
    }

*/
    

    

}



int main() {
    ios::sync_with_stdio(0); // cin && cout becomes faster
    cin.tie(0);//reduce runtime 
    cout.tie(0);
  // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t = 1, i = 0;
    while (t--){
       solve();
    }
 
    return 0;
}









//THE WORLD IS YOURS
//Un Dia Comence A Correr...
