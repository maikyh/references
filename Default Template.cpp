#include <bits/stdc++.h>
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define ll long long
#define ld long double
#define clr(v, d) memset(v, d, sizeof(v))
#define mp make_pair
#define vt vector
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define erase_duplicates(x) x.erase(unique(all(x)),x.end());
#define fi first
#define se second
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

template<class T> int lwb(vt<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
template<class T> int upb(vt<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }
 
template <typename T> std::istream& operator>>(std::istream& input, std::vector<T>& data){ for(T& x : data)input >> x;return input;}
template <typename T> std::ostream& operator<<(std::ostream& stream, const vector<T>& vec){ for(size_t i = 0; i < vec.size(); i++){stream << vec[i];if(i != vec.size() - 1)stream << ' ';}; return stream; }

const int dx[8]  = {1,1,0,-1,-1,-1, 0, 1};
const int dy[8]  = {0,1,1, 1, 0,-1,-1,-1};
const int d4x[4]  = {1,-1, 0, 0};
const int d4y[4]  = {0, 0, 1,-1};

const double PI = acos(-1.0);
const int INF = INT_MAX;
const int INFNEG = INT_MIN;
const ll int MOD = 1e9+7;
const double EP = 1E-10;
 
// bool valid(int r, int c){
//     return r>=0 && c>=0 && r<n && c<m;
// }

struct edge { // aristas
    int u, v, weight;
};

bool cmp(edge a, edge b) {
    return a.weight < b.weight;
}

bool myCompare(pair <int, int> p1, pair<int, int> p2){
    return p1.fi<p2.fi;
}

void solve(){

}     

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1, i = 0;
    // cin >> t;
    while (t--){
        // cout<<"Case #"<<++i<<": ";
        solve();
    }
} 
/*
*/
