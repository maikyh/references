/10
int lowestBit(int n){ return n&(-n); }
int isOn(int s, int j){  return s & (1 << j); }
int clearBit(int s, int j){ return s & ~(1 << j);  }
int setBit(int s, int j){  return s | (1 << j); }
int toggleBit(int s, int j){  return s ^ (1 << j); }
int isPowerofTwo(int s){ return s & (s-1);   }
int turnOffLastBit(int s){ return s & (s-1);  }
//__builtin_popcount(n) counting the number of 1's
//__builtin_popcountll(n) counting the number of 1's

//13
int getSetBitsFromOneToN(int N)
{ 
    int two = 2,ans = 0; 
    int n = N; 
    while(n){ 
        ans += (N/two)*(two>>1); 
        if((N&(two-1)) > (two>>1)-1) ans += (N&(two-1)) - (two>>1)+1; 
        two <<= 1; 
        n >>= 1; 
    } 
    return ans; 
} 
//check si bit esta prendido en posicion k
for(int k = 31;k>=0;k--){
        if(n & (1<<k)){
            cout << "1";
        }else{
            cout << "0";
        }
}
//x | (1 << k) set bit en posicion k en 1 de x
//x & ~(1 << k) set bit en posicion k en 0 de x
//x ^ (1<<k) invierte kth bit de x
//x & (x-1) set last one bit of x to zero
//x | (x-1) inverts all the bits after the last one bit
//x & (x-1) =0 check if x is power of two
//__builtin_clz(x): the number of zeros at the beginning of the bit representation
//__builtin_ctz(x): the number of zeros at the end of the bit representation
//__builtin_popcount(x): the number of ones in the bit representation
//__builtin_parity(x): check parity of the number of ones in the bit representation
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void setBitsInArray(ll n, vector<int> &bits) {
    int position = 1;
    while (n > 0) {
        if (n & 1) {
            bits[position]++; // Increment the corresponding bit position in the array
        }
        position++;
        n >>= 1; // Right shift the number to check the next bit
    }
}
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
 
        // Multiply 'a' with 2
        a = (a * 2) % mod;
 
        // Divide b by 2
        b /= 2;
    }
 
    // Return result
    return res % mod;
}

//15
long computeXOR(int n)
{
    switch( n & 3) // n % 4
    {
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        case 3: return 0;
    }
}
long computeXORFromAToB(int a, int b)
{
    return computeXOR(a) ^ computeXOR(b);
}
