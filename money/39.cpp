#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define in cout<<"in lar"<<endl
const int INF=0x3f3f3f3f;

const int maxn = 10;

struct Node {
    char data;
    int state; // 0: undone; 1: genLeft; 2: genRight
    Node *lc, *rc, *p;
    Node(char data, Node *p) : data(data), state(0), lc(nullptr), rc(nullptr), p(p) {}
    ~Node() {
        delete lc, rc;
    }
};

void solve(string s) {
    Node *root = new Node(s[0], nullptr);
    Node *cur = root;
    int i = 0;
    while (cur) {
        switch (cur->state) {
            case 0:
                cur->lc = new Node(s[++i], cur);
                cur = cur->lc;
                break;
            case 1:
                cur->rc = new Node(s[++i], cur);
                cur = cur->rc;
                break;
            case 2:
                cur = cur->p;
                if (cur) ++cur->state;
                break;
        }
        if (cur && cur->data == '.') {
            cur = cur->p;
            ++cur->state;
        }
    }

    queue <Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *i = q.front(); q.pop();
        if (i->data != '.') cout << i->data;
        if (i->lc) q.push(i->lc);
        if (i->rc) q.push(i->rc);
    }
    cout << endl;

    delete root;
}

int32_t main(){
    // IOS;
    string s;
    cin >> s;
    solve(s);
    return 0;
}