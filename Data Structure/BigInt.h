#include <iostream>
#include <vector>

using namespace std;

namespace bignum {
    const int BASE = 10000;
    typedef vector <int> vi;
    
    void fix(vi &a) {
        a.push_back(0);
        for (int i = 0; i < (int) a.size() - 1; ++i) {
            a[i + 1] += a[i] / BASE; a[i] %= BASE;
            if (a[i] < 0) {
                a[i] += BASE;
                a[i + 1]--;
            }
        }
        while ((int) a.size() > 1 && !a.back()) a.pop_back();
    }

    void operator += (vi &a, const vi &b) {
        a.resize(max(a.size(), b.size()));
        for (int i = 0; i < b.size(); ++i) a[i] += b[i];
        fix(a);
    }
    void operator -= (vi &a, const vi &b) {
        for (int i = 0; i < (int) b.size(); ++i) a[i] -= b[i];
        fix(a);
    }
    void operator *= (vi &a, const int &x) {
        for (int i = 0; i < a.size(); ++i) a[i] *= x;
        fix(a);
    }
    vi operator + (vi a, const vi &b) {
        a += b; return a;
    }
    vi operator - (vi a, const vi &b) {
        a -= b; return a;
    }
    vi operator * (const vi &a, const vi &b) {
        vi c(a.size() + b.size());
        for (int i = 0; i < a.size(); ++i) for (int j = 0; j < (int) b.size(); ++j) c[i + j] += a[i] * a[j];
        return fix(c), c;
    }
    vi operator * (vi a, const int &x) {
        a *= x; return a;
    }
    bool operator < (const vi &a, const vi &b) {
        if (a.size() != b.size()) return a.size() < b.size();
        for (int i = 0; i < a.size(); ++i) if (a[i] != b[i])
            return a[i] < b[i];
        return 0;
    }
    bool operator <= (const vi &a, const vi &b) {
        if (a.size() != b.size()) return a.size() < b.size();
        for (int i = 0; i < a.size(); ++i) if (a[i] != b[i])
            return a[i] < b[i];
        return 1;
    }
    istream& operator >> (istream& cin, vi &a) {
        string s; cin >> s;
        a.clear(); a.resize(s.size() / 4 + 1);
        for (int i = 0; i < s.size(); ++i) {
            int x = (s.size() - i - 1) / 4;
            a[x] = a[x] * 10 + s[i] - '0';
        }
        return fix(a), cin;
    }
    ostream& operator << (ostream& cout, const vi &a) {
        printf("%d", a.back());
        for (int i = a.size() - 2; i >= 0; --i) printf("%04d", a[i]);
        return cout;
    }
    vi to_vi(long long x) { vi a(1, x);     fix(a);     return a; }
};

