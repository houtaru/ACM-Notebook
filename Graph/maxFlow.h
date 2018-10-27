#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define INF 1e18
 
using namespace std;
 
typedef long long ll;
const int maxn = 1e6 + 10;
class maxflow {
private:
    int n, m, s, t;
    ll cap[maxn], flow[maxn];
    int q[maxn], d[maxn], adj[maxn], last[maxn], ptr[maxn], next[maxn];
public:
    void init(int n, int s, int t) {
        this->n = n; this->m = m; this->s = s; this->t = t; m = 0;
        fill_n(last, n + 1, -1);
    }
    void add(int u, int v, int w) {
        adj[m] = v; cap[m] = w; flow[m] = 0; next[m] = last[u]; last[u] = m++;
        adj[m] = u; cap[m] = 0; flow[m] = 0; next[m] = last[v]; last[v] = m++;
    }
    bool findPath() {
        fill_n(d, n + 1, -1);
        int head = 0, tail = 0;
        q[tail++] = s; d[s] = 0;
        while (head < tail) {
            int u = q[head++];
            for (int id = last[u]; id != -1; id = next[id]) {
                int v = adj[id];
                if (d[v] == -1 && flow[id] < cap[id]) {
                    d[v] = d[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return d[t] != -1;
    }
    ll dfs(int u, ll flowed) {
        if (!flowed) return 0;
        if (u == t) return flowed;
        for (int &id = ptr[u]; id != -1; id = next[id]) {
            int v = adj[id];
            if (flow[id] < cap[id] && d[v] == d[u] + 1) {
                ll pushed = dfs(v, min(flowed, cap[id] - flow[id]));
                if (pushed) {
                    flow[id] += pushed;
                    flow[id ^ 1] -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    ll run() {
       // cerr << s << " " << t << "\n";
        ll res = 0;
        while (findPath()) {
            FOR(i, 1, n) ptr[i] = last[i];
            while (ll pushed = dfs(s, INF)) {
                res += pushed;
            }
        }
        return res;
    }
} mf;