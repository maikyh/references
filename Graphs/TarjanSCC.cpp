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


const int mxN = 100050;
ll timeDisc = 0;
ll n,m;

stack<int>st;
vt<vector<pair<ll,ll>>>components;

void SCC(int node,vt<vl> &adj,vl &disc,vl &low, vb &inSt,vl &v){
    disc[node] = low[node] = ++timeDisc;
    st.push(node);
    inSt[node] = true;

    for(auto x:adj[node]){
        if(!disc[x]){
            SCC(x,adj,disc,low,inSt,v);
            low[node] = min(low[node],low[x]);
        }else if(inSt[x]){
            low[node] = min(low[node],disc[x]);
        }
    }

    if(low[node]==disc[node]){
        vt<pair<ll,ll>> component;
        int curr;
        while(st.top()!=node){
            curr = st.top();
            component.pb({v[curr],curr});
            inSt[curr]=false;
            st.pop();
        }
        curr = st.top();
        component.pb({v[curr],curr});
        st.pop();
        inSt[curr]=false;
        components.pb(component);
    }
}

void solve(){
    cin>>n;
    vl v(n+1);

    FOR(i,1,n+1){
        cin>>v[i];
    }

    vt<vl>adj(n+1);
    vl disc(n+1);
    vl low(n+1);
    vb inSt(n+1,false);
    cin>>m;
    FOR(i,0,m){
        ll u,v;cin>>u>>v;
        adj[u].pb(v);
    }

    FOR(i,1,n+1){
        if(!disc[i]){
            SCC(i,adj,disc,low,inSt,v);
        }
    }
    //see SCC components
    // cout << endl;
    ll ans = 0;
    ll ways = 1;
    for(auto x:components){
        //cost of node 
        sort(all(x));
        ll minn = x[0].fi;
        ll currways = 1;

        ans+=minn;

        FOR(i,1,x.size()){
            if(minn==x[i].fi){
                currways++;
            }
        }
        ways = ways*currways;
        ways+=MOD;
        ways = ways%MOD;    
        // cout << endl;
    }

    cout << ans << " " << ways << "\n";


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
