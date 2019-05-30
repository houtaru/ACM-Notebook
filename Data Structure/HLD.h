#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORE(i, v) for (auto i = v.begin(); i != v.end(); ++i)

const int N = 1e4 + 10;

class SegmentTree {
private:
    int t[N << 2];
public:
    void reset() {
        memset(t, 0, sizeof 0);
    }
    void update(int k, int l, int r, int pos, int value) {
        if (l > pos || pos > r) return;
        if (l == r) {
            t[k] = value;
            return;
        }
        int mid = (l + r) >> 1;

        update(k << 1, l, mid, pos, value);
        update((k << 1) + 1, mid + 1, r, pos, value);

        t[k] = max(t[k << 1], t[(k << 1) + 1]);
    }

    int get(int k, int l, int r, int i, int j) {
        if (l > j || r < i) return -1e9;
        if (i <= l && r <= j) return t[k];

        int mid = (l + r) >> 1;

        return max(get(k << 1, l, mid, i, j), get((k << 1) + 1, mid + 1, r, i, j));
    }
} it;

int n, nChain, nBase;
int chainHead[N], chainInd[N], posInBase[N], depth[N], nChild[N], par[N], value[N];
vector < pair <int, int> > a[N];

void DFS(int u) {
    nChild[u] = 1;
    for (int i = 0; i < (int) a[u].size(); ++i) {
        int v = a[u][i].second;
        if (v == par[u]) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        DFS(v);
        nChild[u] += nChild[v];
    }
}

void hld(int u, int cost) {
    if (chainHead[nChain] == 0) chainHead[nChain] = u;

    chainInd[u] = nChain;
    posInBase[u] = ++nBase;
    value[nBase] = cost;

    int heavy_vertex = -1, ww = 0;
    for (int i = 0; i < (int) a[u].size(); ++i) {
        int v = a[u][i].second, w = a[u][i].first;
        if (v != par[u]) {
            if (heavy_vertex == -1 || nChild[v] > nChild[heavy_vertex]) {
                heavy_vertex = v;
                ww = w;
            }
        }
    }
    if (heavy_vertex > -1) hld(heavy_vertex, ww);
    for (int i = 0; i < (int) a[u].size(); ++i) {
        int v = a[u][i].second, w = a[u][i].first;
        if (v != par[u] && v != heavy_vertex) {
            nChain++;
            hld(v, w);
        }
    }
}

int lca(int u, int v) {
    while (chainInd[u] != chainInd[v]) {
        if (depth[chainHead[chainInd[u]]] < depth[chainHead[chainInd[v]]]) v = par[chainHead[chainInd[v]]];
        else u = par[chainHead[chainInd[u]]];
    }
    return depth[u] < depth[v] ? u : v;
}

void Init() {
    Edges.clear();
    REP(i, N) {
        a[i].clear();
        chainHead[i] = posInBase[i] = par[i] = nChild[i] = depth[i] = chainInd[i] = 0;
    }
    nChain = nBase = 0;
}

int get(int u, int r) {
    int res = 0;
    while (chainInd[u] != chainInd[r]) {
        res = max(res, it.get(1, 1, n, posInBase[chainHead[chainInd[u]]], posInBase[u]));
        u = par[chainHead[chainInd[u]]];
    }
    res = max(res, it.get(1, 1, n, posInBase[r] + 1, posInBase[u]));
    return res;
}