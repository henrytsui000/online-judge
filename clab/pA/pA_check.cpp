#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;

void get_input() {
}

void get_answer() {
    ofstream aout("pA_answer.txt");
    aout << "Hello world!" << endl;
}

int main() {
    bool flag = 0;
    rep(i, 10) {
        get_input();
        get_answer();
        system("pA.exe > pA.txt");
        if (system("fc pA.txt pA_answer.txt")) flag = true;
    }
    if (flag) cout << "Wrong Answer" << endl;
    else cout << "Correct!" << endl;
    system("del pA_input.txt pA_answer.txt pA.txt");
    system("pause");
}