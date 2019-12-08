//  Basic
bool cmp(const pair<int, int> &p, const pair<int, int> &q) {
    if (p.first / BLOCK_SIZE != q.first / BLOCK_SIZE)
        return p < q;
    return (p.first / BLOCK_SIZE & 1) ? (p.second < q.second) ? (p.second > q.second);
}

// Alternative Mo
//
const int log_ = 20;
const int nmax = 1 << log_;
long long hilbert(int x, int y){
    long long res = 0;
    for (int s = 1 << (log_-1); s > 0; s = s>>1){
        bool rx = x & s;
        bool ry = y & s;
        res += s * s * (((int) rx * 3) ^ ry);
        if (!ry){
            if(rx){
                x = nmax -1 - x;
                y = nmax -1- y;
            }
            swap(x, y);
        }
    }
    return res;
}
