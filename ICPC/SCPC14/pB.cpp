#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
using pii = pair<int, int>;
template<typename T>
using prior = std::priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using Prior = std::priority_queue<T>;

#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(0)

const int INF = 1E18;
const int mod[2] = {998244353, (int)1E9 + 7};
const int mul[2] = {(int)1E7 + 19, (int)1E8 - 11};

int fastpow(int base, int exp, int modual, int ans = 1) {
    while (exp) {
        if (exp & 1) ans = ans * base % modual;
        base = base * base % modual;
        exp >>= 1;
    }
    return ans;
}

/*
vector<int> HashValue(int n, vector<int> v) {
    int hash[2][2 * n];
    memset(hash, 0x00, sizeof(hash));
    for (int i = 0; i < 2*n-1; ++i) {
        hash[0][i + 1] = (hash[0][i] * mul[0] + v[i % n]) % mod[0];
        hash[1][i + 1] = (hash[1][i] * mul[1] + v[i % n]) % mod[1];
    }
    
    vector<int> ret;
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < n; ++i) {
            int tmpval = hash[t][i] * fastpow(mul[t], n, mod[t]) % mod[t];
            ret.eb((hash[t][i + n] - tmpval + mod[t]) % mod[t]);
        }
    }
    
    return ret;
}
*/

void solve() {
    int n, sum = 0;
    cin >> n;
    
    vector<int> arr[4];
    for (int i = 0; i < 4; ++i) {
        arr[i].resize(n);
        for (int j = 0; j < n; ++j) cin >> arr[i][j], sum += arr[i][j];
    }
    if (sum % n) {cout << "No\n"; return;}
    else sum /= n;
    // cout << "SUM " << sum << "\n";
    
    vector<vector<int>> rot1;
    for (int i = 0; i < n; ++i) {
        vector<int> tmp = arr[0];
        for (int j = 0; j < n; ++j) tmp[j] += arr[1][i + j >= n ? i + j - n : i + j];
        // cout << "INIT "; for (auto x : tmp) cout << x << " "; cout << "\n";
        rot1.eb(tmp);
    }
    
    unordered_map<int, unordered_map<int, int>> hashes;
    int hash[2][2 * n];
    int mult[2] = {fastpow(mul[0], n, mod[0]), fastpow(mul[1], n, mod[1])};
    
    for (int i = 0; i < n; ++i) {
        vector<int> tmp = arr[2];
        for (int j = 0; j < n; ++j) tmp[j] += arr[3][i + j >= n ? i + j - n : i + j];
        
        /// HashValue ///
        
        memset(hash, 0x00, sizeof(hash));
        // for (int j = 0; j < 2*n; ++j) assert(!hash[0][j] and !hash[1][j]);
        for (int j = 0, _j = 0; j < 2*n-1; ++j, ++_j) {
            if (_j == n) _j = 0;
            hash[0][j + 1] = (hash[0][j] * mul[0] + tmp[_j]) % mod[0];
            hash[1][j + 1] = (hash[1][j] * mul[1] + tmp[_j]) % mod[1];
        }
        
        vector<int> ret;
        for (int t = 0; t < 2; ++t) {
            for (int j = 0; j < n; ++j) {
                int tmpval = hash[t][j] * mult[t] % mod[t];
                ret.eb(hash[t][j + n] - tmpval >= mod[t] ?
                       hash[t][j + n] - tmpval - mod[t] :
                       hash[t][j + n] - tmpval);
            }
        }
        
        // vector<int> useless_array = HashValue(n, tmp);
        
        for (int j = 0; j < n; ++j) {
            hashes[ret[j]][ret[j + n]] = 1;
            // cout << "INSERT_HASH (" << ret[j] << ", " << ret[j + n] << ")\n";
            // cout << "  REAL_HASH (" << useless_array[j] << ", " << useless_array[j + n] << ")\n";
        }
    }
    
    for (auto vec : rot1) {
        pii now = {0, 0};
        // cout << "FIND ";
        for (auto &x : vec) {
            x = sum - x;
            // cout << x << " ";
            now.X = (now.X * mul[0] + x) % mod[0];
            now.Y = (now.Y * mul[1] + x) % mod[1];
        }
        // cout << "\n";
        // cout << "FIND_HASH (" << now.X << ", " << now.Y << ")\n";
        if (hashes[now.X][now.Y]) {cout << "Yes\n"; return;}
    }
    
    cout << "No\n";
}

int32_t main() {
    fastIO();
#ifdef local
    freopen("testI.txt", "r", stdin);
    int now_time = clock();
#endif
    
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        solve();
    #ifdef local
        cout << "TIME_PASSED " << clock() - now_time << "\n";
        cout << "AVG_TIME " << (clock() - now_time) / i << "\n";
    #endif
    }
    
    return 0;
}