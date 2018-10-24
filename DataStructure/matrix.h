struct matrix {
    int m, n;
    int a[4][4];
    
    void init(int m, int n) {
        this->m = m; this->n = n;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) a[i][j] = i != j;
    }
    matrix operator * (const matrix &q) {
        matrix e; e.m = this->m; e.n = q.n;
        for (int i = 0; i < e.m; ++i) for (int j = 0; j < e.n; ++j) {
            e.a[i][j] = 0;
            for (int k = 0; k < this->n; ++k) e.a[i][j] = (e.a[i][j] + 1ll * this->a[i][k] * q.a[k][j] % MOD) % MOD;
        }
        return e;
    }
    matrix operator ^ (int k) {
        matrix p = *this;
        matrix e = p; for (int i = 0; i < e.m; ++i) for (int j = 0; j < e.n; ++j) e.a[i][j] = i == j;
        while (k) {
            if (k & 1) e = e * p;
            p = p * p; k >>= 1;
        }
        return e;
    }
};