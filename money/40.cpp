#include <bits/stdc++.h>
using namespace std;
struct link {
    link *nxt, *pre;
    int val;
};
link *root = new link{0, 0, 0}, *tmp;

int32_t main() {
    string str, ckt = "";
    root = new link{new link{nullptr, root, 1}, nullptr, 0}, tmp = root->nxt;
    for (int cnt = 0, crt = 0; cin >> str && str != "."; crt = 0, tmp = root->nxt, ckt = "") {
        for (int i = 0; i < str.size(); i++) if (str[i] <= '9' && str[i] >= '0') ckt += str[i];
        for (int cnt = 2; cnt <= stoi(ckt);  tmp = tmp->nxt = ((tmp->nxt) ? tmp->nxt : (crt++,new link{nullptr, tmp, tmp->val + tmp->pre->val})), cnt++) cnt == 2 ?cout << "[0,1,":cnt == stoi(ckt)?cout << tmp->val << "] create " << crt << " nodes" << endl: cout << tmp->val << ',';
    }
    return 0;
}