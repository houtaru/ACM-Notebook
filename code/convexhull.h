// Complexity: O(nlog(n))

template <class T> 
    struct ConvexHull {
        int head, tail;
        T A[maxn], B[maxn];
 
        ConvexHull(): head(0), tail(0) {}
 
        bool bad(int l1, int l2, int l3) {
            return 1.0 * (B[l3] - B[l1]) / (A[l1] - A[l3]) < 1.0 * (B[l2] - B[l1]) / (A[l1] - A[l2]);
        }
        
        void add(T a, T b) {
            A[tail] = a; B[tail++] = b;
            while (tail > 2 && bad(tail - 3, tail - 2, tail - 1)) {
                A[tail - 2] = A[tail - 1];
                B[tail - 2] = B[tail - 1];
                tail--;
            }
        }
 
        T get(T x) {
            int l = 0, r = tail - 1;
            while (l < r) {
                int m = (l + r) / 2;
                long long f1 = A[m] * x + B[m];
                long long f2 = A[m + 1] * x + B[m + 1];
                if (f1 <= f2) l = m + 1;
                else r = m;
            }
            return A[l] * x + B[l];
        }
    };