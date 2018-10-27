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
#define pb push_back
#define pu push

const string name = "";
const int nTest = 100;
const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int oo = 2e9;

ll Rand(ll l , ll r){
    return l+((ll)rand() * (RAND_MAX+1) * (RAND_MAX+1) * (RAND_MAX+1) +
           (ll)rand() * (RAND_MAX+1) * (RAND_MAX+1) +
           (ll)rand() * (RAND_MAX+1) +
           (ll)rand()) % (r-l+1);
}

void Creat_test(){
    ofstream inp((name + ".inp").c_str());
    inp.close();
}

int main(){
    srand(time(NULL));
    double TimeMax = 0;
    double Time1Max = 0;
    FOR(iTest,1,nTest){
        Creat_test();
        double Time = clock();
        system((name+".exe").c_str());
        Time = (clock()-Time)/(double)CLOCKS_PER_SEC;
        TimeMax = max(Time,TimeMax);
        double Time1 = clock();
        system((name+"_BF.exe").c_str());
        Time1 = (clock()-Time1)/(double)CLOCKS_PER_SEC;
        Time1Max = max(Time1,Time1Max);
        printf("Test %d:\n",iTest);
        if (system(("fc " + name + ".out " + name + ".ans").c_str())!=0){
            printf("\x1B[31mWrong Answer\x1B[0m\n");
            break;
        }
        printf("\x1B[32mCorrect Answer\x1B[0m\n");
        printf("\x1B[33mTime: %f\x1B[0m\n",Time);
        printf("\x1B[33mTime1: %f\x1B[0m\n",Time1);
    }
    printf("\n\x1B[33mTimeMax : %f \x1B[0m\n",TimeMax);
    printf("\x1B[33mTime1Max : %f \x1B[0m\n",Time1Max);

    return 0;
}
