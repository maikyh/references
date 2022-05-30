#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back
#define MOD 1000000007
using namespace __gnu_pbds;
typedef tree<
ll,
null_type,
less_equal<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// less_equal, hence lower_bound becomes upper_bound vice versa

const int MX = 100000 + 10;
ordered_set segtree[4*MX];
ll arr[MX];

void build(ll node, ll low, ll high){

    if(low == high){
        segtree[node].insert(arr[low]);
        return ;
    }

    ll mid = (low+high)/2;

    build(2*node, low,mid);
    build(2*node+1,mid+1,high);

    segtree[node] = segtree[2*node];

    for(auto i:segtree[2*node+1]) segtree[node].insert(i);

}

void update(ll node, ll low, ll high, ll pos, ll x){

    if( low == high){
        segtree[node].erase(segtree[node].upper_bound(arr[pos]));
        segtree[node].insert(x);
        return;
    }

    segtree[node].erase(segtree[node].upper_bound(arr[pos]));
    segtree[node].insert(x);

    ll mid = (low+high)/2;
    if(pos<=mid)
        update(2*node, low, mid, pos, x);
    else
        update(2*node+1,mid+1, high,pos,x);

}

ll query(ll node, ll low, ll high, ll l , ll r, ll x){

    if(r<l) return 0;

    if(low == l && high == r){
        ll k = segtree[node].order_of_key(x);
        return segtree[node].size() - k;
    }

    ll mid = (low+high)/2;

    return (query(2*node,low,mid,l,min(mid,r),x) +
     query(2*node+1,mid+1,high,max(l,mid+1),r,x));

}


int main()
{   
    FIO;

    ll n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>arr[i];

    build(1,1,n);
        
     
    while(q--){
        ll t;
        cin>>t;
 
        if(t == 1){
            ll pos, h;
            cin>>pos>>h;

            update(1,1,n,pos,h);
            arr[pos] = h;
        }
        else{
            ll l,r,c;
            cin>>c>>l>>r;
            
            cout<<query(1,1,n,l,r,c+1)<<"\n";

        }
 
    }

    return 0;
}
