#define REP(i, n) for (int i = 0; i < n; ++i)

struct matrix {
    int m, n;
    long long a[2][2];
 
    void init(int m, int n) {
        this->m = m; this->n = n;
        REP(i, m) REP(j, n) a[i][j] = i == j;
    }
    matrix operator * (const matrix &q) {
        matrix e; e.init(this->m, q.n);
        REP(i, e.m) REP(j, e.n) {
            e.a[i][j] = 0;
            REP(k, this->n) {
                e.a[i][j] += this->a[i][k] * q.a[k][j] % MOD;
                e.a[i][j] %= MOD;
            }
        }
        return e;
    }
    matrix operator ^ (long long k) {
        matrix e, p = *this; e.init(m, n);
        for (; k; k >>= 1, p = p * p) if (k & 1) e = e * p;
        return e;
    }
};