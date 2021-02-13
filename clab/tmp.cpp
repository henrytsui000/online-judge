#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;

void get_input() {
    ofstream iout("pK_input.txt");
    n = (rand() % 40 + 50);
    iout << n << endl;
}

void get_answer() {
    ofstream aout("pK_answer.txt");
}

int main() {
    bool flag = 0;
    srand(time(0));
    rep(i, 10) {
        get_input();
        get_answer();
        system("pK.exe < pK_input.txt > pK.txt");
        if (system("fc pK.txt pK_answer.txt")) flag = true;
    }
    if (flag) cout << "Wrong Answer" << endl;
    else cout << "Correct!" << endl;
    system("del pK_input.txt pK_answer.txt pK.txt");
    system("pause");
}