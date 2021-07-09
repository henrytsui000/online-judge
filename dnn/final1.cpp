#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
const int maxn = 1e5 + 5;
#define F first
#define S second

map<string, int> mod_siz, mod_dt;
map<string, string> n2g;
vector<string> input, output;
vector<string> all_gate;

void init() {
    mod_siz["INPUT"] = 0, mod_siz["NAND2"] = 2, mod_siz["NAND3"] = 3, mod_siz["NOR2"] = 2;
    mod_siz["NOR3"] = 3, mod_siz["XOR2"] = 2, mod_siz["XNOR2"] = 2, mod_siz["INV"] = 1;
    mod_dt["INPUT"] = 0, mod_dt["NAND2"] = 2, mod_dt["NAND3"] = 3, mod_dt["NOR2"] = 2;
    mod_dt["NOR3"] = 3, mod_dt["XOR2"] = 3, mod_dt["XNOR2"] = 3, mod_dt["INV"] = 1;
}
struct nofn {
    string name, typ;
    int opt, DT;
};

struct node : nofn {
    vector<node*> pre;
    node(string N, string T, int O, vector<node*> P) {
        name = N, typ = T, opt = O, pre = P, DT = 0;
    }
    void cal() {
        rep(i, mod_siz[typ]) if (sz(pre) != 0) {
            pre[i]->DT = max(pre[i]->DT, DT + mod_dt[typ]);
            pre[i]->cal();
        }
        if (typ == "INV") {
            if (pre[0]->opt == 2)
                opt = 2;
            else
                opt = !pre[0]->opt;
        } else if (typ == "NAND2") {
            if ((pre[0]->opt + pre[1]->opt > 2)) {
                opt = 2;
            } else
                opt = !(pre[0]->opt & pre[1]->opt);
        } else if (typ == "NAND3") {
            if (pre[0]->opt == 0 || pre[1]->opt == 0 || pre[2]->opt == 0) {
                opt = 1;
            }else if(max({pre[0]->opt, pre[1]->opt,  pre[2]->opt}) == 1){
                opt = 0;
            }else {
                opt = 2;
            }
        } else if (typ == "NOR2") {
            //    cout << "in nor2 : " << name << ' ' << pre[0]->opt << ' ' << pre[1]->opt << endl;
            if (pre[0]->opt != 1 && pre[1]->opt != 1 && (pre[0]->opt + pre[1]->opt > 0)) {
                opt = 2;
            } else
                opt = !(pre[0]->opt || pre[1]->opt);
        } else if (typ == "NOR3") {
            if (pre[0]->opt == 1 || pre[1]->opt == 1 || pre[2]->opt == 1) {
                opt = 0;
            } else if(max({pre[0]->opt, pre[1]->opt,  pre[2]->opt}) == 0){
                opt = 1;
            }else {
                opt = 2;
            }
        } else if (typ == "XOR2") {
            if (pre[0]->opt == 2 || pre[1]->opt == 2)
                opt = 2;
            else
                opt = (pre[0]->opt ^ pre[1]->opt);
        } else if (typ == "XNOR2") {
            if (pre[0]->opt == 2 || pre[1]->opt == 2)
                opt = 2;
            else
                opt = !(pre[0]->opt ^ pre[1]->opt);
        }
    }
};

map<string, node*> mp;
node* rot;
//NAND2, NAND3, NOR2, NOR3, XOR2, XNOR2, INV

