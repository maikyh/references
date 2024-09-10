
int block;
struct a{
    int l;
    int r;
    int id;
    int val;
    a(int l,int r,int id,int val){
        this->l = l;
        this->r = r;
        this->id = id;
        this->val = val;
    }
};

bool myComparator(a elema, a elemb){
    if(elema.l/block != elemb.l/block){
        return elema.l/block < elemb.l/block;
    }
    return elema.r<elemb.r;

}

void solve(){
    int n;cin>>n;
    vi v(n);
    FOR(i,0,n){
        cin>>v[i];
    }   
    block = sqrt(n);
    int q;cin>>q;
    vector<a>queries;
    FOR(i,0,q){
        int l,r,val;cin>>l>>r>>val;
        a curr(l,r,i,val);
        queries.pb(curr);
    }
    sort(queries.begin(),queries.end(),myComparator);
    vb ans(100050);
    vi curr(10,0);
    int currL = 0;
    int currR = 0;
    FOR(i,0,q){
        int l = queries[i].l;
        int r = queries[i].r;
       

        while(currL<l){
            curr[v[currL]]--;
            currL++;
        }

        while(currR<=r){
            curr[v[currR]]++;
            currR++;
        }

        while(currR>r+1){
            currR--;
            curr[v[currR]]--;
        }

        while(currL>l){
            currL--;
            curr[v[currL]]++;
        }

        ans[queries[i].id]=curr[queries[i].val];
    }
    FOR(i,0,q){
        if(ans[i]){
            cout << "yes\n";
        }else{
            cout << "no\n";

        }
    }
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
