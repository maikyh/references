//nxt te da la posicion donde iria la letra t[i] desde la posicion en que estas
//pos = nxt[pos][t[i]-'a'];
const int mxN = 1e5 + 10;
int nxt[mxN][26];

void solve(){
  string s,t; cin >> s >> t;
  FOR(i,0,mxN) FOR(j,0,26) nxt[i][j] = 1e9;

  ROF(i,0,sz(s)){
      FOR(j,0,26) nxt[i][j] = nxt[i+1][j];
      nxt[i][s[i]-'a'] = i;
  }
}
