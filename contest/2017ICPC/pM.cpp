#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define int ll
using ll = long long;
using pii = pair<int, int>;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define all(a) (a.begin(), a.end())
#define eb emplace_back
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

const int MAXN = 100;

struct suffix_array {
    int box[MAXN], tp[MAXN], m;
    bool not_equ(int a, int b, int k, int n) {
        return ra[a] != ra[b] || a + k > n || b + k > n ||
               ra[a + k] != ra[b + k];
    }
    void radix(int *key, int *it, int *ot, int n) {
        fill_n(box, m, 0);
        for (int i = 0; i < n; ++i) ++box[key[i]];
        partial_sum(box, box + m, box);
        for (int i = n - 1; i >= 0; --i)
            ot[--box[key[it[i]]]] = it[i];
    }
    void make_sa(string s, int n) {
        int k = 1;
        for (int i = 0; i < n; ++i) ra[i] = s[i];
        do {
            iota(tp, tp + k, n - k), iota(sa + k, sa + n, 0);
            radix(ra + k, sa + k, tp + k, n - k);
            radix(ra, tp, sa, n);
            tp[sa[0]] = 0, m = 1;
            for (int i = 1; i < n; ++i) {
                m += not_equ(sa[i], sa[i - 1], k, n);
                tp[sa[i]] = m - 1;
            }
            copy_n(tp, n, ra);
            k *= 2;
        } while (k < n && m != n);
    }

    void make_he(string s, int n) {
        for (int j = 0, k = 0; j < n; ++j) {
            if (ra[j])
                for (; s[j + k] == s[sa[ra[j] - 1] + k]; ++k)
                    ;
            he[ra[j]] = k, k = max(0ll, k - 1);
        }
    }
    int sa[MAXN], ra[MAXN], he[MAXN];
    void build(string s) {
        FILL(sa, 0), FILL(ra, 0), FILL(he, 0);
        FILL(box, 0), FILL(tp, 0), m = 256;
        make_sa(s, s.size());
        make_he(s, s.size());
    }
};

int32_t main() {
    int n = 5;
    rep(i,2)rep(i1,2)rep(i2,2)rep(i3,2)rep(i4,2)
        printf("%d %d %d %d %d\n",i,i1,i2,i3,i4);
    return 0;
}
/*
0 0 0 0 1 0
0 0 0 1 1 0
0 0 1 0 1 0
0 1 0 0 1 0
0 1 0 1 1 0
0 1 1 0 1 0
1 0 0 0 1 0
1 0 0 1 1 0
1 0 1 0 1 0
1 1 0 0 0 0
1 1 0 0 1 0
1 1 0 1 0 0
1 1 0 1 1 0
1 1 1 0 0 0
1 1 1 0 1 0
1 1 1 1 0 0
1 1 1 1 1 0

check 材料
讀普物
資料結構作業
離散作業(?)+睡著內容
資料結構 後續排序實做
讀危機分二
寫羅設作業
寫英文作業
全球工程作業
讀K-map
軟研內容
*/