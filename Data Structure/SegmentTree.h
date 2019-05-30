class SegmentTree {
private:
    int t[maxn << 2];
public:
    void reset() {
        memset(t, 0, sizeof 0);
    }
    void update(int k, int l, int r, int pos, int value) {
        if (l > pos || pos > r) return;
        if (l == r) {
            t[k] = value;
            return;
        }
        int mid = (l + r) >> 1;

        update(k << 1, l, mid, pos, value);
        update((k << 1) + 1, mid + 1, r, pos, value);

        t[k] = max(t[k << 1], t[(k << 1) + 1]);
    }

    int get(int k, int l, int r, int i, int j) {
        if (l > j || r < i) return -1e9;
        if (i <= l && r <= j) return t[k];

        int mid = (l + r) >> 1;

        return max(get(k << 1, l, mid, i, j), get((k << 1) + 1, mid + 1, r, i, j));
    }
}