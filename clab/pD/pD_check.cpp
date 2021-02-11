#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, cnt;
int gogo(int n){
    return cnt++, n == 1 ? 0 : gogo((n % 2) ? n * 3 + 1 : n / 2);
}

void get_input() {
    ofstream iout("pD_input.txt");
    n = (rand() % 100 + 1);
    iout << n << endl;
}

void get_answer() {
    ofstream aout("pD_answer.txt");
    cnt = 0;
    gogo(n);
    aout << cnt - 1 << endl;
}

int main() {
    bool flag = 0;
    srand(time(0));
    rep(i, 10) {
        get_input();
        get_answer();
        system("pD.exe < pD_input.txt > pD.txt");
        if (system("fc pD.txt pD_answer.txt")) flag = true;
    }
    if (flag) cout << "Wrong Answer" << endl;
    else cout << "Correct!" << endl;
    system("del pD_input.txt pD_answer.txt pD.txt");
    system("pause");
}