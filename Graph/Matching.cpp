#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <set>
#include <stack>
#include <queue>

#define FOR(i,x,y) for( int i = x ; i <= y ; i ++ )
#define ROF(i,x,y) for( int i = x ; i >= y ; i -- )
#define REP(i,x)   for( int i = 0 ; i < x  ; i ++ )
#define ll long long
#define ii pair <int, int>
#define iii pair <ii, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int oo = 2e9;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
const int nmax = 5e4 + 9 ;

vector <int> v[nmax];
int matchX[nmax], matchY[nmax], Trace[nmax];
int n,m,c;

void Inp(){

    //freopen("Match.inp","r",stdin);
    //freopen("Match.out","w",stdout);
    scanf("%d%d%d",&n,&m,&c);
    while (c--){
        int x,y;
        scanf("%d%d",&x,&y);
        if (matchX[x] == 0 && matchY[y] == 0)
            matchX[x] = y, matchY[y] = x;
        v[x].pb(y);
    }
    return ;
}

void Update(int u){
    while (u){
        matchY[u] = Trace[u];
        int nex = matchX[Trace[u]];
        matchX[Trace[u]] = u;
        u = nex;
    }
}

bool Find_Path(){
    queue <int> q;
    FOR(i,1,m)
        Trace[i] = 0 ;
    FOR(i,1,n)
        if (matchX[i] == 0)
            q.push(i);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        REP(i,v[u].size()){
            int e = v[u][i];
            if (Trace[e])
                continue;
            Trace[e] = u;
            if (matchY[e] == 0){
                Update(e);
                return 1;
            }
            else
                q.push(matchY[e]);
        }
    }
    return 0;
}
void Process(){
    while (Find_Path()){
    }
    int ans = 0;
    FOR(i,1,n)
        ans += matchX[i] != 0;
    printf("%d",ans);
}

int main(){
    Inp();
    Process();
}
