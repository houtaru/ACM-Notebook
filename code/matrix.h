template <class T, T MOD>
struct matrix {
    int m, n;
    vector < vector <T> > a;

    matrix (int m = 0, int n = 0) {
        this->m = m; this->n = n;
        this->a.resize(m);
        REP(i, m) {
            this->a[i].resize(n);
            REP(j, n) this->a[i][j] = i == j;
        }
    }
    matrix (const vector < vector <T> > &p) {
        this->a = p;
        this->m = sz(p);
        this->n = p.empty() ? 0 : sz(p[0]);
    }
    matrix operator * (const matrix &p) {
        matrix e(this->m, p.n);
        REP(i, e.m) REP(j, e.n) {
            e.a[i][j] = 0;
            REP(k, this->n) 
                e.a[i][j] = (e.a[i][j] + (1ll * this->a[i][k] * p.a[k][j]) % MOD) % MOD;
        }
        return e;
    }
    matrix operator ^ (long long k) {
        matrix e(this->m, this->n);
        matrix p = *this;
        for (; k; k >>= 1, p = p * p) if (k & 1)
            e = e * p;
        return e;
    }
};
