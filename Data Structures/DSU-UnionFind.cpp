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


int parent[mxN];

//DSU Altura/rango optimizacion
//int altura[100000];

//DSU Tamano optimizacion
int size[mxN];
// if path compression and heigth/range or size optimization are used then
// we get a O(4)--->O(1) --->> O(funcion inverse ackerman) para n ≤ 10^600


int find(int n){
    if(parent[n]==n){
        return n;
    }else{
        //path compression
        return parent[n] = find(parent[n]);
    }
}

void join(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(size[a]<size[b]){
            parent[a] = b;
            size[b]+=size[a];
        }else{
            parent[b] = a;
            size[a]+=size[b];   
        }
    }


    //optimizacion altura/rango DSU
    // if(a!=b){
    //     if(altura[a]<altura[b]){
    //         parent[a] = b;
    //     }else if(altura[a]>altura[b]){
    //         parent[b] = a;
    //     }else{
    //         parent[b] = a;
    //         altura[a]++;
    //     }
    // }


}


void solve(){
 

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
