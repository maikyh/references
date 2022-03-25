int mod(int a, int b, int c){ // pow(a,b) % c
    int res=1;
    while(b){
        if(b&1) res=(res*a)%c;
        b>>=1;
        a=(a*a)%c;
    }
    return res;
}
    
ll power(ll a, ll b){ // a raised to power b
  ll res=1;
  while(b){
    if(b&1) res=(res*a)%MOD;
    b>>=1;
    a=(a*a)%MOD;
  }
  return res;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll ceil_div(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}

bool checkPrime(int number){
    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;
}

ll mult(vector<ll> &v){
    int n=v.size();
    sort(v.begin(),v.end());
    ll sm=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=i*v[i]-sm;
        sm+=v[i];
    }
    return ans;
}
ll sum(vpl &vec){
    vector<ll> x,y;
    for(auto p : vec){
        x.pb(p.fi);
        y.pb(p.se);
    }
    return mult(x) + mult(y);
}
