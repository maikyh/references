/*
Topic: Difference Array query
Here, we need to perform difference array logic twice.
First we need to have the difference array from our query x[] and y[]
Then we need to multiply val[] values as they are the values increased in query
Finally, a linear scan adding with main array elements will do the job done :)
*/

#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define ll long long
const int mxN = 1e5+1;
ll arr[mxN], l[mxN], r[mxN], x[mxN], y[mxN], dif[mxN], qur[mxN], val[mxN];
void solve(){
    int n,m,q;
    cin >> n >> m >> q;

    FOR(i,1,n+1)
        cin >> arr[i];
    
    FOR(i,1,m+1)
        cin >> l[i] >> r[i] >> val[i];

    FOR(i,1,q+1){
        cin >> x[i] >> y[i];
        dif[x[i]]++;
        dif[y[i]+1]--;
    }

    FOR(i,1,m+1){
        dif[i] += dif[i-1];
        // deb(i);
        // deb(dif[i]);
    }

    FOR(i,1,m+1){
        qur[l[i]] += dif[i] * val[i];
        qur[r[i]+1] -= dif[i] * val[i];
    }

    FOR(i,1,n+1){
        qur[i] += qur[i-1];
        arr[i] += qur[i];
    }

    FOR(i,1,n+1)
        cout<< arr[i] << " ";
    cout<<'\n';
}     
