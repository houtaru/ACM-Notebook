const int maxn = 1e5 + 10;
vector <int> adj[maxn];

class LowestCommonAncestor {
private:
    int depth[maxn];
    int root[22][maxn];
public:
    void dfs(int u) {
        for (int j = 1; j < 22; ++j) root[u][j] = root[root[u][j - 1]][j - 1];
        for (int v : adj[u]) if (v != root[u][0]) {
            root[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
    
    int lca(int u, int v) {
        for (int i = 20; i >= 0; --i) if (depth[root[u][i]] >= depth[v]) {
            u = root[u][i];
        }
        for (int i = 20; i >= 0; --i) if (depth[root[v][i]] >= depth[u]) {
            v = root[v][i];
        }
        if (u == v) return u;
        for (int i = 20; i >= 0; --i) if (root[u][i] != root[v][i]) {
            u = root[u][i]; v = root[v][i];
        }
        return root[u][0];
    }
};