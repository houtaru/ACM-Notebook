#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1e18

const int maxn = 2e4 + 10;

struct minCostFlow {
	int n, m, s, t;
	ll totalCost, totalFlow;
	ll cap[maxn], flow[maxn], cost[maxn], best[maxn];
	int adj[maxn], next[maxn], last[maxn], pre[maxn];
	bool inque[maxn];
	
	void init(int n, int s, int t) {
		this->n = n; this->s = s; this->t = t;
		fill_n(last, n + 10, -1);
	}
	void add(int u, int v, int ca, int co) {
		adj[m] = v; cap[m] = ca; flow[m] = 0; cost[m] = co; next[m] = last[u]; last[u] = m++;
		adj[m] = u; cap[m] = 0; flow[m] = 0; cost[m] = -co; next[m] = last[v]; last[v] = m++;
	}
	bool findPath() { 
		fill_n(best, n + 10, INF);	best[s] = 0;
		fill_n(inque, n + 10, 0); 	inque[s] = 1;
		queue <int> q; q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int id = last[u]; id != -1; id = next[id]) {
				int v = adj[id];
				if (flow[id] < cap[id] && best[v] > best[u] + cost[id]) {
					best[v] = best[u] + cost[id]; pre[v] = id;
					if (!inque[v]) {
						q.push(v);
					}
				}
			}
			inque[s] = 0;
		}
		return best[t] < INF;
	}
	ll run() {
		totalCost = 0; totalFlow = 0;
		while (findPath()) {
			ll mn = INF;
			for (int v = t, id = pre[v]; v != s; v = adj[id ^ 1], id = pre[v]) mn = min(mn, cap[id] - flow[id]);
			for (int v = t, id = pre[v]; v != s; v = adj[id ^ 1], id = pre[v]) {
				flow[id] += mn; flow[id ^ 1] -= mn;
			}
			totalFlow += mn;
			totalCost += mn * best[t];
		}
		return totalCost;
	}
} mc;