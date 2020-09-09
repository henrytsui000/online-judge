// #pragma GCC target("avx2")
#pragma GCC optimize("O3", "unroll-loops")
 
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define double long double
// template <typename T>
// using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pii = pair<int, int>;
template<typename T>
using prior = std::priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using Prior = std::priority_queue<T>;
 
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()
#define eb emplace_back
#define pb push_back
 
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RANDOM() random_device __rd; \
                 mt19937 __gen = mt19937(__rd()); \
                 uniform_int_distribution<int> __dis(1E5, 1E6); \
                 auto rnd = bind(__dis, __gen)
 
const int INF = 1E9;
const int mod = 1E9 + 7;
const int maxn = 5E5 + 5;
 
int32_t main() {
    fastIO();
    
    int n;
    cin >> n;
    
    deque<int> v(n);
    for (auto &x : v) cin >> x;
    
    int a = 0, b = 0;
    while (v.size() >= 2) {
        if (v[0] >= v[1]) {
            a += v[0], b += v[1];
            v.pop_front(), v.pop_front();
        }
        else {
            a += v[v.size()-1], b += v[0];
            v.pop_back(), v.pop_front();
        }
    }
    
    if (v.size() == 1) a += v[0];
    
    cout << a << " " << b << "\n";
    
    return 0;
}



/*

我是演員，是個天生的coding高手 但是我也喜歡找備胎
我的備胎原則很簡單 他們會是一對我的追求者
然後牽成一個圓 但我的備胎裡面一定要有兩個人 就是東東跟西西
而且他們希望備胎們不要太ㄟ


*/