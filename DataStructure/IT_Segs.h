/* <3 <3 <3 */
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = a ;i <= b ; ++i)
#define ROF(i,a,b) for (int i = a ;i >= b ; --i)
#define REP(i,a) for (int i = 0 ; i < a ; i++)
#define ll long long
#define ull unsigned long long
#define ii pair <int,int>
#define iii pair <ii,int>
#define fi first
#define se second
#define  pb push_back
#define pu push
#define debug(x) cerr << #x << " : " << x << "\n"

const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const ll oo = 2e18;
const int nmax = 1e5 + 9;

struct line{
    ll sum,mul;
};
struct rec{
    ll s,t,c;
};

int n,k;
rec a[nmax];
ll dp[nmax];
line IT[nmax * 4];

void Inp(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("RELAY.inp","r",stdin);
    freopen("RELAY.out","w",stdout);
    cin >> n >> k;
    FOR(i,1,n)
        cin >> a[i].s >> a[i].t >> a[i].c;
    n += 1;
    a[n].s = k;
    a[n].t = k;
    a[n].c = 0;
}

bool comp(rec a, rec b){
    return a.s < b.s;
}

void Process_BF(){
    sort(a+1, a+n+1, comp);
    FOR(i,1,n){
        dp[i] = oo;
        FOR(j,0,i-1)
            if (a[i].s <= a[j].t)
                dp[i] = min( dp[i], dp[j] + a[j].c * (a[i].s - a[j].s));
    }
    cout << dp[n] ;
}

ll Calc(line val, ll pos){
    return val.sum + val.mul*pos;
}

void Up(int id, int l, int r, int u, int v, line val){
    if (l > v || r < u)
        return;
    int mid = (l+r)/2;
    if (l >= u && r <= v){
        if (Calc(IT[id],a[l].s) <= Calc(val, a[l].s) && Calc(IT[id],a[r].s) <= Calc(val,a[r].s))
            return;
        if (Calc(IT[id],a[l].s) >= Calc(val, a[l].s) && Calc(IT[id],a[r].s) >= Calc(val,a[r].s)){
            IT[id] = val;
            return;
        }
        if (Calc(IT[id],a[l].s) >= Calc(val, a[l].s) && Calc(IT[id],a[mid].s) >= Calc(val,a[mid].s)){
            //cerr << 1 << "\n";
            Up(id*2+1, mid+1, r, u, v, IT[id]);
            IT[id] = val;
            return;
        }
        if (Calc(IT[id],a[l].s) <= Calc(val, a[l].s) && Calc(IT[id],a[mid].s) <= Calc(val,a[mid].s)){
            Up(id*2+1, mid + 1, r, u, v, val);
            return;
        }
        if (Calc(IT[id],a[mid+1].s) >= Calc(val, a[mid+1].s) && Calc(IT[id],a[r].s) >= Calc(val,a[r].s)){
            Up(id*2, l , mid, u, v, IT[id]);
            IT[id] = val;
            return;
        }

        if (Calc(IT[id],a[mid+1].s) <= Calc(val, a[mid+1].s) && Calc(IT[id],a[r].s) <= Calc(val,a[r].s)){
            Up(id*2, l, mid, u, v, val);
            return;
        }

        return ;
    }
    Up(id * 2,l, mid, u, v, val);
    Up(id * 2 + 1, mid + 1, r, u, v, val);
    return ;
}

ll Get(int id, int l, int r, int u){
    ll res = oo ;
    if (l > u || r < u)
        return oo;
    res = min(res, Calc(IT[id], a[u].s));
    if ( l == u && r == u)
        return res;
    int mid = (l+r)/2;
    res = min(res, Get(id*2, l, mid, u));
    res = min(res, Get(id*2+1, mid +1, r, u));
    return res;
}

void Init_IT(){
    FOR(i,1,4*n){
        IT[i].sum = 1e18;
        IT[i].mul = 1e9;
    }
}

int Find(int l, int x){
    int r = n;
    while (l <= r){
        int mid = ( l + r ) / 2;
        if (a[mid].s < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

void Process_FULL(){
    sort(a+1, a+n+1, comp);
    Init_IT();
    FOR(i,1,n){
        if (a[i].s == 0)
            dp[i] = 0;
        else
            dp[i] = Get(1, 1, n, i);
        line val;
        val.sum = dp[i] - a[i].c * a[i].s;
        val.mul = a[i].c;
        //cerr << i << " " << dp[i] << " " << val.sum << " " << val.mul << "\n";
        int l = Find(i+1, a[i].s);
        int r = Find(i+1, a[i].t + 1) - 1;
        //cerr << l << " " << r << "\n";
        if (l > r)
            continue;
        Up(1, 1, n, l, r, val);
    }
    //FOR(i,1,n)
    //    debug(dp[i]);
    cout << dp[n] ;
}
int main(){
    Inp();
    Process_FULL();
    //Process_BF();
    return 0;
}
