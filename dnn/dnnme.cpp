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
const int maxn = 1e4 + 5;

struct node {
    string name;
    int NID, w;
    int vis;
    void giv(string N, int T, int O, int V) {
        name = N, NID = T, w = O, vis = V;
    }
};

vector<node> edge[maxn];
map<string, int> id;
map<int, string> nam;
node all_nd[maxn];
set<string> OBS;

void get_input() {
    string str;
    ifstream fin("case2.txt");
    int cnt = 1;
    while (true) {
        getline(fin, str);
        if (str[3] == 't') break;
        string tmp = "", EDG = "";
        int i = 0;
        str += ' ';
        for (; i < sz(str); i++) {
            if (str[i] == ' ') {
                if (EDG == "") {
                    EDG = tmp;
                    i += 3;
                    tmp = "";
                } else {
                    if (id[EDG]) {
                        if (!id[tmp]) id[tmp] = cnt, nam[cnt] = tmp, cnt++;
                        node C;
                        C.giv(tmp, id[tmp], 1, 0);
                        edge[id[EDG]].emplace_back(C);
                    } else {
                        id[EDG] = cnt, nam[cnt] = EDG, cnt++;
                        if (!id[tmp]) id[tmp] = cnt, nam[cnt] = tmp, cnt++;
                        node C;
                        C.giv(tmp, id[tmp], 1, 0);
                        edge[id[EDG]].emplace_back(C);
                    }
                    EDG = tmp = "";
                }
            } else
                tmp += str[i];
        }
    }
    string tmp;
    str += ' ';
    for (int i = 9; i < sz(str); i++) {
        if (str[i] == ' ') {
            OBS.insert(tmp);
            tmp = "";
        } else
            tmp += str[i];
    }
}
vector<vector<string> > all_rout;
vector<string> now_vis;
void gogo(int n) {
    now_vis.emplace_back(nam[n]);
    all_nd[n].vis++;
    if (nam[n] == "T") {
        all_rout.emplace_back(now_vis);
    }
    for (node x : edge[n]) {
        if (all_nd[x.NID].vis != 3 && OBS.count(nam[x.NID]) == 0) {
            gogo(x.NID);
            now_vis.pop_back();
            all_nd[x.NID].vis--;
        }
    }
}

bool cmp(vector<string> &a, vector<string> &b) {
    return sz(a) < sz(b);
}

void get_ans() {
    sort(all(all_rout), cmp);
    for (vector<string> vcc : all_rout) {
        bool KP, KK, sad;
        KP = KK = sad = 0;
        for (string x : vcc) {
            if (x == "P") KP = true;
        }
        for (string x : vcc) {
            if (x == "K")
                KK = true;
            else if (x == "G") {
                if (!KK) sad = true;
            }
        }
        if (!sad && KP) {
            for (string x : vcc) {
                cout << x << ' ';
            }
            cout << endl;
            return;
        }
    }
}

int main() {
    get_input();
    gogo(id["S"]);
    get_ans();
    return 0;
}