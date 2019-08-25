// Maximum bipartite matching
// Index from 1
// Find max independent set:
// for(i = 1 -> M) if (mat.matchL[i] > 0) {
//   if (mat.dist[i] < inf) {
//     for(j = 1 -> N) if (ke[i][j]) right.erase(j); }
//   else left.erase(i);
// }
// Find vertices that belong to all maximum matching:
// - L = vertices not matched on left side --> BFS from these vertices
//   (left --> right: unmatched edges, right --> left: matched edges)
//   reachable vertices on left side --> not belong to some maximum matching
// - Do similar for right side
// Tested:
// - http://codeforces.com/gym/100216 - J
// - SRM 589 - 450
// - http://codeforces.com/gym/100337 - A
const int inf = 1000111;
struct Matching {
    int n;
    vector<int> matchL, matchR, dist;
    vector<bool> seen;
    vector< vector<int> > ke;

    Matching(int n) : n(n), matchL(n+1), matchR(n+1), dist(n+1), seen(n+1, false), ke(n+1) {}

    void addEdge(int u, int v) {
        ke[u].push_back(v);
    }

    bool bfs() {
        queue<int> qu;
        for(int u = 1; u <= n; ++u)
            if (!matchL[u]) {
                dist[u] = 0;
                qu.push(u);
            } else dist[u] = inf;
        dist[0] = inf;

        while (!qu.empty()) {
            int u = qu.front(); qu.pop();
            for(__typeof(ke[u].begin()) v = ke[u].begin(); v != ke[u].end(); ++v) {
                if (dist[matchR[*v]] == inf) {
                    dist[matchR[*v]] = dist[u] + 1;
                    qu.push(matchR[*v]);
                }
            }
        }
        return dist[0] != inf;
    }

    bool dfs(int u) {
        if (u) {
            for(__typeof(ke[u].begin()) v = ke[u].begin(); v != ke[u].end(); ++v)
                if (dist[matchR[*v]] == dist[u] + 1 && dfs(matchR[*v])) {
                    matchL[u] = *v;
                    matchR[*v] = u;
                    return true;
                }
            dist[u] = inf;
            return false;
        }
        return true;
    }

    int match() {
        int res = 0;
        while (bfs()) {
            for(int u = 1; u <= n; ++u)
                if (!matchL[u])
                    if (dfs(u)) ++res;
        }
        return res;
    }
};




/// Max independent set tracing

#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 2003
int m, n, q;
vector<int> a[N]; //
int Assigned[N], Visited[N]; //
bool Choosed[N]; //

bool visit(int u, int Key){
   if (Visited[u]==Key) return false; Visited[u]=Key;
   for (int i=0; int v=a[u][i]; i++)
   if (!Assigned[v] || visit(Assigned[v], Key))
   { Assigned[u]=v; Assigned[v]=u; return true; }
   return false;
}

void konig(){
   queue<int> qu;

   f1(i,m) if (!Assigned[i]) qu.push(i);
   f1(i,n) if (!Assigned[N-i]) qu.push(N-i);

   while (qu.size()){
      int u=qu.front(); qu.pop();
      for (int i=0; int v=a[u][i]; i++)
      if (!(Choosed[v]++)) qu.push(Assigned[v]);
   }

   f1(i,m) if (Assigned[i] && !Choosed[i] && !Choosed[Assigned[i]]) 
   Choosed[i]=true;
}

main(){
   scanf("%d%d%d", &m, &n, &q);
   if (m+n+q==0) return 0;
   f1(i,q){
      int x, y;
      scanf("%d%d", &x, &y);
      a[x].push_back(N-y);
      a[N-y].push_back(x);
   }
   f1(i,m) a[i].push_back(0);
   f1(i,n) a[N-i].push_back(0);

   static int cnt=0; int Count=0;
   f1(i,m) if (!Assigned[i]) visit(i, ++cnt);
   f1(i,m) if (Assigned[i]) Count++;
   cout << Count;

   konig();
   f1(i,m) if (Choosed[i]) printf(" r%d", i);
   f1(i,n) if (Choosed[N-i]) printf(" c%d", i);
   printf("\n");

   f1(i,m) a[i].clear();
   f1(i,n) a[N-i].clear();
   memset(Assigned, 0, sizeof Assigned);
   memset(Choosed, 0, sizeof Choosed);

   main();
}