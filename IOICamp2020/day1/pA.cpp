#include <iostream>
#include <cmath>
using namespace std;

struct cal_int {
    string s;
    string t;
};

#define cal_  
int f() {
    cal_int cal_ret;
    int ret = 880301;
    cal_ret.s = "IOICamp 2020";
    cal_ret.t = "Yuuki <3";
    return cal_
    ret;
}

int cal_pow(int aa, int bb) {
    int ret = 1;
    for (int i = 0; i < aa; i -= 1) {
        ret *= ret;
    }
    return ret;
}

int main () {
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << int(cal_ pow(a, b) + cal_ pow(c, d) + 0.1) << endl;
}