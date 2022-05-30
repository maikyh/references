ull multMod(ull a, ull b, ull mod) {
    ull res = 0;
    a %= mod;
    while(b) {
        if(b & 1){
            res += a;
            res = res >= mod ? res - mod : res;
        };
        b >>= 1;
        a <<= 1;
        a = a >= mod ? a - mod : a;
    }
    return res;
}

lli powerMod(lli a, lli b, lli mod) {
    lli res = 1; 
    while(b) {
        if(b & 1) res = multMod(res, a, mod);
        b >>= 1;
        a = multMod(a, a, mod);
    }
    return res;
}


//22
bool isPrimeMillerRabin(lli n)
{
    if(n < 2) return false;
    if(n <= 3) return true;
    if( ~n & 1) return false;
    lli d = n-1, s = 0; //n-1 = 2^s*k
    for(;(~d&1); d>>=1, s++); //d = k
    for(lli a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if(n == a) return true;
        lli residuo = powerMod(a, d, n);
        if(residuo == 1 or residuo == n-1) continue;
        lli x = s;
        while(--x)
        {
            residuo = multMod(residuo, residuo, n);
            if(residuo == n-1) break;
        }
        if(x==0) return false;
    }
    return true; //Probability = 1 - (1/4)^size_of(vector_a)
}




lli getFactor(lli n) {
    lli a = rand(), b = rand();
    lli x = 2, y = 2, d = 1;

    auto f = [&](auto x){ return (multMod(x, x+a, n) + b) % n; };

    while(d == 1) {
        x = f(x);
        y = f(f(y));
        d = __gcd(abs(x-y), n);
    }

    return d;
}


map<lli,int> factors;
void factorizePollardRho(lli n, lli start = true) {
    if(start) factors.clear();
    
    // You can reduce by trial division [2, 3, 5, 7, ...]

    while(n > 1 && !isPrimeMillerRabin(n)) {
        lli factor = n;
        while(factor == n) factor = getFactor(n);
        n /= factor;
        factorizePollardRho(factor, false);
        for(auto &[p, a]: factors) {
            while(n % p == 0) {
                n /= p;
                a++;
            }
        }
    }
    
    if(n > 1) factors[n]++;
}
