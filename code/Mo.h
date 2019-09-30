//  Basic
bool cmp(const pair<int, int> &p, const pair<int, int> &q) {
    if (p.first / BLOCK_SIZE != q.first / BLOCK_SIZE)
        return p < q;
    return (p.first / BLOCK_SIZE & 1) ? (p.second < q.second) ? (p.second > q.second);
}