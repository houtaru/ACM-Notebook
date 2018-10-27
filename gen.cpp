/**
 *  Author: houtaruijika
 *  Created: 2018.10.24 22:02:00
 */

#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)

#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(all(v)), v.end())

#define DEBUG(x) cerr << #x << " = " << x << endl;
#define DEBUGS(v, a, b) cerr << #a << " = "; FOR(i, a, b) cerr << a[i] << " "; cerr << endl;

long long Rand(long long l, long long r) { return l + (r - l) * (rand()/(double)RAND_MAX); }

void gen(int iTest) {
    ofstream input("input.in");
    //code goes here

    //
    input.close();
}

void run(int iTest) {
    system("task_name < input.in > output.out");
    system("task_name_trau < input.in > answer.ans");
    if (system("fc output.out answer.ans") != 0) {
        cout << "Test " << iTest << ": is WRONG!!!!\n";
        exit(0);
    }
    cout << "Test " << iTest << ": is CORRECT!\n";
}

int main() {
    srand(time(NULL));
    int nTest = 1;
    for (int i = 0; i < nTest; ++i) {
        gen(i);
        run(i);
    }
    return 0;
}