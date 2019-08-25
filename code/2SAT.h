// Tested:
// - http://codeforces.com/contest/568/problem/C
// - https://open.kattis.com/contests/nwerc15open/problems/cleaningpipes
const int MN = 200111;   // 2 * no variables.
int n;
vector<int> g[MN], gt[MN];
vector<bool> used;
vector<int> order, comp;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs1 (to);
	}
	order.push_back (v);
}
void dfs2 (int v, int cl) {
    comp[v] = cl;
    for (size_t i=0; i<gt[v].size(); ++i) {
        int to = gt[v][i];
        if (comp[to] == -1)
            dfs2 (to, cl);
	}
}
int main() {
    // n = 2 * (number of boolean variables)
    // NOTE: if we need to fix some variable, e.g. set i = 0 --> addEdge(2*i+1, 2*i)
    // var i --> 2 nodes: 2*i, 2*i+1.

    n = 200000;  // 2 * number of variables.
    used.clear();
    order.clear();
    comp.clear();

    REP(i,n) {
        g[i].clear();
        gt[i].clear();
    }

    // for each condition:
    // u -> v: addEdge(u, v)

    used.assign (n, false);
    REP(i,n) if (!used[i]) dfs1 (i);
    comp.assign (n, -1);
    for (int i=0, j=0; i<n; ++i) {
        int v = order[n-i-1];
        if (comp[v] == -1) dfs2 (v, j++);
    }
    REP(i,n) if (comp[i] == comp[i^1]) {
        puts ("NO SOLUTION"); return 0;
    }
    for (int i=0; i<n; i += 2) {
        int ans = comp[i] > comp[i^1] ? i : i^1; 
        printf ("%d ", ans);
    }
}
