//total number of subarrays having a given XOR k
//if TLE, use vector instead of map
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int solve(vector<int> &A, int B) {
    unordered_map<int,int>visited;
    int cpx = 0;
    long long c=0;
    for(int i=0;i<A.size();i++){
        cpx^=A[i];
        if(cpx==B) c++;
        int h = cpx^B;
        if(visited.find(h)!=visited.end()){
            c=c+visited[h];
        }
        visited[cpx]++;
    }
    return c;
}
};


int main()
{   vector<int> A{ 4,2,2,6,4 };
    Solution obj;
    int totalCount= obj.solve(A,6);
    cout<<"The total number of subarrays having a given XOR k is "<<totalCount<<endl;
}


//total number of subsubsequences having a given XOR k mod 1e9+7
void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(1 << 6, 0));
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        for(int mask = 0; mask < (1 << 6); ++mask) {
            dp[i][mask] += dp[i - 1][mask];
            if(dp[i][mask] >= MOD) dp[i][mask] -= MOD;
            dp[i][mask & a[i]] += dp[i - 1][mask];
            if(dp[i][mask & a[i]] >= MOD) dp[i][mask & a[i]] -= MOD;
        }
        dp[i][a[i]] = (dp[i][a[i]] + 1) % MOD;
    }
    int ans = 0;
    for(int mask = 0; mask < (1 << 6); ++mask) {
        if(__builtin_popcount(mask) == x) {
            ans = (ans + dp[n][mask]) % MOD;
        }
    }
    cout << ans << "\n";
}    