void get_input(char IPT[]) {
    string str, tmp;
    ifstream fin(IPT);
    int itr;
    while (true) {
        getline(fin, str);
        if ((str != "") && (str[0] != str[1] || str[2] != '/'))
            break;
    }

    // output
    while (true) {
        getline(fin, str);
        if ((str != "") && (str[0] != str[1] || str[3] != '/'))
            break;
    }
    itr = 0, str += ' ';
    while (str[itr] == ' ' || str[itr] == '\t') itr++;
    while (str[itr] != ' ') itr++;
    for (int i = itr + 1; i < sz(str); i++) {
        if (str[i] == ' ') {
            if (tmp != "0" && tmp != "1")
                output.emplace_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    // input
    while (true) {
        getline(fin, str);
        if ((str != "") && (str[0] != str[1] || str[0] != '/') && (str[2] != '/'))
            break;
    }
    itr = 0, str += ' ';
    vector<node*> vec;
    while (str[itr] == ' ' || str[itr] == '\t') itr++;
    while (str[itr] != ' ') itr++;
    for (int i = itr + 1; i < sz(str); i++) {
        if (str[i] == ' ') {
            if (tmp != "0" && tmp != "1") {
                n2g[tmp] = tmp;
                mp[tmp] = new node{tmp, "INPUT", 3, vec};
                input.emplace_back(tmp);
            }
            tmp = "";
        } else {
            tmp += str[i];
        }
    }

    // wire don't care
    while (true) {
        getline(fin, str);
        if ((str != "")  && ((str[0] != str[1] || str[0] != '/') && str[2] != '/'))
            break;
    }
    while (true) {
        while (true) {
            getline(fin, str);
            if ((sz(str)>3) && ((str[0] != str[1] || str[0] != '/') && str[2] != '/'))
                break;
        }
        if (str == "endmodule") {
            //    cout << "end!" << endl;
            break;
        }
        tmp = "";
        str += ' ';
        vector<string> ipt;
        rep(i, sz(str)) {
            if (str[i] == ' ') {
                if (tmp != "")
                    ipt.emplace_back(tmp);
                tmp = "";
            } else {
                tmp += str[i];
            }
        }
        n2g[ipt[2]] = ipt[1];
        all_gate.push_back(ipt[1]);
        vector<node*> tkp;
        // cout << mod_siz[ipt[0]] << endl;
        // cout << "build:" << ipt[1] << ": \n";
        rep(i, mod_siz[ipt[0]]) {
            tkp.push_back(mp[n2g[ipt[3 + i]]]);
            // cout << ipt[2 + i] << ' ' << n2g[ipt[3 + i]] << endl;
        }
        node* root = new node{ipt[1], ipt[0], 3, tkp};
        mp[ipt[1]] = root;
        rot = root;
    }
}

void test_build(node* ipt) {
    if (ipt != nullptr) {
        cout << ipt->name << endl;
        rep(i, mod_siz[ipt->typ]) {
            test_build(ipt->pre[i]);
        }
    }
}

int find_max_dt(vector<string>& vec) {
    int mx = 0;
    for (string x : vec)
        mx = max(mx, mp[x]->DT);
    return mx;
}

void get_patterns(char IPT[], char OPT[]) {
    string str, tmp = "";
    ifstream pin(IPT);
    ofstream fout(OPT);
    getline(pin, str);
    vector<string> input_pin;
    int itr = 0;
    while (str[itr] != ' ') itr++;
    str += ' ';
    for (int i = itr + 1; i < sz(str); i++) {
        if (str[i] == ' ') {
            input_pin.emplace_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    while (getline(pin, str)) {
        if (str == "end") {
            //cout << "end files" << endl;
            return;
        }
        itr = 0, str += ' ';
        string pattern_name;
        while (str[itr] != ' ') pattern_name += str[itr], itr++;
        fout << pattern_name << endl;
        int cnt = 0;
        for (int i = itr + 1; i < sz(str); i++) {
            if (str[i] == ' ') {
                mp[input_pin[cnt]]->opt = stoi(tmp);
                //cout << mp[input_pin[cnt]]->opt << ' ';
                cnt++;
                tmp = "";
            } else {
                tmp += str[i];
            }
        }
        // cout << endl;

        //cout << "in gogo" << endl;
        for (string x : output) {
            //cout << n2g[x] << ' ';
            mp[n2g[x]]->cal();
        }
        // cout << endl;
        for (string x : all_gate) {
            fout << mp[x]->name << ' ' << mp[x]->opt << endl;
            mp[x]->opt = 3;
            mp[x]->DT = 0;
        }
        fout << "Delay Time: " << find_max_dt(input) << endl;
    }
}

int main(int argc, char* argv[]) {
    init();
    get_input(argv[1]);
    get_patterns(argv[2], argv[3]);
    return 0;
}
