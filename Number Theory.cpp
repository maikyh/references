ll mod(ll a, ll b, ll c){ // pow(a,b) % c
    ll res=1;
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

bool isprime(ll n) { 
    if (n <= 1) return false; 
	if (n <= 3) return true; 
	  
	if (n % 2 == 0 || n % 3 == 0) return false; 
	  
	for (ll i = 5; i * i <= n; i += 6) 
		if (n % i == 0 || n % (i+2) == 0) 
		    return false; 
	  
	return true; 
} 

//Iterar sobre Matriz en O(n);
///////////////////START HERE////////////////////////
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
/////////////////END HERE//////////////////////////////

//factmod
ll mod_factorial(ll n, ll p) {
    ll factorial = 1;
    while (n > 0) {
        long long k = n / p;
        ll b = n % p;
        if (k % 2 == 1) {
            factorial = 1LL * factorial * (p - 1) % p;
        }
        for (ll i = 1; i <= b; i++) {
            factorial = 1LL * factorial * i % p;
        }
        n = k;
    }
    return factorial;
}
//factpow
ll factorial_power(ll n, ll p) {
    ll power = 0;
    while (n > 0) {
        n /= p;
        power += n;
    }
    return power;
}

//Path of a Binary Tree with len of the path and change of direction
///////////////////START HERE////////////////////////
ll fact[mxN + 5];
ll factpow[mxN + 5];
ll sqr(ll a){
    return (a * a) % MOD;
}
ll modpow(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a % MOD;
    ll tmp = sqr(modpow(a , b >> 1));
    if(b&1) tmp = (tmp * a) % MOD;
    return tmp;
}

void init(){
    fact[0] = fact[1] = 1;
    for(int i = 2;i <= mxN; ++i){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    for(int i = 0;i <= mxN; ++i){
        factpow[i] = modpow(fact[i], MOD - 2);
    }
}

ll C(int a, int b){
    return (((fact[a] * factpow[b]) % MOD) * factpow[a - b]) % MOD;
}

//ll a,b;
//cin >> a >> b;
//ll ans = (2 * C(a-1, b))% MOD;
/////////////////END HERE//////////////////////////////

vector<int> get_all_modular_inverses(int p) {
    vector<int> inverse_factorials(p);
    inverse_factorials[p - 1] = p - 1; // -1 mod p = p - 1
    for (int k = p - 2; k > 0; k--) {
        inverse_factorials[k] = 1LL * inverse_factorials[k + 1] * (k + 1) % p;
    }

    vector<int> inverses(p);
    int factorial = 1;
    for (int k = 1; k < p; k++) {
        inverses[k] = 1LL * factorial * inverse_factorials[k] % p;
        factorial = 1LL * factorial * k % p;
    }
    return inverses;
}

//Criba de Eratostenes
bool prime[15000105]; 
void sieve(int n) { 
    for (ll i = 0; i <= n; i++) prime[i] = 1;
	    for (ll p = 2; p * p <= n; p++) { 
		    if (prime[p] == true) { 
		        for (ll i = p * p; i <= n; i += p) 
			    prime[i] = false; 
		    } 
	    } 
    prime[1] = prime[0] = 0;
}

//Divisores de un numero n
vector<ll> getdivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divs.push_back(i);
        divs.push_back(n / i);
      }
    }
    erase_duplicates(divs);
    // sort(all(divs));
    return divs;
}
