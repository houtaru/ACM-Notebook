const int maxn = 1e5 + 10;

class DisjoinSetUnion {
private:
    int par[maxn], lab[maxn];
public:
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
            lab[i] = 1;
        }
    }
    int anc(int p) { return par[p] == p ? p : par[p] = anc(par[p]); }
    bool join(int p, int q) {
        if (anc(p) == anc(q)) return 0;
        lab[(anc(q)] += lab[anc(p)];
        par[anc(p)] = anc(q);
        return 1;
    }
};