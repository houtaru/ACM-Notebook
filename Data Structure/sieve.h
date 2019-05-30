const int maxn = 1e6 + 10;

int f[maxn];
vector <int> prime;

for (int i = 2; i < maxn; ++i) {
    if (!f[i]) {
        f[i] = i;
        prime.push_back(i);
    }
    for (int j = 0; j < (int) prime.size() && i * prime[j] < maxn && prime[j] <= f[i]; ++j)
        f[i * prime[j]] = prime[j];
}