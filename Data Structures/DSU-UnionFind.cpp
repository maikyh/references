

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
