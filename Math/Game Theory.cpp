struct PeriodicGrundy {
    vector<int> g;      // g[0..preperiod+period-1]
    int preperiod = 0;
    int period = 0;

    int grundy(long long x) const {
        if (x < (long long)g.size()) return g[(size_t)x];
        if (period == 0) { // fallback defensivo (no debería pasar)
            return g.back();
        }
        if (x < preperiod) return g[(size_t)x];
        long long idx = preperiod + ( (x - preperiod) % period );
        return g[(size_t)idx];
    }
};

PeriodicGrundy build_periodic_grundy(vector<int> moves) {
    // Normalizamos movimientos
    sort(moves.begin(), moves.end());
    moves.erase(unique(moves.begin(), moves.end()), moves.end());
    moves.erase(remove(moves.begin(), moves.end(), 0), moves.end());
    if (moves.empty()) {
        // Sin movimientos: sólo g(0)=0 y todo lo demás no jugable -> g(x)=0
        PeriodicGrundy pg;
        pg.g = {0};
        pg.preperiod = 0;
        pg.period = 1;
        return pg;
    }

    // Parámetros de detección (puedes ampliarlos si alguna vez no encuentra período)
    const int BURN   = 5000;   // "calentamiento" (prefijo que ignoramos para detectar)
    const int CHECK  = 5000;   // tamaño de ventana para comprobar repetición
    const int LIM    = BURN + 3*CHECK; // tamaño total a calcular

    vector<int> g(LIM, 0);
    int K = (int)moves.size();

    // Para mex, como a lo sumo hay K valores alcanzables, el mex <= K.
    vector<char> seen(K + 5, 0);

    for (int x = 1; x < LIM; ++x) {
        // marcamos Grundy alcanzables
        for (int m : moves) {
            if (m > x) break;
            int v = g[x - m];
            if (v <= K + 1) seen[v] = 1;
        }
        // mex
        int mex = 0;
        while (mex < (int)seen.size() && seen[mex]) ++mex;
        g[x] = mex;
        // limpiamos "seen" que marcamos
        for (int m : moves) {
            if (m > x) break;
            int v = g[x - m];
            if (v <= K + 1) seen[v] = 0;
        }
    }

    // Detectamos período p en la cola de la secuencia
    int period = 0;
    // Probamos p desde 1 hasta CHECK: exigimos que se repita en las dos últimas ventanas
    for (int p = 1; p <= CHECK; ++p) {
        bool ok = true;
        // ventana 1: [LIM - CHECK, LIM)
        for (int i = LIM - CHECK; i < LIM; ++i) {
            if (g[i] != g[i - p]) { ok = false; break; }
        }
        if (!ok) continue;
        // ventana 2: [LIM - 2*CHECK, LIM - CHECK)
        for (int i = LIM - 2*CHECK; i < LIM - CHECK; ++i) {
            if (g[i] != g[i - p]) { ok = false; break; }
        }
        if (ok) { period = p; break; }
    }

    PeriodicGrundy pg;
    if (period == 0) {
        // Si no encontramos período, guardamos todo (poco probable en práctica)
        // Recomendación: subir LIM/CHECK si pasa con un conjunto extraño de movimientos.
        pg.g = g;
        pg.preperiod = LIM;
        pg.period = 0;
        return pg;
    }

    // Fijamos el preperiodo como el inicio de la segunda ventana de chequeo
    int preperiod = LIM - 2*CHECK;

    // Conservamos sólo [0 .. preperiod + period)
    vector<int> g_compact(preperiod + period);
    for (int i = 0; i < preperiod + period; ++i) g_compact[i] = g[i];

    pg.g = std::move(g_compact);
    pg.preperiod = preperiod;
    pg.period = period;
    return pg;
}

void solve(){
    vi moves = {1,2,3};

    PeriodicGrundy pg = build_periodic_grundy(moves);

    int n; cin >> n;
    int ans = 0;
    FOR(i,0,n){
        int x; cin >> x;
        ans ^= pg.grundy(x);
    }

    if(ans == 0) cout<<"second"<<ENDL;
    else cout<<"first"<<ENDL;

}
