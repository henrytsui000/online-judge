#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
#define int ll
const int maxn = 1e5 + 5;

bool cmp(int a, int b) { return a > b; }

int32_t main() {
    int a, b, c;
    cin >> a >> b >> c;
    int t;
    cin >> t;
    int cnt = 0;
    vector<int> usb;
    vector<int> ps;
    int ans = 0;
    while (t--) {
        int n;
        string str;
        cin >> n >> str;
        if (str[0] == 'U')
            usb.eb(n);
        else
            ps.eb(n);
    }
    sort(all(ps), cmp);
    sort(all(usb), cmp);

    rep(i, a) {
        if (usb.empty()) break;
        ans += usb.back();
        cnt++;
        usb.pop_back();
    }
    rep(i, b) {
        if (ps.empty()) break;
        ans += ps.back();
        cnt++;
        ps.pop_back();
    }
    for (int x : ps) {
        usb.eb(x);
    }
    sort(all(usb), cmp);
    rep(i, c) {
        if (usb.empty()) break;
        ans += usb.back();
        cnt++;
        usb.pop_back();
    }
    cout << cnt << ' ' << ans << endl;
    return 0;
}


/*

還記得那年夏天，TMD、cold77、崔怪堂踏著開心的步伐到十八間山上看星星
他們買了一個星象盤，深藍色的底子帶白色的星空點綴，當他們拿起來看時，一位對插話十分感與趣的景邁說：

「啊，天鵝座好像天鵝似的。」

「我看倒有點像星座盤發霉。」崔怪堂說。

「真像一隻大烤鴨。」一位外號叫「大食客」的cold77緊接著說。

「欸先別說天鵝座了，你們知道夏季大三角嗎？」TMD又想業配了

「你才大三角啦！全家大三角！」景邁忍不住大聲嚷嚷了起來

大家開始七嘴八舌的討論星座盤上最大三角在哪裡

聰明的你可以幫忙找到二維座標中的最大三角形在哪裡嗎？

tips:
人人的欣賞觀點不盡相同，那是和個人的性格與生活環境有關。
人總會去尋求自己喜歡的事物，每個人的看法或觀點不同，並沒有什麼關係，重要的是你的答案跟正解一樣。
*/