/*
x: a[j], y: a[j + (L >> 1)]
or: (x, y + x), (x, y - x)
and: (x + y, y), (x - y, y)
xor: (x + y, x - y), (x + y, x - y)/2
*/
void fwt(val_t *a, int n) { //or
    for (int L = 2; L <= n; L <<= 1) {
        for (int i = 0; i < n; i += L) {
            for (int j = i; j < i + (L >> 1); ++j) {
                a[j + (L >> 1)] += a[j]; //inv: a[j + (L >> 1)] -= a[j];
            }
        }
    }
}
